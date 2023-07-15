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
    int borderRadius;           //边框圆角角度
    int borderMargin;           //边框边距

    int triangleWidth;          //提示箭头宽度
    int triangleHeight;         //提示箭头高度

    QColor borderColor;         //边框颜色
    QColor bgColor;             //背景颜色

    double blurRadius;          //模糊半径
    double triangleRatio;       //提示箭头位置比例
    TrianglePosition trianglePosition;//提示箭头位置

    //绘制路径+阴影效果
    QPainterPath path;
    QGraphicsDropShadowEffect *shadowEffect;

public:
    int getBorderRadius()       const;
    int getBorderMargin()       const;

    int getTriangleWidth()      const;
    int getTriangleHeight()     const;

    QColor getBorderColor()     const;
    QColor getBgColor()         const;

    double getBlurRadius()      const;
    double getTriangleRatio()   const;
    TrianglePosition getTrianglePosition() const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置边框圆角角度+边距
    void setBorderRadius(int borderRadius);
    void setBorderMargin(int borderMargin);

    //设置提示箭头的宽度高度
    void setTriangleWidth(int triangleWidth);
    void setTriangleHeight(int triangleHeight);

    //设置边框颜色+背景颜色
    void setBorderColor(const QColor &borderColor);
    void setBgColor(const QColor &bgColor);

    //设置边框模糊半径+提示箭头的比例+位置
    void setBlurRadius(double blurRadius);
    void setTriangleRatio(double triangleRatio);
    void setTrianglePosition(const TrianglePosition &trianglePosition);
};

#endif // SHADOWWIDGET_H
