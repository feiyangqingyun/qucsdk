#ifndef PROGRESSROUND_H
#define PROGRESSROUND_H

/**
 * 圆形进度条控件 作者:feiyangqingyun(QQ:517216493) 2016-10-16
 * 本控件来源于网络(原作者:不详(https://sourceforge.net/projects/qroundprogress/))
 * 1. 支持三种风格样式 圆环风格、饼状风格、线条风格。
 * 2. 自动居中绘制显示。
 * 3. 可设置顺时针逆时针走向。
 * 4. 可设置起始进度位置。
 * 5. 可设置范围值。
 * 6. 可设置各种颜色。
 * 7. 可设置当前值。
 * 8. 可设置整个部件的背景。
 * 9. 可设置未填充进度区域的背景。
 * 10. 可设置文本显示所在的中间圆环的背景。
 * 11. 可设置未填充区域的前景色、边框色。
 * 12. 可设置填充进度条区域的背景色。
 * 13. 可设置在中心显示的文本色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressRound : public QWidget
#else
class ProgressRound : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(BarStyle)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor baseColor READ getBaseColor WRITE setBaseColor)
    Q_PROPERTY(QColor innerBgColor READ getInnerBgColor WRITE setInnerBgColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor progressColor READ getProgressColor WRITE setProgressColor)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(double nullPosition READ getNullPosition WRITE setNullPosition)
    Q_PROPERTY(double outlinePenWidth READ getOutlinePenWidth WRITE setOutlinePenWidth)
    Q_PROPERTY(double dataPenWidth READ getDataPenWidth WRITE setDataPenWidth)

    Q_PROPERTY(BarStyle barStyle READ getBarStyle WRITE setBarStyle)
    Q_PROPERTY(QString format READ getFormat WRITE setFormat)
    Q_PROPERTY(bool clockWise READ getClockWise WRITE setClockWise)

public:
    enum BarStyle {
        BarStyle_Donut = 0, //圆环风格
        BarStyle_Pie = 1,   //饼状风格
        BarStyle_Line = 2   //线条风格
    };

    explicit ProgressRound(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter, const QRectF &baseRect);
    void drawBase(QPainter *painter, const QRectF &baseRect);
    void drawProgress(QPainter *painter, const QRectF &baseRect);
    void calculateInnerRect(const QRectF &baseRect, double outerRadius, QRectF &innerRect, double &innerRadius);
    void drawInnerBackground(QPainter *painter, const QRectF &innerRect);
    void drawValue(QPainter *painter, const QRectF &innerRect, double innerRadius);

private:
    void rebuildDataBrushIfNeeded();

private:
    QColor bgColor;                 //背景颜色
    QColor textColor;               //文本颜色
    QColor baseColor;               //未填充区域的背景
    QColor innerBgColor;            //文本所在圆环的背景
    QColor borderColor;             //边框颜色
    QColor progressColor;           //进度颜色

    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    int precision;                  //精确度,小数点后几位

    double nullPosition;            //最小值位置
    double outlinePenWidth;         //外边框宽度
    double dataPenWidth;            //数据文本宽度

    BarStyle barStyle;              //样式
    QString format;                 //文本格式
    bool clockWise;                 //顺时针
    QGradientStops gradientData;    //颜色集合

public:
    QColor getBgColor()             const;
    QColor getTextColor()           const;
    QColor getBaseColor()           const;
    QColor getInnerBgColor()        const;
    QColor getBorderColor()         const;
    QColor getProgressColor()       const;

    double getValue()               const;
    double getMinValue()            const;
    double getMaxValue()            const;
    int getPrecision()              const;

    double getNullPosition()        const;
    double getOutlinePenWidth()     const;
    double getDataPenWidth()        const;

    BarStyle getBarStyle()          const;
    QString	getFormat()             const;
    bool getClockWise()             const;
    QGradientStops getGradientData()const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置各种颜色
    void setBgColor(const QColor &bgColor);
    void setTextColor(const QColor &textColor);
    void setBaseColor(const QColor &baseColor);
    void setInnerBgColor(const QColor &innerBgColor);
    void setBorderColor(const QColor &borderColor);
    void setProgressColor(const QColor &progressColor);

    //设置范围值
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    //设置最大最小值
    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    //设置目标值
    void setValue(double value);
    void setValue(int value);

    //设置精确度,小数点后几位
    void setPrecision(int precision);

    //设置最小值位置
    void setNullPosition(double nullPosition);
    //设置外边框宽度
    void setOutlinePenWidth(double outlinePenWidth);
    //设置数据文本宽度
    void setDataPenWidth(double dataPenWidth);

    //设置样式
    void setBarStyle(const BarStyle &barStyle);
    //设置格式
    void setFormat(const QString &format);

    //设置进度旋转方向
    void setClockWise(bool clockWise);
    //设置颜色集合
    void setGradientData(const QGradientStops &gradientData);
};

#endif // PROGRESSROUND_H
