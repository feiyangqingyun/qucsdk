#ifndef PINYIN_H
#define PINYIN_H

/**
 * 简体转繁体+汉字转拼音带音标类 作者:feiyangqingyun(QQ:517216493) 2019-02-16
 * 1. 简体繁体互相转换。
 * 2. 汉字转拼音带音标。
 */

#include <QObject>
#include <QStringList>
#include <QMap>

#ifdef quc
class Q_DECL_EXPORT PinYin : public QObject
#else
class PinYin : public QObject
#endif

{
    Q_OBJECT
public:
    enum Format {
        Format_None = 0,
        Format_Tone = 1,
        Format_Number = 2
    };

    static PinYin *Instance();
    explicit PinYin(QObject *parent = 0);

private:
    static QScopedPointer<PinYin> self;

    //分别存储单个汉字的拼音,多音字的拼音,繁体与简体对照表
    QMap<QString, QString> map_one, map_group, map_fanti;

    //从文本文件读取汉字与拼音对照表
    QMap<QString, QString> getDict(const QString &fileName);

public slots:
    //初始化
    void initPath(const QString &path);
    void initDict(const QString &pinyin_one = "pinyin_one.txt",
                  const QString &pinyin_group = "pinyin_group.txt",
                  const QString &pinyin_fanti = "pinyin_fanti.txt");

    //简体转繁体
    QChar getFanTi(const QChar &letter);
    QString getFanTi(const QString &str);

    //繁体转简体
    QChar getJianTi(const QChar &letter);
    QString getJianTi(const QString &str);

    //判断字符是否是汉字
    bool isChinese(const QChar &letter);

    //格式化拼音显示
    QStringList formatPinyin(const QString &str, const Format &format);

    //将单个汉字转换为相应格式的拼音
    QStringList getPinYin(const QChar &letter, const Format &format);

    //将字符串转换成相应格式的拼音
    QString getPinYin(const QString &str, const QString &separator, const Format &format);

};

#endif // PINYIN_H
