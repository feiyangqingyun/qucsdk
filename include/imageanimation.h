#ifndef IMAGEANIMATION_H
#define IMAGEANIMATION_H

/**
 * 图片切换动画控件 作者:赵彦博(QQ:408815041 zyb920@hotmail.com) 2019-06-10
 * 1. 可设置动画类型，默认9种，后期会增加更多。
 * 2. 渐变显示。
 * 3. 百叶窗。
 * 4. 从右向左翻转。
 * 5. 从外到内水平分割。
 * 6. 从左到右。
 * 7. 从右到左。
 * 8. 从下到上。
 * 9. 从上到下。
 * 10. 从右下到左上。
 * 11. 可设置两张图片的路径名称或者图片。
 * 12. 可设置动画因子。
 */

#include <QWidget>

class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT ImageAnimation : public QWidget
#else
class ImageAnimation : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(AnimationType)

    Q_PROPERTY(float factor READ getFactor WRITE setFactor)
    Q_PROPERTY(QString imageName1 READ getImageName1 WRITE setImageName1)
    Q_PROPERTY(QString imageName2 READ getImageName2 WRITE setImageName2)
    Q_PROPERTY(QPixmap pixmap1 READ getPixmap1 WRITE setPixmap1)
    Q_PROPERTY(QPixmap pixmap2 READ getPixmap2 WRITE setPixmap2)
    Q_PROPERTY(AnimationType animationType READ getAnimationType WRITE setAnimationType)

public:
    enum AnimationType {
        FadeEffect = 0,             //渐变渐显
        BlindsEffect = 1,           //百叶窗
        FlipRightToLeft = 2,        //从右向左翻转
        OutsideToInside = 3,        //从外到内水平分割
        MoveLeftToRightEffect = 4,  //从左到右转动
        MoveRightToLeftEffect = 5,  //从右到左转动
        MoveBottomToUpEffect = 6,   //从下到上转动
        MoveUpToBottomEffect = 7,   //从上到下转动
        MoveBottomToLeftUpEffect = 8//从右下到左上飞入
    };

    explicit ImageAnimation(QWidget *parent = 0);
    ~ImageAnimation();

protected:
    void paintEvent(QPaintEvent *);
    void fadeEffect(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void blindsEffect(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void flipRightToLeft(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void outsideToInside(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void moveLeftToRightEffect(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void moveRightToLeftEffect(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void moveBottomToUpEffect(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void moveUpToBottomEffect(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);
    void moveBottomToLeftUpEffect(QPainter *painter, const QRect &rect, float factor, const QPixmap &pixmap1, const QPixmap &pixmap2);

private:
    float factor;           //动画因子(0 - 1.0之间变化)
    QString imageName1;     //图片1路径名称
    QString imageName2;     //图片2路径名称
    QPixmap pixmap1;        //图片1
    QPixmap pixmap2;        //图片2

    //动画效果类型和动画对象
    AnimationType animationType;
    QPropertyAnimation *animation;

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置动画因子
    float getFactor() const;
    void setFactor(float factor);

    //获取和设置图片1
    QString getImageName1() const;
    void setImageName1(const QString &imageName1);

    //获取和设置图片2
    QString getImageName2() const;
    void setImageName2(const QString &imageName2);

    //获取和设置图片1
    QPixmap getPixmap1() const;
    void setPixmap1(const QPixmap &pixmap1);

    //获取和设置图片2
    QPixmap getPixmap2() const;
    void setPixmap2(const QPixmap &pixmap2);

    //获取和设置动画类型
    AnimationType getAnimationType() const;
    void setAnimationType(const AnimationType &animationType);

public Q_SLOTS:
    //启动和停止动画
    void start();
    void stop();
};

#endif // IMAGEANIMATION_H
