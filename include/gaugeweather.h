#ifndef GAUGEWEATHER_H
#define GAUGEWEATHER_H

/**
 * 天气仪表盘控件 作者:东门吹雪(QQ:709102202) 整理:飞扬青云(QQ:517216493) 2019-04-23
 * 1. 可设置两种值，比如温度、湿度。
 * 2. 可设置两种值的背景颜色、文字颜色。
 * 3. 可设置零度值左侧右侧两种颜色。
 * 4. 可设置圆的起始角度和结束角度。
 * 5. 可设置10种天气，晴天、雨天、阴天、大风等。
 * 6. 可设置各种其他颜色。
 * 7. 科设置是否启用动画显示进度以及动画步长。
 */

#include <QWidget>
#ifndef noxmlsvg
#include <QDomElement>
#include <QSvgRenderer>
#endif

#ifdef quc
class Q_DECL_EXPORT GaugeWeather : public QWidget
#else
class GaugeWeather : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(WeatherType)

    Q_PROPERTY(double outerValue READ getOuterValue WRITE setOuterValue)
    Q_PROPERTY(double outerMinValue READ getOuterMinValue WRITE setOuterMinValue)
    Q_PROPERTY(double outerMaxValue READ getOuterMaxValue WRITE setOuterMaxValue)

    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)
    Q_PROPERTY(int outerStartAngle READ getOuterStartAngle WRITE setOuterStartAngle)
    Q_PROPERTY(int outerEndAngle READ getOuterEndAngle WRITE setOuterEndAngle)

    Q_PROPERTY(QColor outerRingBgColor READ getOuterRingBgColor WRITE setOuterRingBgColor)
    Q_PROPERTY(QColor outerRingColor READ getOuterRingColor WRITE setOuterRingColor)

    Q_PROPERTY(double innerValue READ getInnerValue WRITE setInnerValue)
    Q_PROPERTY(double innerMinValue READ getInnerMinValue WRITE setInnerMinValue)
    Q_PROPERTY(double innerMaxValue READ getInnerMaxValue WRITE setInnerMaxValue)

    Q_PROPERTY(int innerStartAngle READ getInnerStartAngle WRITE setInnerStartAngle)
    Q_PROPERTY(int innerEndAngle READ getInnerEndAngle WRITE setInnerEndAngle)

    Q_PROPERTY(QColor innerRingBgColor READ getInnerRingBgColor WRITE setInnerRingBgColor)
    Q_PROPERTY(QColor innerRingNegativeColor READ getInnerNegativeColor WRITE setInnerNegativeColor)
    Q_PROPERTY(QColor innerRingPositiveColor READ getInnerPositiveColor WRITE setInnerPositiveColor)

    Q_PROPERTY(int innerScaleMajor READ getInnerScaleMajor WRITE setInnerScaleMajor)
    Q_PROPERTY(int innerScaleMinor READ getInnerScaleMinor WRITE setInnerScaleMinor)
    Q_PROPERTY(QColor innerScaleColor READ getInnerScaleColor WRITE setInnerScaleColor)
    Q_PROPERTY(QColor innerScaleNumColor READ getInnerScaleNumColor WRITE setInnerScaleNumColor)

    Q_PROPERTY(QColor centerPixMapNegativeColor READ getCenterPixMapNegativeColor WRITE setCenterPixMapNegativeColor)
    Q_PROPERTY(QColor centerPixMapPositiveColor READ getCenterPixMapPositiveColor WRITE setCenterPixMapPositiveColor)

    Q_PROPERTY(QColor outerValueTextColor READ getOuterValueTextColor WRITE setOuterValueTextColor)
    Q_PROPERTY(QColor innerNegativeValueTextColor READ getInnerNegativeValueTextColor WRITE setInnerNegativeValueTextColor)
    Q_PROPERTY(QColor innerPositiveValueTextColor READ getInnerPositiveValueTextColor WRITE setInnerPositiveValueTextColor)

    Q_PROPERTY(bool animation READ getAnimation WRITE setAnimation)
    Q_PROPERTY(double animationStep READ getAnimationStep WRITE setAnimationStep)
    Q_PROPERTY(WeatherType weatherType READ getWeatherType WRITE setWeatherType)

public:
    enum WeatherType {
        WeatherType_SUNNY = 0,          //晴天
        WeatherType_RAINY = 1,          //雨天
        WeatherType_SNOWY = 2,          //雪天
        WeatherType_CLOUDY = 3,         //多云
        WeatherType_WINDY = 4,          //风
        WeatherType_SNOWY_RAINY = 5,    //雪雨
        WeatherType_HAIL = 6,           //冰雹
        WeatherType_LIGHTNING = 7,      //闪电
        WeatherType_FOG = 8,            //雾
        WeatherType_PARTLYCLOUDY = 9    //局部多云
    };

    explicit GaugeWeather(QWidget *parent = 0);
    ~GaugeWeather();

protected:
    void paintEvent(QPaintEvent *);
    void drawOuterRingBg(QPainter *painter);
    void drawOuterRing(QPainter *painter);
    void drawInnerRingBg(QPainter *painter);
    void drawInnerRing(QPainter *painter);
    void drawInnerRingScale(QPainter *painter);
    void drawInnerRingScaleNum(QPainter *painter);
    void drawCenterPixMap(QPainter *painter);
    void drawValue(QPainter *painter);

private slots:
    void updateOuterValue();            //更新外圈数值
    void updateInnerValue();            //更新内圈数值

