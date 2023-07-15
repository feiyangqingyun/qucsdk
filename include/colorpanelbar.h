#ifndef COLORPANELBAR_H
#define COLORPANELBAR_H

/**
 * 颜色面板柱状条 作者:feiyangqingyun(QQ:517216493) 2017-11-21
 * 1. 可设置边框宽度、圆角角度、颜色。
 * 2. 可设置百分比选取框高度、边框宽度、圆角角度、颜色。
 * 3. 可设置上部分颜色、下部分颜色、禁用状态下背景颜色。
 * 4. 可设置是否遮住上部分、遮住颜色。
 * 5. 可设置显示为HSB模式。
 * 6. 可设置是否显示当前值或者当前值百分比。
 * 7. 可设置上下高度对应的范围值。
 * 8. 可设置初始值及初始百分比。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ColorPanelBar : public QWidget
#else
class ColorPanelBar : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

    Q_PROPERTY(bool autoHeight READ getAutoHeight WRITE setAutoHeight)
    Q_PROPERTY(int percentHeight READ getPercentHeight WRITE setPercentHeight)
    Q_PROPERTY(int percentBorder READ getPercentBorder WRITE setPercentBorder)
    Q_PROPERTY(int percentRadius READ getPercentRadius WRITE setPercentRadius)
    Q_PROPERTY(QColor percentColor READ getPercentColor WRITE setPercentColor)

    Q_PROPERTY(QColor topColor READ getTopColor WRITE setTopColor)
    Q_PROPERTY(QColor bottomColor READ getBottomColor WRITE setBottomColor)
    Q_PROPERTY(QColor disableColor READ getDisableColor WRITE setDisableColor)

    Q_PROPERTY(bool showOverlay READ getShowOverlay WRITE setShowOverlay)
    Q_PROPERTY(QColor overlayColor READ getOverlayColor WRITE setOverlayColor)

    Q_PROPERTY(bool staticMode READ getStaticMode WRITE setStaticMode)
    Q_PROPERTY(bool outMode READ getOutMode WRITE setOutMode)
    Q_PROPERTY(bool hsbMode READ getHSBMode WRITE setHSBMode)
    Q_PROPERTY(bool showValue READ getShowValue WRITE setShowValue)

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(double percent READ getPercent WRITE setPercent)
    Q_PROPERTY(QColor color READ getColor)

public:
    explicit ColorPanelBar(QWidget *parent = 0);

protected:
    void showEvent(QShowEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawOverlay(QPainter *painter);
    void drawPercent(QPainter *painter);

private:
    int borderWidth;            //边框宽度
    int borderRadius;           //边框圆角
    QColor borderColor;         //边框颜色

    bool autoHeight;            //自动高度
    int percentHeight;          //百分比选中框的高度
    int percentBorder;          //百分比选中框的边框宽度
    int percentRadius;          //百分比选中框的边框圆角
    QColor percentColor;        //百分比选中框的颜色

    QColor topColor;            //顶部颜色
    QColor bottomColor;         //底部颜色
    QColor disableColor;        //禁用状态下背景颜色

    bool showOverlay;           //是否遮住上部分
    QColor overlayColor;        //遮住颜色

    bool staticMode;            //静态颜色模式
    bool outMode;               //突出模式
    bool hsbMode;               //显示HSB颜色
    bool showValue;             //显示当前值

    double minValue;            //最小值
    double maxValue;            //最大值
    double value;               //当前值
    double percent;             //当前百分比
    QColor color;               //当前颜色

    int rightHeight;            //右侧百分比移动区域的高度
    bool isPressed;             //鼠标是否按下

    QPixmap bgPix;              //背景颜色图片
    QRect bgRect;               //背景色区域
    QRect overlayRect;          //遮住部分区域

private:
    void initColor();           //获取对应百分比处的颜色

public:
    int getBorderWidth()        const;
    int getBorderRadius()       const;
    QColor getBorderColor()     const;

    bool getAutoHeight()        const;
    int getPercentHeight()      const;
    int getPercentBorder()      const;
    int getPercentRadius()      const;
    QColor getPercentColor()    const;

    QColor getTopColor()        const;
    QColor getBottomColor()     const;
    QColor getDisableColor()    const;

    bool getShowOverlay()       const;
    QColor getOverlayColor()    const;

    bool getStaticMode()        const;
    bool getOutMode()           const;
    bool getHSBMode()           const;
    bool getShowValue()         const;

    double getMinValue()        const;
    double getMaxValue()        const;
    double getValue()           const;
    double getPercent()         const;
    QColor getColor()           const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置边框宽度
    void setBorderWidth(int borderWidth);
    //设置边框圆角
    void setBorderRadius(int borderRadius);
    //设置边框颜色
    void setBorderColor(const QColor &borderColor);

    //设置百分比选择框是否自动高度
    void setAutoHeight(bool autoHeight);
    //设置百分比选中框高度
    void setPercentHeight(int percentHeight);
    //设置百分比选中框的边框宽度
    void setPercentBorder(int percentBorder);
    //设置百分比选中框的边框圆角
    void setPercentRadius(int percentRadius);
    //设置百分比选中框的颜色
    void setPercentColor(const QColor &percentColor);

    //设置顶部颜色
    void setTopColor(const QColor &topColor);
    //设置底部颜色
    void setBottomColor(const QColor &bottomColor);
    //设置禁用状态下背景颜色
    void setDisableColor(const QColor &disableColor);

    //设置是否遮住上部分
    void setShowOverlay(bool showOverlay);
    //设置遮住颜色
    void setOverlayColor(const QColor &overlayColor);

    //设置是否为静态颜色模式
    void setStaticMode(bool staticMode);
    //设置是否突出显示选择框
    void setOutMode(bool outMode);
    //设置是否为HSB颜色模式
    void setHSBMode(bool hsbMode);
    //设置是否显示当前值
    void setShowValue(bool showValue);

    //设置最小值
    void setMinValue(double minValue);
    void setMinValue(int minValue);

    //设置最大值
    void setMaxValue(double maxValue);
    void setMaxValue(int maxValue);

    //设置当前值
    void setValue(double value);
    void setValue(int value);

    //设置当前百分比
    void setPercent(double percent);
    void setPercent(int percent);

Q_SIGNALS:
    void colorChanged(const QColor &color, double value, double percent);
};

#endif // COLORPANELBAR_H
