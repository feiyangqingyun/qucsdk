#ifndef GAUGECLOUD_H
#define GAUGECLOUD_H

/**
 * 云台仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2018-09-02
 * 1. 可设置背景颜色。
 * 2. 可设置基准颜色。
 * 3. 可设置边框颜色。
 * 4. 可设置文本颜色。
 * 5. 可识别每个角度、中间鼠标按下并发出信号。
 * 6. 可设置八个角的图标和中间图标，随便换。
 * 7. 内置4种云台风格 黑色、白色、蓝色、紫色。
 * 8. 支持拓展鼠标进入离开时的切换。
 * 9. 精准识别内圆区域鼠标按下，而不是圆的矩形区域。
 * 10. 支持长按连续触发，支持设定延时间隔和执行间隔。
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

    Q_PROPERTY(QColor baseColor READ getBaseColor WRITE setBaseColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor arcColor READ getArcColor WRITE setArcColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor enterColor READ getEnterColor WRITE setEnterColor)
    Q_PROPERTY(QColor pressColor READ getPressColor WRITE setPressColor)

    Q_PROPERTY(QString iconText READ getIconText WRITE setIconText)
    Q_PROPERTY(QString centerText READ getCenterText WRITE setCenterText)
    Q_PROPERTY(CloudStyle cloudStyle READ getCloudStyle WRITE setCloudStyle)

    Q_PROPERTY(bool autoRepeat READ getAutoRepeat WRITE setAutoRepeat)
    Q_PROPERTY(int autoRepeatDelay READ getAutoRepeatDelay WRITE setAutoRepeatDelay)
    Q_PROPERTY(int autoRepeatInterval READ getAutoRepeatInterval WRITE setAutoRepeatInterval)

public:
    enum CloudStyle {
        CloudStyle_Black = 0,   //黑色风格
        CloudStyle_White = 1,   //白色风格
        CloudStyle_Blue = 2,    //蓝色风格
        CloudStyle_Purple = 3,  //紫色风格
        CloudStyle_Custom = 4   //自定义风格
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
    void drawArc(QPainter *painter);
    void drawText(QPainter *painter);

private:
    QColor bgColor;         //背景颜色
    QColor baseColor;       //基准颜色
    QColor arcColor;        //圆弧颜色
    QColor borderColor;     //边框颜色
    QColor textColor;       //文字颜色
    QColor enterColor;      //悬停文字颜色
    QColor pressColor;      //按下文字颜色

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
    void checkPressed();

private:
    double twoPtDistance(const QPointF &pt1, const QPointF &pt2);

public:
    QColor getBgColor()         const;
    QColor getBaseColor()       const;
    QColor getArcColor()        const;
    QColor getBorderColor()     const;
    QColor getTextColor()       const;
    QColor getEnterColor()      const;
    QColor getPressColor()      const;

    QString getIconText()       const;
    QString getCenterText()     const;
    CloudStyle getCloudStyle()  const;

    bool getAutoRepeat()        const;
    int getAutoRepeatDelay()    const;
    int getAutoRepeatInterval() const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置背景颜色
    void setBgColor(const QColor &bgColor);
    //设置基准颜色
    void setBaseColor(const QColor &baseColor);
    //设置圆弧颜色
    void setArcColor(const QColor &arcColor);
    //设置边框颜色
    void setBorderColor(const QColor &borderColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);
    //设置悬停文本颜色
    void setEnterColor(const QColor &enterColor);
    //设置按下文本颜色
    void setPressColor(const QColor &pressColor);

    //设置八个角图标
    void setIconText(const QString &iconText);
    //设置中间图标
    void setCenterText(const QString &centerText);
    //设置云台样式
    void setCloudStyle(const CloudStyle &cloudStyle);

    //设置是否启用长按重复执行
    void setAutoRepeat(bool autoRepeat);
    //设置延时执行长按时间
    void setAutoRepeatDelay(int autoRepeatDelay);
    //设置长按重复执行间隔
    void setAutoRepeatInterval(int autoRepeatInterval);

Q_SIGNALS:
    //鼠标按下的区域,共9个,从0-8依次表示底部/左下角/左侧/左上角/顶部/右上角/右侧/右下角/中间
    void mousePressed(int position, const QString &strPosition);
    //鼠标松开
    void mouseReleased(int position, const QString &strPosition);
};

#endif // GAUGECLOUD_H
