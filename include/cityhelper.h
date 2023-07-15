#ifndef CITYHELPER_H
#define CITYHELPER_H

/**
 * 省市县联动 作者:feiyangqingyun(QQ:517216493) 2017-11-06
 * 1. 获取所有省份名称集合。
 * 2. 获取指定省份下的所有市区名称集合。
 * 3. 获取指定省份及市区下的所有区县集合。
 */

#include <QObject>

#ifdef quc
class Q_DECL_EXPORT CityHelper
#else
class CityHelper
#endif

{
public:
    //去除字符
    static QString getValue(const QString &value);
    //读取文件返回数据
    static QByteArray getFile(const QString &jsonFile);
    //根据不同的类型查询对应的结果
    //type 0-获取所有省份 1-获取省份下的所有市区 2-获取市区下的县城
    static QStringList getResult(const QByteArray &data, quint8 type, const QString &provinceName, const QString &cityName);
    //获取所有省份
    static QStringList getProvince(const QString &jsonFile);
    //获取省份下的所有市区
    static QStringList getCity(const QString &jsonFile, const QString &provinceName);
    //获取省份下的市区的所有县城
    static QStringList getCounty(const QString &jsonFile, const QString &provinceName, const QString &cityName);
};

#endif // CITYHELPER_H
