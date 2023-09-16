#ifndef ROUNDTEXT_H
#define ROUNDTEXT_H

/**
 * 弧形旋转文字 作者:雨田哥(QQ:3246214072) 整理:feiyangqingyun(QQ:517216493) 2023-8-28
 * 1. 可设置弧形文字。
 * 2. 自定义圆弧大小。
 * 3. 自定义文字起始角度。
 * 4. 可设置顺时针/逆时针滚动。
 * 5. 可设置文字颜色和大小。
 * 6. 可设置旋转间隔用于控制旋转速度。
 */

#include <QWidget>
class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT RoundText : public QWidget
#else
class RoundText : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QString text READ getText WRITE setText)
    Q_PROPERTY(int textSize READ getTextSize WRITE setTextSize)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(int animationDuration READ getAnimationDuration WRITE setAnimationDuration)

    Q_PROPERTY(bool clockWise READ getClockWise WRITE setClockWise)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)

public:
    explicit RoundText(QWidget *parent = 0);

protected:
    void updatePixmap();
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QString text;           //文字内容
    int textSize;           //文字大小
    QColor textColor;		//文字颜色

    bool animation;			//启用旋转动画
    int animationDuration;	//旋转动画间隔

    bool clockWise;         //是否顺时针
    int startAngle;         //起始角度

    int rotate;             //旋转角度
    QPixmap pixmap;			//弧形图像
    QPropertyAnimation *animationProperty;

private slots:
    void initAnimation();
    void valueChanged(const QVariant &value);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置文字内容
    QString getText() const;
    void setText(const QString &text);

    //获取和设置文字大小
    int getTextSize() const;
    void setTextSize(int ponitsize);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置启动旋转
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画间隔
    int getAnimationDuration()  const;
    void setAnimationDuration(int animationDuration);

    //获取和设置顺时针
    bool getClockWise() const;
    void setClockWise(bool clockWise);

    //获取和设置起始角度
    int getStartAngle() const;
    void setStartAngle(int startAngle);
};

#endif // ROUNDTEXT_H
