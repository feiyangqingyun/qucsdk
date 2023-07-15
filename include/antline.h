#ifndef ANTLINE_H
#define ANTLINE_H

/**
 * 蚂蚁线控件 整理:feiyangqingyun(QQ:517216493) 2018-08-31
 * 1. 可设置蚂蚁线的长度。
 * 2. 可设置蚂蚁线的宽度=粗细。
 * 3. 可设置蚂蚁线的步长。
 * 4. 可设置蚂蚁线的流动速度。
 * 5. 可设置蚂蚁线的颜色。
 * 6. 可设置蚂蚁线的形状。
 */

#include <QWidget>
#include <QVector>

#ifdef quc
class Q_DECL_EXPORT AntLine : public QWidget
#else
class AntLine : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(LineStyle)

    Q_PROPERTY(int lineLen READ getLineLen WRITE setLineLen)
    Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)
    Q_PROPERTY(int lineStep READ getLineStep WRITE setLineStep)
    Q_PROPERTY(int lineSpeed READ getLineSpeed WRITE setLineSpeed)

    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(LineStyle lineStyle READ getLineStyle WRITE setLineStyle)

public:
    enum LineStyle {
        LineStyle_Rect = 0,         //矩形
        LineStyle_RoundedRect = 1,  //圆角矩形
        LineStyle_Ellipse = 2,      //椭圆
        LineStyle_Circle = 3        //圆形
    };

    explicit AntLine(QWidget *parent = 0);
    ~AntLine();

protected:
    void paintEvent(QPaintEvent *event);

private:
    int lineLen;                //线条长度
    int lineWidth;              //线条宽度
    int lineStep;               //每次移动的步长
    int lineSpeed;              //线条流动的速度

    QColor lineColor;           //线条颜色
    LineStyle lineStyle;        //线条样式

    int dashes;                 //线条长度
    int spaces;                 //空白长度
    QVector<qreal> dashPattern; //线条样式数据
    QTimer *timer;              //更新定时器

private slots:
    void updateValue();

public:
    int getLineLen()            const;
    int getLineWidth()          const;
    int getLineStep()           const;
    int getLineSpeed()          const;

    QColor getLineColor()       const;
    LineStyle getLineStyle()    const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置线条长度
    void setLineLen(int lineLen);
    //设置线条宽度
    void setLineWidth(int lineWidth);
    //设置线条步长
    void setLineStep(int lineStep);
    //设置线条速度
    void setLineSpeed(int lineSpeed);

    //设置线条颜色
    void setLineColor(const QColor &lineColor);
    //设置线条样式
    void setLineStyle(const LineStyle &lineStyle);

};

#endif // ANTLINE_H
