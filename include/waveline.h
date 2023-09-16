#ifndef WAVELINE_H
#define WAVELINE_H

/**
 * 直方波形图控件 作者:feiyangqingyun(QQ:517216493) 2016-11-06
 * 1. 可设置最大值。
 * 2. 可设置每次过渡的步长。
 * 3. 可设置item之间的间隔。
 * 4. 可设置渐变的背景颜色。
 * 5. 可设置线条的颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT WaveLine : public QWidget
#else
class WaveLine : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int step READ getStep WRITE setStep)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

public:
    explicit WaveLine(QWidget *parent = 0);
    ~WaveLine();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawLine(QPainter *painter);

private:
    int maxValue;           //最大值
    int step;               //步长
    int space;              //间距

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色
    QColor lineColor;       //线条颜色

    QTimer *timer;          //绘制定时器
    QVector<int> currentDataVec;//当前数据集合
    QVector<int> dataVec;   //目标数据集合

private slots:
    void updateData();      //更新数据

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置数据
    void setData(const QVector<int> &dataVec);

    //获取和设置最大值
    int getMaxValue() const;
    void setMaxValue(int maxValue);

    //获取和设置步长
    int getStep() const;
    void setStep(int step);

    //获取和设置间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置背景颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);
};

#endif // WAVELINE_H
