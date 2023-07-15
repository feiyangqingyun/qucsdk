#ifndef MAGICMOUSE_H
#define MAGICMOUSE_H

/**
 * 魔幻老鼠控件 作者:feiyangqingyun(QQ:517216493) 2018-07-15
 * 本控件来源于qtdemo
 * 1. 可设置身体、眼睛、眼珠、鼻子、尾巴的颜色。
 * 2. 可设置停留位置旋转角度。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT MagicMouse : public QWidget
#else
class MagicMouse : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int angle READ getAngle WRITE setAngle)
    Q_PROPERTY(QColor bodyColor READ getBodyColor WRITE setBodyColor)
    Q_PROPERTY(QColor eyeColor READ getEyeColor WRITE setEyeColor)
    Q_PROPERTY(QColor eyeballColor READ getEyeballColor WRITE setEyeballColor)
    Q_PROPERTY(QColor noseColor READ getNoseColor WRITE setNoseColor)
    Q_PROPERTY(QColor earColor READ getEarColor WRITE setEarColor)
    Q_PROPERTY(QColor tailColor READ getTailColor WRITE setTailColor)

public:
    explicit MagicMouse(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    int angle;                  //旋转角度
    QColor bodyColor;           //身体颜色
    QColor eyeColor;            //眼睛颜色
    QColor eyeballColor;        //眼珠颜色
    QColor noseColor;           //鼻子颜色
    QColor earColor;            //耳朵颜色
    QColor tailColor;           //尾巴颜色

public:
    int getAngle()              const;
    QColor getBodyColor()       const;
    QColor getEyeColor()        const;
    QColor getEyeballColor()    const;
    QColor getNoseColor()       const;
    QColor getEarColor()        const;
    QColor getTailColor()       const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置旋转角度
    void setAngle(int angle);
    //设置身体颜色
    void setBodyColor(const QColor &bodyColor);
    //设置眼睛颜色
    void setEyeColor(const QColor &eyeColor);
    //设置眼珠颜色
    void setEyeballColor(const QColor &eyeballColor);
    //设置鼻子颜色
    void setNoseColor(const QColor &noseColor);
    //设置耳朵颜色
    void setEarColor(const QColor &earColor);
    //设置尾巴颜色
    void setTailColor(const QColor &tailColor);
};

#endif // MAGICMOUSE_H
