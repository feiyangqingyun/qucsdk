#ifndef CUSTOMROCKER_H
#define CUSTOMROCKER_H

#include <QWidget>

/**
 * 自定义摇杆控件 作者:赵彦博(QQ:408815041) 整理:feiyangqingyun(QQ:517216493) 2019-03-28
 * 1. 可设置是否只在外边缘线上。
 * 2. 可设置边框宽度。
 * 3. 可设置摇杆的半径。
 * 4. 可设置边框颜色。
 * 5. 可设置背景颜色。
 * 6. 可设置摇杆颜色。
 * 7. 发出移动角度信号。
 */

#ifdef quc
class Q_DECL_EXPORT CustomRocker : public QWidget
#else
class CustomRocker : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool online READ getOnline WRITE setOnline)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(int rockerRadius READ getRockerRadius WRITE setRockerRadius)

    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor rockerColor READ getRockerColor WRITE setRockerColor)

public:
    explicit CustomRocker(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resetPoint(const QPoint &point);

private:
    bool online;            //是否只在线上
    int borderWidth;        //边框宽度
    int rockerRadius;       //摇杆圆半径

    QColor borderColor;     //边框颜色
    QColor bgColor;         //背景颜色
    QColor rockerColor;     //摇杆颜色

    int radius;             //圆半径
    bool pressed;           //鼠标是否按下
    QPoint currentPoint;    //当前坐标
    QPoint centerPoint;     //中心坐标

private:
    double getDistance() ;
    double twoPtDistance(const QPointF &pt1, const QPointF &pt2);

public Q_SLOTS:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置是否限定边缘移动
    bool getOnline() const;
    void setOnline(bool online);

    //获取和设置边框宽度
    int getBorderWidth() const;
    void setBorderWidth(int borderWidth);

    //获取和设置摇杆圆角角度
    int getRockerRadius() const;
    void setRockerRadius(int rockerRadius);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置摇杆颜色
    QColor getRockerColor() const;
    void setRockerColor(const QColor &rockerColor);

Q_SIGNALS:
    //当前角度和离中心点的距离
    void moveAngle(double angle, double distance);
};

#endif // CUSTOMROCKER_H
