#ifndef GAUGESIMPLE_H
#define GAUGESIMPLE_H

/**
 * 简单仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-11-20
 * 1. 可设置范围值，支持负数值。
 * 2. 可设置大刻度数量、小刻度数量。
 * 3. 可设置开始旋转角度、结束旋转角度。
 * 4. 可设置是否启用动画效果以及动画效果每次移动的步长。
 * 5. 自适应窗体拉伸，刻度尺、文字自动缩放。
 * 6. 可自由拓展各种渐变色，各圆的半径。
 * 7. 指示器样式可选择圆形指示器、指针指示器、圆角指针指示器、三角形指示器。
 * 8. 可设置当前值进度颜色和剩余值进度颜色。
 * 9. 背景透明，可自由设置背景图片。
 * 10. 可设置用户设定值、目标值。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeSimple : public QWidget
#else
class GaugeSimple : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PointerStyle)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)

    Q_PROPERTY(int scaleMajor READ getScaleMajor WRITE setScaleMajor)
    Q_PROPERTY(int scaleMinor READ getScaleMinor WRITE setScaleMinor)
    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int endAngle READ getEndAngle WRITE setEndAngle)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)

    Q_PROPERTY(bool showUserValue READ getShowUserValue WRITE setShowUserValue)
    Q_PROPERTY(double userValue READ getUserValue WRITE setUserValue)
    Q_PROPERTY(QColor userValueColor READ getUserValueColor WRITE setUserValueColor)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)

    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor titleColor READ getTitleColor WRITE setTitleColor)

    Q_PROPERTY(QString title READ getTitle WRITE setTitle)

    Q_PROPERTY(bool showOverlay READ getShowOverlay WRITE setShowOverlay)
    Q_PROPERTY(QColor overlayColor READ getOverlayColor WRITE setOverlayColor)

    Q_PROPERTY(PointerStyle pointerStyle READ getPointerStyle WRITE setPointerStyle)

public:
    enum PointerStyle {
        PointerStyle_Circle = 0,        //圆形指示器
        PointerStyle_Indicator = 1,     //指针指示器
        PointerStyle_IndicatorR = 2,    //圆角指针指示器
        PointerStyle_Triangle = 3       //三角形指示器
    };

    explicit GaugeSimple(QWidget *parent = 0);
    ~GaugeSimple();

protected:
    void paintEvent(QPaintEvent *);
    void drawArc(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawRoundCircle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawOverlay(QPainter *painter);

private slots:
    void updateValue();

private:
    double minValue;                //最小值
    double maxValue;                //最大值
    double value;                   //目标值

    int scaleMajor;                 //大刻度数量
    int scaleMinor;                 //小刻度数量
    int startAngle;                 //开始旋转角度
    int endAngle;                   //结束旋转角度

    bool animation;                 //是否启用动画显示
    double animationStep;           //动画显示时步长

    bool showUserValue;             //显示用户设定值
    double userValue;               //用户设定值
    QColor userValueColor;          //用户设定值颜色

    QColor usedColor;               //当前值颜色
    QColor freeColor;               //剩余值颜色

    QColor scaleColor;              //刻度尺颜色
    QColor pointerColor;            //指针颜色
    QColor textColor;               //文字颜色
    QColor titleColor;              //标题颜色

    QString title;                  //仪表盘标题

    bool showOverlay;               //显示遮罩层
    QColor overlayColor;            //遮罩层颜色

    PointerStyle pointerStyle;      //指针样式

    bool reverse;                   //是否往回走
    double currentValue;            //当前值
    QTimer *timer;                  //定时器绘制动画

public:
    double getMinValue()            const;
    double getMaxValue()            const;
    double getValue()               const;

    int getScaleMajor()             const;
    int getScaleMinor()             const;
    int getStartAngle()             const;
    int getEndAngle()               const;

    bool getAnimation()             const;
    double getAnimationStep()       const;

    bool getShowUserValue()         const;
    double getUserValue()           const;
    QColor getUserValueColor()      const;

    QColor getUsedColor()           const;
    QColor getFreeColor()           const;

    QColor getScaleColor()          const;
    QColor getPointerColor()        const;
    QColor getTextColor()           const;
    QColor getTitleColor()          const;

    QString getTitle()              const;

    bool getShowOverlay()           const;
    QColor getOverlayColor()        const;

    PointerStyle getPointerStyle()  const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置范围值
    void setRange(double minValue, double maxValue);

    //设置最大最小值
    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    //设置目标值
    void setValue(double value);
    void setValue(int value);

    //设置主刻度数量
    void setScaleMajor(int scaleMajor);
    //设置小刻度数量
    void setScaleMinor(int scaleMinor);
    //设置开始旋转角度
    void setStartAngle(int startAngle);
    //设置结束旋转角度
    void setEndAngle(int endAngle);

    //设置是否启用动画显示
    void setAnimation(bool animation);
    //设置动画显示的步长
    void setAnimationStep(double animationStep);

    //设置是否显示用户设定值
    void setShowUserValue(bool showUserValue);

    //设置用户值
    void setUserValue(double userValue);
    void setUserValue(int userValue);

    //设置用户设定值颜色
    void setUserValueColor(const QColor &userValueColor);

    //设置当前值颜色
    void setUsedColor(const QColor &usedColor);
    //设置剩余值颜色
    void setFreeColor(const QColor &freeColor);

    //设置刻度尺颜色
    void setScaleColor(const QColor &scaleColor);
    //设置指针颜色
    void setPointerColor(const QColor &pointerColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);
    //设置标题颜色
    void setTitleColor(const QColor &titleColor);

    //设置标题
    void setTitle(const QString &title);

    //设置是否显示遮罩层
    void setShowOverlay(bool showOverlay);
    //设置遮罩层颜色
    void setOverlayColor(const QColor &overlayColor);

    //设置指针样式
    void setPointerStyle(const PointerStyle &pointerStyle);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // GAUGESIMPLE_H
