#ifndef SCANTANTAN_H
#define SCANTANTAN_H

/**
 * 探探雷达控件 作者:东门吹雪(QQ:709102202) 整理:feiyangqingyun(QQ:517216493) 2019-10-01
 * 1. 可设置中间图像。
 * 2. 可设置图像的边框宽度、边框颜色，产生圆形图像效果。
 * 3. 可设置扫描线的最大半径。
 * 4. 可设置扫描线的边框宽度。
 * 5. 可设置扩散圈的线条宽度。
 * 6. 可设置扫描线的每次移动的步长。
 * 7. 可设置扩散圈的每次移动的步长。
 * 8. 可设置扫描线的颜色。
 * 9. 可设置扩散圈的颜色。
 */

#include <QWidget>

class QSequentialAnimationGroup;

#ifdef quc
class Q_DECL_EXPORT ScanTanTan : public QWidget
#else
class ScanTanTan : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QPixmap image READ getImage WRITE setImage)
    Q_PROPERTY(int imageBorderWidth READ getImageBorderWidth WRITE setImageBorderWidth)
    Q_PROPERTY(QColor imageBorderColor READ getImageBorderColor WRITE setImageBorderColor)

    Q_PROPERTY(int scanRadius READ getScanRadius WRITE setScanRadius)
    Q_PROPERTY(int scanWidth READ getScanWidth WRITE setScanWidth)
    Q_PROPERTY(int ringWidth READ getRingWidth WRITE setRingWidth)

    Q_PROPERTY(int scanStep READ getScanStep WRITE setScanStep)
    Q_PROPERTY(int ringStep READ getRingStep WRITE setRingStep)

    Q_PROPERTY(QColor scanColor READ getScanColor WRITE setScanColor)
    Q_PROPERTY(QColor ringColor READ getRingColor WRITE setRingColor)

public:
    struct RingData {
        int radius;     //半径
        float width;    //画笔粗细
        int alpha;      //透明度
    };

    explicit ScanTanTan(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawScan(QPainter *painter);
    void drawRing(QPainter *painter);
    void drawImage(QPainter *painter);

private slots:
    void changeScan();
    void changeRing();
    void updateImage(const QVariant &value);
    double twoPtDistance(const QPointF &pt1, const QPointF &pt2);

private:
    QPixmap image;          //中间图片
    int imageBorderWidth;   //图片边框宽度
    QColor imageBorderColor;//图片边框颜色

    int scanRadius;         //扫描线最大半径
    int scanWidth;          //扫描线边框宽度
    int ringWidth;          //扩散圈线条宽度

    int scanStep;           //扫描线每次移动的步长
    int ringStep;           //扩散圈每次移动的步长

    QColor scanColor;       //扫描线颜色
    QColor ringColor;       //扩散圈颜色

    bool isPressed;         //鼠标是否按下
    int ringRadius;         //扩散圈半径
    int imageRadius;        //图片半径
    int scanDeg;            //当前扫描线角度

    //扩散圈集合,鼠标可能按下多次则产生多个扩散圈,用队列存起来
    QList<RingData> rings;
    //动画组合,用于中间图片的变大放小
    QSequentialAnimationGroup *animationGroup;

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置图片
    QPixmap getImage() const;
    void setImage(const QPixmap &image);

    //获取和设置图片边框宽度
    int getImageBorderWidth() const;
    void setImageBorderWidth(int imageBorderWidth);

    //获取和设置图片边框颜色
    QColor getImageBorderColor() const;
    void setImageBorderColor(const QColor &imageBorderColor);

    //获取和设置扫描线最大半径
    int getScanRadius() const;
    void setScanRadius(int scanRadius);

    //获取和设置扫描线边框宽度
    int getScanWidth() const;
    void setScanWidth(int scanWidth);

    //获取和设置扩散圈线条宽度
    int getRingWidth() const;
    void setRingWidth(int ringWidth);

    //获取和设置扫描线步长
    int getScanStep() const;
    void setScanStep(int scanStep);

    //获取和设置扩散圈步长
    int getRingStep() const;
    void setRingStep(int ringStep);

    //获取和设置扫描线颜色
    QColor getScanColor() const;
    void setScanColor(const QColor &scanColor);

    //获取和设置扩散圈颜色
    QColor getRingColor() const;
    void setRingColor(const QColor &ringColor);
};

#endif // SCANTANTAN_H
