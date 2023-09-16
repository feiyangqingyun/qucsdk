#ifndef PROGRESSPLAY_H
#define PROGRESSPLAY_H

/**
 * 播放进度条控件 作者:feiyangqingyun(QQ:517216493) 2019-04-30
 * 1. 可设置总大小、缓存大小、已播放不同的值。
 * 2. 可设置总大小、缓存大小、已播放不同的颜色。
 * 3. 可设置圆角角度。
 * 4. 可设置启用自动圆角。
 * 5. 可设置边框宽度、颜色。
 * 6. 可设置背景颜色、文字颜色。
 * 7. 可直接单击定位，发送信号。
 * 8. 可设置启用进度圆角角度。
 * 9. 精准计算圆角角度，解决了QSS中border-radius当进度小于圆角角度出现方形的bug。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressPlay : public QWidget
#else
class ProgressPlay : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int valueAll READ getValueAll WRITE setValueAll)
    Q_PROPERTY(int valuePlay READ getValuePlay WRITE setValuePlay)
    Q_PROPERTY(int valueLoad READ getValueLoad WRITE setValueLoad)

    Q_PROPERTY(QColor colorPlay READ getColorPlay WRITE setColorPlay)
    Q_PROPERTY(QColor colorLoad READ getColorLoad WRITE setColorLoad)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(int radius READ getRadius WRITE setRadius)
    Q_PROPERTY(bool autoRadius READ getAutoRadius WRITE setAutoRadius)
    Q_PROPERTY(bool showProgressRadius READ getShowProgressRadius WRITE setShowProgressRadius)

    Q_PROPERTY(double borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

public:
    explicit ProgressPlay(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawValueLoad(QPainter *painter);
    void drawValuePlay(QPainter *painter);
    void drawBorder(QPainter *painter);

private:
    int valueAll;           //总大小
    int valuePlay;          //已播放大小
    int valueLoad;          //已缓存大小

    QColor colorPlay;       //已播放颜色
    QColor colorLoad;       //缓存颜色
    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色

    int radius;             //圆角角度
    bool autoRadius;        //自动圆角
    bool showProgressRadius;//显示进度圆角角度

    double borderWidth;     //边框宽度
    QColor borderColor;     //边框颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置总大小
    int getValueAll() const;
    void setValueAll(int valueAll);

    //获取和设置已播放大小
    int getValuePlay() const;
    void setValuePlay(int valuePlay);

    //获取和设置已加载大小
    int getValueLoad() const;
    void setValueLoad(int valueLoad);

    //获取和设置已播放颜色
    QColor getColorPlay() const;
    void setColorPlay(const QColor &colorPlay);

    //获取和设置已加载颜色
    QColor getColorLoad() const;
    void setColorLoad(const QColor &colorLoad);

    //获取和设置背景颜色+文字颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置圆角角度
    int getRadius() const;
    void setRadius(int radius);

    //获取和设置自动圆角
    bool getAutoRadius() const;
    void setAutoRadius(bool autoRadius);

    //获取和设置是否显示进度圆角角度
    bool getShowProgressRadius() const;
    void setShowProgressRadius(bool showProgressRadius);

    //获取和设置边框宽度
    double getBorderWidth() const;
    void setBorderWidth(double borderWidth);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);
};

#endif // PROGRESSPLAY_H
