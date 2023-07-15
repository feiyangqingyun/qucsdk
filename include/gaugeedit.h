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
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值
    QString unit;                   //单位

    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度
    bool animation;                 //是否启用动画显示
    double animationStep;           //动画显示时步长

    QColor outerCircleColor;        //外圆背景颜色
    QColor innerCircleColor;        //内圆背景颜色
    QColor centerCircleColor;       //中心圆颜色
    QColor usedColor;               //进度颜色
    QColor freeColor;               //空余颜色
    QColor textColor;               //文字颜色

    bool reverse;                   //是否往回走
    double currentValue;            //当前值
    QTimer *timer;                  //定时器绘制动画

    int offset;                     //偏移值
    QLineEdit *lineEdit;            //编辑框

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;
    QString getUnit()               const;

    int getStartAngle()             const;
    int getEndAngle()               const;
    bool getAnimation()             const;
    double getAnimationStep()       const;

    QColor getOuterCircleColor()    const;
    QColor getInnerCircleColor()    const;
    QColor getCenterCircleColor()   const;
    QColor getUsedColor()           const;
    QColor getFreeColor()           const;
    QColor getTextColor()           const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置范围值
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    //设置最大最小值
    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    //设置目标值
    void setValue(double value);
    void setValue(int value);

    //设置单位
    void setUnit(const QString &unit);

    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);

    //设置是否启用动画显示
    void setAnimation(bool animation);
    //设置动画显示的步长
    void setAnimationStep(double animationStep);

    //设置外圆背景颜色
    void setOuterCircleColor(const QColor &outerCircleColor);
    //设置内圆背景颜色
    void setInnerCircleColor(const QColor &innerCircleColor);
    //设置中心圆颜色
    void setCenterCircleColor(const QColor &centerCircleColor);
    //设置进度颜色
    void setUsedColor(const QColor &usedColor);
    //设置空余颜色
    void setFreeColor(const QColor &freeColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);

Q_SIGNALS:
    void valueChanged(double value);
    void valueChanged(int value);
};

#endif // GAUGEEDIT_H