private:
    double outerMaxValue;               //外圈最大值
    double outerMinValue;               //外圈最小值
    double outerValue;                  //外圈值
    double outerCurrValue;              //外圈当前值

    int precision;                      //精确度,小数点后几位
    int outerStartAngle;                //外环开始旋转角度
    int outerEndAngle;                  //外环结束旋转角度

    QColor outerRingBgColor;            //外圈背景色
    QColor outerRingColor;              //外圈当前色

    double innerMaxValue;               //内圈最大值
    double innerMinValue;               //内圈最小值
    double innerValue;                  //内圈值
    double innerCurrValue;              //内圈当前值

    int innerStartAngle;                //内环开始旋转角度
    int innerEndAngle;                  //内环结束旋转角度

    QColor innerRingBgColor;            //内圈背景色
    QColor innerRingNegativeColor;      //内圈负值当前色
    QColor innerRingPositiveColor;      //内圈正值当前色

    int innerScaleMajor;                //内环大刻度数量
    int innerScaleMinor;                //内环小刻度数量
    QColor innerScaleColor;             //内环刻度颜色
    QColor innerScaleNumColor;          //内环刻度值颜色

    QColor centerPixMapNegativeColor;   //中心图片颜色
    QColor centerPixMapPositiveColor;   //中心图片颜色
    QString centerSvgPath;              //当前svg图片路径
    WeatherType weatherType;            //天气类型

    QColor outerValueTextColor;         //外环值文本颜色
    QColor innerNegativeValueTextColor; //内环正值文本颜色
    QColor innerPositiveValueTextColor; //内环负值文本颜色

    bool animation;                     //是否启用动画显示
    double animationStep;               //动画显示时步长

    bool outerReverse;                  //是否往回走
    bool innerReverse;                  //是否往回走
    bool clockWise;                     //顺时针

    QTimer *outerTimer;                 //外环定时器绘制动画
    QTimer *innerTimer;                 //内环定时器绘制动画

    //将svg文件中的xml数据颜色替换
#ifndef noxmlsvg
    void setColor(QDomElement elem, QString strtagname, QString strattr, QString strattrval);
    QString rgb2HexStr(const QColor &color);
#endif

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setOuterRange(double minValue, double maxValue);

    //获取和设置外环最小值
    double getOuterMinValue() const;
    void setOuterMinValue(double value);

    //获取和设置外环最大值
    double getOuterMaxValue() const;
    void setOuterMaxValue(double value);

    //获取和设置外环值
    double getOuterValue() const;
    void setOuterValue(double value);

    //获取和设置小数点
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置外环开始旋转角度
    int getOuterStartAngle() const;
    void setOuterStartAngle(int startAngle);

    //获取和设置外环结束旋转角度
    int getOuterEndAngle() const;
    void setOuterEndAngle(int endAngle);

    //获取和设置外环背景色
    QColor getOuterRingBgColor() const;
    void setOuterRingBgColor(const QColor &color);

    //获取和设置外环进度色
    QColor getOuterRingColor() const;
    void setOuterRingColor(const QColor &color);

    //设置内环范围值
    void setInnerRange(double minValue, double maxValue);

    //获取和设置内环最小值
    double getInnerMinValue() const;
    void setInnerMinValue(double value);

    //获取和设置内环最大值
    double getInnerMaxValue() const;
    void setInnerMaxValue(double value);

    //获取和设置内环值
    double getInnerValue() const;
    void setInnerValue(double value);

    //获取和设置内环开始旋转角度
    int getInnerStartAngle() const;
    void setInnerStartAngle(int startAngle);

    //获取和设置内环结束旋转角度
    int getInnerEndAngle() const;
    void setInnerEndAngle(int endAngle);

    //获取和设置内环背景颜色
    QColor getInnerRingBgColor() const;
    void setInnerRingBgColor(const QColor &color);

    //获取和设置内环负数值颜色
    QColor getInnerNegativeColor() const;
    void setInnerNegativeColor(const QColor &color);

    //获取和设置内环正数值颜色
    QColor getInnerPositiveColor() const;
    void setInnerPositiveColor(const QColor &color);

    //获取和设置内环刻度尺大间隔
    int getInnerScaleMajor() const;
    void setInnerScaleMajor(int value);

    //获取和设置内环刻度尺小间隔
    int getInnerScaleMinor() const;
    void setInnerScaleMinor(int value);

    //获取和设置内环刻度尺颜色
    QColor getInnerScaleColor() const;
    void setInnerScaleColor(const QColor &color);

    //获取和设置内环刻度值颜色
    QColor getInnerScaleNumColor() const;
    void setInnerScaleNumColor(const QColor &color);

    //获取和设置负数值图标颜色
    QColor getCenterPixMapNegativeColor() const;
    void setCenterPixMapNegativeColor(const QColor &color);

    //获取和设置正数值图标颜色
    QColor getCenterPixMapPositiveColor() const;
    void setCenterPixMapPositiveColor(const QColor &color);

    //获取和设置外环文本颜色
    QColor getOuterValueTextColor() const;
    void setOuterValueTextColor(const QColor &color);

    //获取和设置内环负数值颜色
    QColor getInnerNegativeValueTextColor() const;
    void setInnerNegativeValueTextColor(const QColor &color);

    //获取和设置内环正数值颜色
    QColor getInnerPositiveValueTextColor() const;
    void setInnerPositiveValueTextColor(const QColor &color);

    //获取和设置是否启用动画显示
    bool getAnimation() const;
    void setAnimation(bool animation);

    //获取和设置动画显示的步长
    double getAnimationStep() const;
    void setAnimationStep(double animationStep);

    //获取和设置天气类型
    WeatherType getWeatherType() const;
    void setWeatherType(const WeatherType &weatherType);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // GAUGEWEATHER_H
