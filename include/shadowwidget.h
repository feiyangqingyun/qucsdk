#ifndef SHADOWWIDGET_H
#define SHADOWWIDGET_H

#include <QWidget>
#include <QPainterPath>
class QGraphicsDropShadowEffect;

/**
 * 阴影边框窗体 作者:赵彦博(QQ:408815041) 整理:feiyangqingyun(QQ:517216493) 2021-03-18
 * 1. 可设置提示窗体的圆角角度。
 * 2. 可设置提示窗体的边距。
 * 3. 可设置提示箭头的宽度和高度。
 * 4. 可设置提示箭头的位置比例。
 * 5. 可设置提示箭头的位置为上、下、左、右、无。
 * 6. 可设置阴影边框颜色。
 * 7. 可设置窗体背景颜色。
 */

#ifdef quc
class Q_DECL_EXPORT ShadowWidget : public QWidget
#else
class ShadowWidget : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(TrianglePosition)

    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(int borderMargin READ getBorderMargin WRITE setBorderMargin)

    Q_PROPERTY(int triangleWidth READ getTriangleWidth WRITE setTriangleWidth)
    Q_PROPERTY(int triangleHeight READ getTriangleHeight WRITE setTriangleHeight)

    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

    Q_PROPERTY(double blurRadius READ getBlurRadius WRITE setBlurRadius)
    Q_PROPERTY(double triangleRatio READ getTriangleRatio WRITE setTriangleRatio)
    Q_PROPERTY(TrianglePosition trianglePosition READ getTrianglePosition WRITE setTrianglePosition)

public:
    //提示箭头位置
    enum TrianglePosition {
        TrianglePosition_None = 0,
        TrianglePosition_Top = 1,
        TrianglePosition_Right = 2,
        TrianglePosition_Bottom = 3,
        TrianglePosition_Left = 4
    };

    explicit ShadowWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawPath();

private:
    int borderRadius;       //边框圆角角度
    int borderMargin;       //边框边距

    int triangleWidth;      //提示箭头宽度
    int triangleHeight;     //提示箭头高度

    QColor borderColor;     //边框颜色
    QColor bgColor;         //背景颜色

    double blurRadius;      //模糊半径
    double triangleRatio;   //提示箭头位置比例

    //提示箭头位置
    TrianglePosition trianglePosition;

    //绘制路径+阴影效果
    QPainterPath path;
    QGraphicsDropShadowEffect *shadowEffect;

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置边框圆角角度+边距
    int getBorderRadius() const;
    void setBorderRadius(int borderRadius);

    int getBorderMargin() const;
    void setBorderMargin(int borderMargin);

    //获取和设置提示箭头的宽度
    int getTriangleWidth() const;
    void setTriangleWidth(int triangleWidth);

    //获取和设置提示箭头的高度
    int getTriangleHeight() const;
    void setTriangleHeight(int triangleHeight);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置模糊半径
    double getBlurRadius() const;
    void setBlurRadius(double blurRadius);

    //获取和设置箭头比例
    double getTriangleRatio() const;
    void setTriangleRatio(double triangleRatio);

    //获取和设置箭头位置
    TrianglePosition getTrianglePosition() const;
    void setTrianglePosition(const TrianglePosition &trianglePosition);
};

#endif // SHADOWWIDGET_H
