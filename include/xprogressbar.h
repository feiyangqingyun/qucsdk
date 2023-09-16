#ifndef XPROGRESSBAR_H
#define XPROGRESSBAR_H

/**
 * 自定义进度条控件 作者:feiyangqingyun(QQ:517216493) 2019-04-30
 * 1. 可设置背景颜色。
 * 2. 可设置进度颜色。
 * 3. 可设置圆角角度。
 * 4. 可设置进度是否圆角。
 * 5. 可设置是否自动圆角。
 * 6. 可设置渐变颜色进度。
 * 7. 精准计算圆角角度，解决了QSS中border-radius当进度小于圆角角度出现方形的bug。
 */

#include <QProgressBar>

#ifdef quc
class Q_DECL_EXPORT XProgressBar : public QProgressBar
#else
class XProgressBar : public QProgressBar
#endif

{
    Q_OBJECT

    Q_PROPERTY(QBrush valueBrush READ getValueBrush WRITE setValueBrush)
    Q_PROPERTY(QColor valueColor READ getValueColor WRITE setValueColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(int radius READ getRadius WRITE setRadius)
    Q_PROPERTY(bool autoRadius READ getAutoRadius WRITE setAutoRadius)
    Q_PROPERTY(bool showProgressRadius READ getShowProgressRadius WRITE setShowProgressRadius)

    Q_PROPERTY(double borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

public:
    explicit XProgressBar(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawBorder(QPainter *painter);

private:
    QBrush valueBrush;          //进度画刷
    QColor valueColor;          //进度颜色
    QColor bgColor;             //背景颜色
    QColor textColor;           //文字颜色

    int radius;                 //圆角角度
    bool autoRadius;            //自动圆角
    bool showProgressRadius;    //显示进度圆角角度

    double borderWidth;         //边框宽度
    QColor borderColor;         //边框颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置进度画刷
    QBrush getValueBrush() const;
    void setValueBrush(const QBrush &valueBrush);

    //获取和设置进度颜色
    QColor getValueColor() const;
    void setValueColor(const QColor &valueColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文字颜色
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

#endif // XPROGRESSBAR_H
