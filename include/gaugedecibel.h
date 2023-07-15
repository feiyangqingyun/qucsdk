#ifndef GAUGEDECIBEL_H
#define GAUGEDECIBEL_H

/**
 * 分贝仪表盘控件 作者:东门吹雪(QQ:709102202) 整理:飞扬青云(QQ:517216493) 2019-04-23
 * 1. 可设置当前度数。
 * 2. 可设置背景颜色、文字颜色。
 * 3. 可设置边框颜色、边框宽度。
 * 4. 可设置渐变内环颜色集合。
 * 5. 可设置启动动画和动画步长。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeDecibel : public QWidget
#else
class GaugeDecibel : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor triangleColor READ getTriangleColor WRITE setTriangleColor)

public:
    explicit GaugeDecibel(QWidget *parent = 0);
    ~GaugeDecibel();

private slots:
    void updateValue();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawAngle(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawTriangle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double ave_angle;
    double angle;           //起止角度
    double value;           //值
    double minValue;        //最小值
    double maxValue;        //最大值

    bool animation;         //是否启用动画显示
    int animationStep;      //动画显示时步长

    bool reverse;           //是否往回走
    double currentValue;    //当前值
    QTimer *timer;          //定时器绘制动画

    double mMin;            //最小值三角
    double mMax;            //走过的最大值三角
    bool isFirstData;       //是否首次最大值

    QColor bgColor;         //背景色
    QColor textColor;       //文字颜色
    QColor usedColor;       //进度色
    QColor triangleColor;   //三角形颜色

    QPointF rotatePoint(const QPointF &A, const double &angle);
    void checkMaxAndMin(double value);

public:
    double getValue()               const;
    double getMaxValue()            const;
    double getMinValue()            const;

    bool getAnimation()             const;
    int getAnimationStep()          const;

    QColor getBgColor()             const;
    QColor getTextColor()           const;
    QColor getUsedColor()           const;
    QColor getTriangleColor()       const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置外环最大最小值
    void setValue(double value);
    void setMinValue(double value);
    void setMaxValue(double value);
    void setRange(double minValue, double maxValue);

    //设置是否启用动画显示
    void setAnimation(bool animation);
    //设置动画显示的步长
    void setAnimationStep(int animationStep);

    //设置背景颜色+文字颜色+进度颜色+三角形颜色
    void setBgColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setUsedColor(const QColor &color);
    void setTriangleColor(const QColor &color);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // GAUGEDECIBEL_H
