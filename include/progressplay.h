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
 * 9. 精准计算圆角角度，解决了QSS中border-radius当进度小于圆角角度出现方形的BUG。
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
    int valueAll;               //总大小
    int valuePlay;              //已播放大小
    int valueLoad;              //已缓存大小

    QColor colorPlay;           //已播放颜色
    QColor colorLoad;           //缓存颜色
    QColor bgColor;             //背景颜色
    QColor textColor;           //文字颜色

    int radius;                 //圆角角度
    bool autoRadius;            //自动圆角
    bool showProgressRadius;    //显示进度圆角角度

    double borderWidth;         //边框宽度
    QColor borderColor;         //边框颜色

public:
    int getValueAll()           const;
    int getValuePlay()          const;
    int getValueLoad()          const;

    QColor getColorPlay()       const;
    QColor getColorLoad()       const;
    QColor getBgColor()         const;
    QColor getTextColor()       const;

    int getRadius()             const;
    bool getAutoRadius()        const;
    bool getShowProgressRadius()const;

    double getBorderWidth()     const;
    QColor getBorderColor()     const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置 总大小+缓存大小+已播放 值
    void setValueAll(int valueAll);
    void setValuePlay(int valuePlay);
    void setValueLoad(int valueLoad);

    //设置 缓存大小+已播放 颜色
    void setColorPlay(const QColor &colorPlay);
    void setColorLoad(const QColor &colorLoad);

    //设置背景颜色+文字颜色
    void setBgColor(const QColor &bgColor);
    void setTextColor(const QColor &textColor);

    //设置圆角+自动圆角+是否显示进度圆角角度
    void setRadius(int radius);
    void setAutoRadius(bool autoRadius);
    void setShowProgressRadius(bool showProgressRadius);

    //设置边框宽度+颜色
    void setBorderWidth(double borderWidth);
    void setBorderColor(const QColor &borderColor);
};

#endif // PROGRESSPLAY_H
