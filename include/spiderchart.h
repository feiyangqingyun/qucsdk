#ifndef SPIDERCHART_H
#define SPIDERCHART_H

/**
 * 蜘蛛网图控件 作者:东门吹雪(QQ:709102202) 整理:feiyangqingyun(QQ:517216493) 2022-03-02
 * 1. 可设置最大值最小值范围值。
 * 2. 可设置层级数量。
 * 3. 可设置边数量。
 * 4. 可设置边宽度。
 * 5. 可设置边颜色。
 * 6. 可设置边描述（种类）。
 * 7. 可设置开始角度。
 * 8. 可设置标尺位置。
 * 9. 可设置标尺可见。
 * 10. 可设置图例可见。
 * 11. 可设置线条宽度。
 * 12. 可设置线条颜色。
 * 13. 可设置文字颜色。
 */

#include <QWidget>
#include <QMap>
#include <QVector>

//重新定义一些数据类型
typedef QMap<QString, QVector<float> > mdata;
typedef QMap<QString, QColor> mcolor;

#ifdef quc
class Q_DECL_EXPORT SpiderChart : public QWidget
#else
class SpiderChart : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(qreal minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(qreal maxValue READ getMaxValue WRITE setMaxValue)

    Q_PROPERTY(int levelCount READ getLevelCount WRITE setLevelCount)
    Q_PROPERTY(int sideCount READ getSideCount WRITE setSideCount)
    Q_PROPERTY(QColor sideColor READ getSideColor WRITE setSideColor)
    Q_PROPERTY(QString sideText READ getSideText WRITE setSideText)

    Q_PROPERTY(qreal startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int scalePos READ getScalePos WRITE setScalePos)
    Q_PROPERTY(bool scaleVisible READ getScaleVisible WRITE setScaleVisible)
    Q_PROPERTY(bool legendVisible READ getLegendVisible WRITE setLegendVisible)

    Q_PROPERTY(qreal lineWidth READ getLineWidth WRITE setLineWidth)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit SpiderChart(QWidget *parent = 0);
    ~SpiderChart();

protected:
    void paintEvent(QPaintEvent *);
    void drawSide(QPainter *painter);
    void drawLine(QPainter *painter);
    void drawText(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawLegend(QPainter *painter);

private:
    qreal minValue;     //最小值
    qreal maxValue;     //最大值

    int levelCount;     //层级数量
    int sideCount;      //边数量
    QColor sideColor;   //边颜色
    QString sideText;   //边描述(种类)

    int startAngle;     //开始角度
    int scalePos;       //标尺位置
    bool scaleVisible;  //标尺可见
    bool legendVisible; //图例可见

    qreal lineWidth;    //线条宽度
    QColor lineColor;   //线条颜色
    QColor textColor;   //文字颜色

    int radius;         //绘制半径
    double radiusPer;   //半径因子
    double startRad;    //开始弧度
    double deltaRad;    //三角弧度

    mdata dataValue;    //数据值集合
    mcolor dataColor;   //数据颜色集合

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置最小值
    qreal getMinValue() const;
    void setMinValue(qreal minValue);

    //获取和设置最大值
    qreal getMaxValue() const;
    void setMaxValue(qreal maxValue);

    //设置范围值
    void setRange(qreal minValue, qreal maxValue);

    //获取和设置设置层级数量
    int getLevelCount() const;
    void setLevelCount(int levelCount);

    //获取和设置设置边数量
    int getSideCount() const;
    void setSideCount(int sideCount);

    //获取和设置设置边颜色
    QColor getSideColor() const;
    void setSideColor(const QColor &sideColor);

    //获取和设置设置种类描述
    QString getSideText() const;
    void setSideText(const QString &sideText);

    //获取和设置开始角度
    int getStartAngle() const;
    void setStartAngle(int startAngle);

    //获取和设置标尺位置
    int getScalePos() const;
    void setScalePos(int scalePos);

    //获取和设置标尺可见
    bool getScaleVisible() const;
    void setScaleVisible(bool scaleVisible);

    //获取和设置图例可见
    bool getLegendVisible() const;
    void setLegendVisible(bool legendVisible);

    //获取和设置线条宽度
    qreal getLineWidth() const;
    void setLineWidth(qreal lineWidth);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //添加一项数据集合
    void addData(const QString &name, const QVector<float> &data, const QColor &color);
    //设置数据颜色
    void setDataColor(const QString &name, const QColor &color);
    //移除数据项
    void removeData(const QString &name);
    //清空所有数据
    void clearData();
};

#endif // SPIDERCHART_H
