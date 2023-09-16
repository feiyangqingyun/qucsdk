#ifndef VERIFIEDCODE_H
#define VERIFIEDCODE_H

/**
 * 验证码控件 作者:feiyangqingyun(QQ:517216493) 2016-12-25
 * 1. 可设置字符长度。
 * 2. 可设置噪点数量。
 * 3. 可设置干扰线条数量。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT VerifiedCode : public QWidget
#else
class VerifiedCode : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int codeLen READ getCodeLen WRITE setCodeLen)
    Q_PROPERTY(int noiseCount READ getNoiseCount WRITE setNoiseCount)
    Q_PROPERTY(int lineCount READ getLineCount WRITE setLineCount)

public:
    explicit VerifiedCode(QWidget *parent = 0);
    ~VerifiedCode();

protected:
    void paintEvent(QPaintEvent *);
    void drawRoise(QPainter *painter);
    void drawLine(QPainter *painter);
    void drawCode(QPainter *painter);

private:
    int codeLen;                //验证码长度
    int noiseCount;             //噪点数量
    int lineCount;              //干扰线数量

    QString code;               //当前验证码
    QStringList listCode;       //验证码池列表
    QStringList colorList;      //颜色集合

private:
    void updateCode();          //更新验证码

public:
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //载入验证码
    void loadCode();
    //获取验证码
    QString getCode() const;

    //获取和设置验证码长度
    int getCodeLen() const;
    void setCodeLen(int codeLen);

    //获取和设置干扰噪点数量
    int getNoiseCount() const;
    void setNoiseCount(int noiseCount);

    //获取和设置干扰线条数量
    int getLineCount() const;
    void setLineCount(int lineCount);
};

#endif // VERIFIEDCODE_H
