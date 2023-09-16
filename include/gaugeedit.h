#ifndef GAUGEEDIT_H
#define GAUGEEDIT_H

/**
 * 可输入仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2019-09-11
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置开始旋转角度、结束旋转角度。
 * 3. 可设置是否启用动画效果以及动画效果每次移动的步长。
 * 4. 可设置外圆背景、内圆背景、进度颜色、空余颜色、文字颜色。
 * 5. 自适应窗体拉伸，文字自动缩放。
 * 6. 支持tab及鼠标按下切换焦点。
 * 7. 支持直接输入值立即应用。
 * 8. 获取焦点控件自动变大。
 * 9. 支持键盘上下键步长为1修改值。
 * 10. 支持上下翻页键步长为10修改值。
 * 11. 支持鼠标滚轮步长为1修改值。
 * 12. 限定只能输入数字，支持小数位。
 * 13. 数字大小自适应控件宽度变大变小。
 */

#include <QWidget>

class QLineEdit;

#ifdef quc
class Q_DECL_EXPORT GaugeEdit : public QWidget
#else
class GaugeEdit : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)

    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)
    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(QColor outerCircleColor READ getOuterCircleColor WRITE setOuterCircleColor)
    Q_PROPERTY(QColor innerCircleColor READ getInnerCircleColor WRITE setInnerCircleColor)
    Q_PROPERTY(QColor centerCircleColor READ getCenterCircleColor WRITE setCenterCircleColor)
    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit GaugeEdit(QWidget *parent = 0);
    ~GaugeEdit();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void drawOuterCircle(QPainter *painter);
    void drawInnerCircle(QPainter *painter);
    void drawProgress(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawUnit(QPainter *painter);

private slots:
    void initStyle();
    void changeFont();
    void updateValue();
    void textChanged(const QString &value);

private:
    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //目标值
    QString unit;               //单位

    int startAngle;             //开始旋转角度
    int endAngle;               //结束旋转角度
    bool animation;             //是否启用动画显示
    double animationStep;       //动画显示时步长

    QColor outerCircleColor;    //外圆背景颜色
    QColor innerCircleColor;    //内圆背景颜色
    QColor centerCircleColor;   //中心圆颜色
    QColor usedColor;           //进度颜色
    QColor freeColor;           //空余颜色
    QColor textColor;           //文字颜色

    bool reverse;               //是否往回走
    double currentValue;        //当前值
    QTimer *timer;              //定时器绘制动画

    int offset;                 //偏移值
    QLineEdit *lineEdit;        //编辑框

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    //获取和设置最小值
    double getMinValue() const;
    void setMinValue(double minValue);

    //获取和设置最大值
    double getMaxValue() const;
    void setMaxValue(double maxValue);

    //获取和设置目标值
    double getValue() const;
    void setValue(double value);

    //获取和设置单位
    QString getUnit() const;
    void setUnit(const QString &unit);

    //获取和设置开始旋转角度
    int getStartAngle() const;
    void setStartAngle(int startAngle);

    //获取和设置结束旋转角度
    int getEndAngle() const;
    void setEndAngle(int endAngle);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    double getAnimationStep() const;
    void setAnimationStep(double animationStep);

    //获取和设置外圆背景颜色
    QColor getOuterCircleColor() const;
    void setOuterCircleColor(const QColor &outerCircleColor);

    //获取和设置内圆背景颜色
    QColor getInnerCircleColor() const;
    void setInnerCircleColor(const QColor &innerCircleColor);

    //获取和设置中心圆颜色
    QColor getCenterCircleColor() const;
    void setCenterCircleColor(const QColor &centerCircleColor);

    //获取和设置进度颜色
    QColor getUsedColor() const;
    void setUsedColor(const QColor &usedColor);

    //获取和设置空余颜色
    QColor getFreeColor() const;
    void setFreeColor(const QColor &freeColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(double value);
    void valueChanged(int value);
};

#endif // GAUGEEDIT_H
