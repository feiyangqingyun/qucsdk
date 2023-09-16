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

private:
    //旋转坐标点
    QPointF rotatePoint(const QPointF &A, const double &angle);
    //校验最大最小值
    void checkMaxAndMin(double value);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置当前值
    double getValue() const;
    void setValue(double value);

    //获取和设置最小值
    double getMinValue() const;
    void setMinValue(double value);

    //获取和设置最大值
    double getMaxValue() const;
    void setMaxValue(double value);

    //设置范围值
    void setRange(double minValue, double maxValue);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    int getAnimationStep() const;
    void setAnimationStep(int animationStep);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &color);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &color);

    //获取和设置进度颜色
    QColor getUsedColor() const;
    void setUsedColor(const QColor &color);

    //获取和设置三角形颜色
    QColor getTriangleColor() const;
    void setTriangleColor(const QColor &color);

Q_SIGNALS:
    //值变化信号
    void valueChanged(double value);
};

#endif // GAUGEDECIBEL_H
