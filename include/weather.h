#ifndef WEATHER_H
#define WEATHER_H

/**
 * 城市天气类 作者:feiyangqingyun(QQ:517216493) 2021-09-25
 * 1. 指定任意城市获取天气信息。
 * 2. 天气信息包括日期、低温、高温、天气、风力、风向。
 * 3. 查询结果立即返回，包括接收到的数据。
 * 4. 支持获取对应天气的图标值。
 * 5. 自带演示demo省市县下拉联动选择。
 * 6. 同时支持QtScript和QJson解析。
 * 7. 支持指定标签直接显示当前天气。
 * 8. 支持实时采集指定城市天气显示到标签。
 * 9. 天气显示样式支持多种类型风格。
 * 10. 可直接获取天气图形字体。
 */

#include <QObject>
#include <QFont>
#include <QLabel>
#include <QStringList>
#include <QDebug>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#include "qjsonarray.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qjsonvalue.h"
#else
#include "qscriptengine.h"
#include "qscriptvalue.h"
#include "qscriptvalueiterator.h"
#endif

class QNetworkAccessManager;
class QNetworkReply;

struct WeatherInfo {
    QString date;       //日期
    QString low;        //低温
    QString high;       //高温
    QString type;       //天气
    QString fengli;     //风力
    QString fengxiang;  //风向

    //重载打印输出格式
    friend QDebug operator << (QDebug debug, const WeatherInfo &weatherInfo) {
        QStringList list;
        list << QString("日期: %1").arg(weatherInfo.date);
        list << QString("低温: %1").arg(weatherInfo.low);
        list << QString("高温: %1").arg(weatherInfo.high);
        list << QString("天气: %1").arg(weatherInfo.type);
        list << QString("风力: %1").arg(weatherInfo.fengli);
        list << QString("风向: %1").arg(weatherInfo.fengxiang);

#if (QT_VERSION >= QT_VERSION_CHECK(5,4,0))
        debug.noquote() << list.join("\n");
#else
        debug << list.join("\n");
#endif
        return debug;
    }
};

#ifdef quc
class Q_DECL_EXPORT Weather : public QObject
#else
class Weather : public QObject
#endif

{
    Q_OBJECT
public:
    static QFont getIconFont();
    static int getWeatherIcon(const QString &type);
    explicit Weather(QObject *parent = 0);

private:
    QNetworkAccessManager *manager;
    QString city;
    QLabel *label;
    quint8 style;
    QTimer *timer;

private:
    QString replace1(QString text);
    QString replace2(QString text);

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
    void getData(QJsonObject objData, QString &city, QString &ganmao, QString &wendu);
    void getData(QJsonObject object, WeatherInfo &weatherInfo, bool yesterday);
#else
    void getData(QScriptValue objData, QString &city, QString &ganmao, QString &wendu);
    void getData(QScriptValue object, WeatherInfo &weatherInfo, bool yesterday);
#endif

private slots:
    void finished(QNetworkReply *reply);
    void doWeather(const QString &city, const QString &wendu, const QString &ganmao, const QList<WeatherInfo> &weatherInfos);

public:
    //设置城市名称
    void setCity(const QString &city);
    //设置显示天气的标签及样式
    void setLabel(QLabel *label, quint8 style);

    //联网自动定位当前城市
    QString getLocation();

public Q_SLOTS:
    //指定城市查询天气 cityName=上海
    void query(const QString &city);
    void query();

    //启动和停止定时器轮询天气,间隔单位秒
    void start(int interval);
    void stop();

Q_SIGNALS:
    //打印信息信号
    void debug(const QString &msg);
    //失败错误信号
    void error(const QString &msg);
    //返回天气信息集合
    void receiveWeather(const QString &city, const QString &wendu, const QString &ganmao, const QList<WeatherInfo> &weatherInfos);
};

#endif // WEATHER_H
