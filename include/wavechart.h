#ifndef WAVECHART_H
#define WAVECHART_H

/**
 * 曲线图表控件 作者:feiyangqingyun(QQ:517216493) 2016-10-23
 * 1. 可设置间隔。
 * 2. 可设置标题。
 * 3. 可设置是否显示横线及坐标点。
 * 4. 可设置背景色文字颜色。
 * 5. 可设置范围值及x轴y轴步长。
 * 6. 暂时不支持最小值小于0的数据。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT WaveChart : public QWidget
#else
class WaveChart : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double xStep READ getXStep WRITE setXStep)
    Q_PROPERTY(double yStep READ getYStep WRITE setYStep)

    Q_PROPERTY(double space READ getSpace WRITE setSpace)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(int smoothType READ getSmoothType WRITE setSmoothType)

    Q_PROPERTY(bool showHLine READ getShowHLine WRITE setShowHLine)
    Q_PROPERTY(bool showPoint READ getShowPoint WRITE setShowPoint)
    Q_PROPERTY(bool showPointBg READ getShowPointBg WRITE setShowPointBg)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor pointColor READ getPointColor WRITE setPointColor)

public:
    explicit WaveChart(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawBox(QPainter *painter);
    void drawText(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawPoint(QPainter *painter);

private:
    QRectF pointRect;       //绘制数据区域
    QVector<double> listData;//数据集合

    double minValue;        //最小值
    double maxValue;        //最大值
    double xStep;           //x轴步长
    double yStep;           //y轴步长

    double space;           //间隔
    QString title;          //标题
    int smoothType;         //平滑类型 0-不平滑 1-平滑算法1 2-平滑算法2

    bool showHLine;         //是否显示横线
    bool showPoint;         //是否显示坐标点
    bool showPointBg;       //是否显示坐标背景

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色
    QColor textColor;       //文字颜色
    QColor pointColor;      //坐标点颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置最小值
    double getMinValue() const;
    void setMinValue(double minValue);

    //获取和设置最大值
    double getMaxValue() const;
    void setMaxValue(double maxValue);

    //获取和设置X步长
    double getXStep() const;
    void setXStep(double xStep);

    //获取和设置Y步长
    double getYStep() const;
    void setYStep(double yStep);

    //获取和设置间隔
    double getSpace() const;
    void setSpace(double space);

    //获取和设置标题
    QString getTitle() const;
    void setTitle(const QString &title);

    //获取和设置平滑类型
    int getSmoothType() const;
    void setSmoothType(int smoothType);

    //获取和设置显示横线
    bool getShowHLine() const;
    void setShowHLine(bool showHLine);

    //获取和设置显示坐标点
    bool getShowPoint() const;
    void setShowPoint(bool showPoint);

    //获取和设置显示坐标背景
    bool getShowPointBg() const;
    void setShowPointBg(bool showPointBg);

    //获取和设置背景开始颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    //获取和设置背景结束颜色
    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置数据点颜色
    QColor getPointColor() const;
    void setPointColor(const QColor &pointColor);

public Q_SLOTS:
    //添加和设置数据数据
    void addData(double data);
    void setData(QVector<double> data);
    void clearData();
};

#endif // WAVECHART_H
