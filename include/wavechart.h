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

private slots:
    void updateData();

private:
    QRectF pointRect;               //绘制数据区域
    QVector<double> listData;       //数据集合

    double minValue;                //最小值
    double maxValue;                //最大值
    double xStep;                   //x轴步长
    double yStep;                   //y轴步长

    double space;                   //间隔
    QString title;                  //标题
    int smoothType;                 //平滑类型 0-不平滑 1-平滑算法1 2-平滑算法2

    bool showHLine;                 //是否显示横线
    bool showPoint;                 //是否显示坐标点
    bool showPointBg;               //是否显示坐标背景

    QColor bgColorStart;            //背景渐变开始颜色
    QColor bgColorEnd;              //背景渐变结束颜色
    QColor textColor;               //文字颜色
    QColor pointColor;              //坐标点颜色

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getXStep()               const;
    double getYStep()               const;

    double getSpace()               const;
    QString getTitle()              const;
    int getSmoothType()             const;

    bool getShowHLine()             const;
    bool getShowPoint()             const;
    bool getShowPointBg()           const;

    QColor getBgColorStart()        const;
    QColor getBgColorEnd()          const;
    QColor getTextColor()           const;
    QColor getPointColor()          const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //添加和设置数据数据
    void addData(double data);
    void setData(QVector<double> data);
    void clearData();

    //设置范围值及步长
    void setMinValue(double minValue);
    void setMaxValue(double maxValue);
    void setXStep(double xStep);
    void setYStep(double yStep);

    //设置间隔
    void setSpace(double space);
    //设置标题
    void setTitle(const QString &title);
    //设置平滑类型
    void setSmoothType(int smoothType);

    //设置显示横线
    void setShowHLine(bool showHLine);
    //设置显示坐标点
    void setShowPoint(bool showPoint);
    //设置显示坐标背景
    void setShowPointBg(bool showPointBg);

    //设置颜色
    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);
    void setTextColor(const QColor &textColor);
    void setPointColor(const QColor &pointColor);
};

#endif // WAVECHART_H
