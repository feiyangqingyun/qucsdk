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
 * 6. 精准计算圆角角度，解决了QSS中border-radius当进度小于圆角角度出现方形的BUG。
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
    QBrush getValueBrush()      const;
    QColor getValueColor()      const;
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
    //设置进度画刷+进度颜色+背景颜色+文字颜色
    void setValueBrush(const QBrush &valueBrush);
    void setValueColor(const QColor &valueColor);
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

#endif // XPROGRESSBAR_H
