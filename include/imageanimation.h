#ifndef IMAGEANIMATION_H
#define IMAGEANIMATION_H

/**
 * 图片切换动画控件 作者:赵彦博(QQ:408815041 zyb920@hotmail.com) 2019-06-10
 * 1. 可设置动画类型，默认9种，后期会增加更多。
 * FadeEffect = 0,             //图像1渐渐变淡,图像2渐渐显现
 * BlindsEffect = 1,           //百叶窗效果
 * FlipRightToLeft = 2,        //图像从右向左翻转
 * OutsideToInside = 3,        //从外到内水平分割
 * MoveLeftToRightEffect = 4,  //图像1从左至右退出可视区域,同时图像2从左至右进入可视区域
 * MoveRightToLeftEffect = 5,  //图像1从左至右退出可视区域,同时图像2从左至右进入可视区域
 * MoveBottomToUpEffect = 6,   //图像1从下至上退出可视区域,同时图像2从下至上进入可视区域
 * MoveUpToBottomEffect = 7,   //图像1从上至下退出可视区域,同时图像2从上至下进入可视区域
 * MoveBottomToLeftUpEffect = 8//图像1不动,同时图像2从右下到左上
 * 2. 可设置两张图片的路径名称或者图片。
 * 3. 可设置动画因子。
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
    float factor;                   //动画因子(0 - 1.0之间变化)
    QString imageName1;             //图片1路径名称
    QString imageName2;             //图片2路径名称
    QPixmap pixmap1;                //图片1
    QPixmap pixmap2;                //图片2
    AnimationType animationType;    //动画效果类型

    QPropertyAnimation *animation;  //动画属性

public:
    float getFactor()               const;
    QString getImageName1()         const;
    QString getImageName2()         const;
    QPixmap getPixmap1()            const;
    QPixmap getPixmap2()            const;
    AnimationType getAnimationType()const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置动画因子
    void setFactor(float factor);

    //设置图片1+图片2路径名称
    void setImageName1(const QString &imageName1);
    void setImageName2(const QString &imageName2);

    //设置图片1+图片2
    void setPixmap1(const QPixmap &pixmap1);
    void setPixmap2(const QPixmap &pixmap2);

    //设置动画类型
    void setAnimationType(const AnimationType &animationType);

    //启动+停止动画
    void start();
    void stop();
};

#endif // IMAGEANIMATION_H
