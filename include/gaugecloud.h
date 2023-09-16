#ifndef GAUGECLOUD_H
#define GAUGECLOUD_H

/**
 * 云台仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2018-09-02
 * 1. 可设置背景颜色。
 * 2. 可设置渐变边框颜色。
 * 3. 可设置文字颜色、文字按下和悬停颜色。
 * 4. 可设置边距以及是否启用渐变边框。
 * 5. 可设置中间圆形边框颜色和宽度。
 * 6. 可设置中间圆形背景颜色和悬停颜色。
 * 7. 可识别每个角度、中间鼠标按下并发出信号。
 * 8. 可设置八个角的图标和中间图标，随便换。
 * 9. 内置4种云台风格 黑色、白色、蓝色、紫色。
 * 10. 支持拓展鼠标进入离开时的切换。
 * 11. 精准识别内圆区域鼠标按下，而不是圆的矩形区域。
 * 12. 支持长按连续触发，支持设定延时间隔和执行间隔。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeCloud : public QWidget
#else
class GaugeCloud : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(CloudStyle)

    Q_PROPERTY(int margin READ getMargin WRITE setMargin)
    Q_PROPERTY(bool gradient READ getGradient WRITE setGradient)

    Q_PROPERTY(QColor borderColor1 READ getBorderColor1 WRITE setBorderColor1)
    Q_PROPERTY(QColor borderColor2 READ getBorderColor2 WRITE setBorderColor2)
    Q_PROPERTY(QColor borderColor3 READ getBorderColor3 WRITE setBorderColor3)
    Q_PROPERTY(QColor borderColor4 READ getBorderColor4 WRITE setBorderColor4)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)    
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor enterColor READ getEnterColor WRITE setEnterColor)
    Q_PROPERTY(QColor pressColor READ getPressColor WRITE setPressColor)

    Q_PROPERTY(int centerBorderWidth READ getCenterBorderWidth WRITE setCenterBorderWidth)
    Q_PROPERTY(QColor centerBorderColor READ getCenterBorderColor WRITE setCenterBorderColor)
    Q_PROPERTY(QColor centerBgColor READ getCenterBgColor WRITE setCenterBgColor)
    Q_PROPERTY(QColor centerHoverColor READ getCenterHoverColor WRITE setCenterHoverColor)

    Q_PROPERTY(QString iconText READ getIconText WRITE setIconText)
    Q_PROPERTY(QString centerText READ getCenterText WRITE setCenterText)
    Q_PROPERTY(CloudStyle cloudStyle READ getCloudStyle WRITE setCloudStyle)

    Q_PROPERTY(bool autoRepeat READ getAutoRepeat WRITE setAutoRepeat)
    Q_PROPERTY(int autoRepeatDelay READ getAutoRepeatDelay WRITE setAutoRepeatDelay)
    Q_PROPERTY(int autoRepeatInterval READ getAutoRepeatInterval WRITE setAutoRepeatInterval)

public:
    enum CloudStyle {
        CloudStyle_Black = 1,   //黑色风格
        CloudStyle_White = 2,   //白色风格
        CloudStyle_Blue = 3,    //蓝色风格
        CloudStyle_Purple = 4,  //紫色风格
        CloudStyle_Custom = 255 //自定义风格
    };

    explicit GaugeCloud(QWidget *parent = 0);
    ~GaugeCloud();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    void paintEvent(QPaintEvent *);
    void drawCircle(QPainter *painter, int radius, const QBrush &brush);
    void drawArc(QPainter *painter, int radius, const QColor &color);
    void drawText(QPainter *painter);

private:
    int margin;             //边距
    bool gradient;          //是否渐变

    QColor borderColor1;    //边框颜色1
    QColor borderColor2;    //边框颜色2
    QColor borderColor3;    //边框颜色3
    QColor borderColor4;    //边框颜色4

    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色
    QColor enterColor;      //悬停文字颜色
    QColor pressColor;      //按下文字颜色

    int centerBorderWidth;  //中间边框宽度
    QColor centerBorderColor;//中间边框颜色
    QColor centerBgColor;   //中间背景颜色
    QColor centerHoverColor;//中间悬停颜色

    QString iconText;       //八个角图标
    QString centerText;     //中间图标
    CloudStyle cloudStyle;  //云台样式

    bool autoRepeat;        //是否重复执行按下
    int autoRepeatDelay;    //延时执行按下动作
    int autoRepeatInterval; //重复执行间隔

    bool enter;             //鼠标是否进入
    bool pressed;           //鼠标是否按下
    bool inCenter;          //是否在内圆中
    QPoint lastPoint;       //鼠标按下处的坐标

    QRectF centerRect;      //中间区域
    QRectF leftRect;        //左侧图标区域
    QRectF topRect;         //上侧图标区域
    QRectF rightRect;       //右侧图标区域
    QRectF bottomRect;      //下侧图标区域
    QRectF leftTopRect;     //左上角图标区域
    QRectF rightTopRect;    //右上角图标区域
    QRectF leftBottomRect;  //左下角图标区域
    QRectF rightBottomRect; //右下角图标区域

    QFont iconFont;         //图形字体
    int position;           //最后按下的位置
    QStringList positions;  //位置对应文字集合
    QTimer *timer;          //定时器触发长按

private slots:
    //初始化颜色
    void initColor();
    //检查是否按下
    void checkPressed();
    //两个坐标之间的距离
    double twoPtDistance(const QPointF &pt1, const QPointF &pt2);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置边距
    int getMargin() const;
    void setMargin(int margin);

    //获取和设置是否渐变
    bool getGradient() const;
    void setGradient(bool gradient);

    //获取和设置边框颜色1
    QColor getBorderColor1() const;
    void setBorderColor1(const QColor &borderColor1);

    //获取和设置边框颜色2
    QColor getBorderColor2() const;
    void setBorderColor2(const QColor &borderColor2);

    //获取和设置边框颜色3
    QColor getBorderColor3() const;
    void setBorderColor3(const QColor &borderColor3);

    //获取和设置边框颜色4
    QColor getBorderColor4() const;
    void setBorderColor4(const QColor &borderColor4);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文本颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置悬停文本颜色
    QColor getEnterColor() const;
    void setEnterColor(const QColor &enterColor);

    //获取和设置按下文本颜色
    QColor getPressColor() const;
    void setPressColor(const QColor &pressColor);

    //获取和设置中间边框宽度
    int getCenterBorderWidth() const;
    void setCenterBorderWidth(int centerBorderWidth);

    //获取和设置中间边框颜色
    QColor getCenterBorderColor() const;
    void setCenterBorderColor(const QColor &centerBorderColor);

    //获取和设置中间背景颜色
    QColor getCenterBgColor() const;
    void setCenterBgColor(const QColor &centerBgColor);

    //获取和设置中间悬停颜色
    QColor getCenterHoverColor() const;
    void setCenterHoverColor(const QColor &centerHoverColor);

    //获取和设置八个角图标
    QString getIconText() const;
    void setIconText(const QString &iconText);

    //获取和设置中间图标
    QString getCenterText() const;
    void setCenterText(const QString &centerText);

    //获取和设置云台样式
    CloudStyle getCloudStyle() const;
    void setCloudStyle(const CloudStyle &cloudStyle);

    //获取和设置是否启用长按重复执行
    bool getAutoRepeat() const;
    void setAutoRepeat(bool autoRepeat);

    //获取和设置延时执行长按时间
    int getAutoRepeatDelay() const;
    void setAutoRepeatDelay(int autoRepeatDelay);

    //获取和设置长按重复执行间隔
    int getAutoRepeatInterval() const;
    void setAutoRepeatInterval(int autoRepeatInterval);

Q_SIGNALS:
    //鼠标按下的区域共9个 0=底部 1=左下角 2=左侧 3=左上角 4=顶部 5=右上角 6=右侧 7=右下角 8=中间
    void mousePressed(int position, const QString &strPosition);
    //鼠标松开
    void mouseReleased(int position, const QString &strPosition);
};

#endif // GAUGECLOUD_H
