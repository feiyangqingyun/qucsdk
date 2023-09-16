#ifndef CUSTOMGRAPHICS_H
#define CUSTOMGRAPHICS_H

/**
 * 自定义多边形控件 作者:赵彦博(QQ:408815041) 整理:feiyangqingyun(QQ:517216493) 2019-03-28
 * 1. 自定义随意绘制多边形。
 * 2. 产生闭合形状后可单击选中移动整个多边形。
 * 3. 可拉动某个点。
 * 4. 支持多个多边形。
 * 5. 鼠标右键退出绘制。
 * 6. 可设置各种颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT CustomGraphics : public QWidget
#else
class CustomGraphics : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool selectDotVisible READ getSelectDotVisible WRITE setSelectDotVisible)
    Q_PROPERTY(int dotRadius READ getDotRadius WRITE setDotRadius)
    Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)

    Q_PROPERTY(QColor dotColor READ getDotColor WRITE setDotColor)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor polygonColor READ getPolygonColor WRITE setPolygonColor)
    Q_PROPERTY(QColor selectColor READ getSelectColor WRITE setSelectColor)

public:
    typedef struct {
        bool selected;
        QVector<QPoint> pos;
    } Polygon;

    explicit CustomGraphics(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    void drawPolygon(QPainter *p, const Polygon &v);
    void drawLines(QPainter *p, const QList<QPoint> &list, bool isFirst = true);

private:
    bool selectDotVisible;      //选中点可见
    int dotRadius;              //点的半径
    int lineWidth;              //线条宽度

    QColor dotColor;            //点的颜色
    QColor lineColor;           //线条颜色
    QColor polygonColor;        //多边形颜色
    QColor selectColor;         //选中颜色

    QPoint tempPoint;           //临时点
    QList<QPoint> tempPoints;   //点集合
    QList<Polygon> tempPolygons;//多边形集合

    bool pressed;               //鼠标是否按下
    QPoint lastPoint;           //鼠标按下处的坐标
    QPoint ellipsePos;          //保存按下点的坐标
    int selectedEllipseIndex;   //选中点的index
    Polygon pressedPolygon;     //保存按下时多边形的原始坐标
    int selectedIndex;          //选中多边形的index

private:
    //计算两点间的距离
    double length(const QPoint &p1, const QPoint &p2);
    //检测是否选中多边形
    bool checkPoint(const QVector<QPoint> &points, int x, int y);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

    //获取和设置选中点可见
    bool getSelectDotVisible() const;
    void setSelectDotVisible(bool selectDotVisible);

    //获取和设置点的圆角角度
    int getDotRadius() const;
    void setDotRadius(int dotRadius);

    //获取和设置线条宽度
    int getLineWidth() const;
    void setLineWidth(int lineWidth);

    //设置点颜色
    QColor getDotColor() const;
    void setDotColor(const QColor &dotColor);

    //设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //设置封闭区域颜色
    QColor getPolygonColor() const;
    void setPolygonColor(const QColor &polygonColor);

    //设置选中颜色
    QColor getSelectColor() const;
    void setSelectColor(const QColor &selectColor);

    //清除临时绘制的
    void clearTemp();
    //清除所有
    void clearAll();
    //获取多边形区域点坐标集合
    void getPoints();

Q_SIGNALS:
    //封闭区域多边形点坐标集合
    void receivePoints(const QVector<QPoint> &points);
};

#endif // CUSTOMGRAPHICS_H
