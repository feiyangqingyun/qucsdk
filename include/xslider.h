#ifndef XSLIDER_H
#define XSLIDER_H

/**
 * 滑动条控件 作者:feiyangqingyun(QQ:517216493) 2019-01-16
 * 1. 可设置高度。
 * 2. 可设置正常颜色。
 * 3. 可设置滑过的颜色。
 * 4. 可设置手柄边框颜色。
 * 5. 可设置手柄颜色。
 * 6. 可设置文字颜色。
 * 7. 单击自动切换到按下处位置。
 * 8. 对应值显示在手柄圆圈处。
 */

#include <QSlider>

#ifdef quc
class Q_DECL_EXPORT XSlider : public QSlider
#else
class XSlider : public QSlider
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool showText READ getShowText WRITE setShowText)
    Q_PROPERTY(int sliderHeight READ getSliderHeight WRITE setSliderHeight)
    Q_PROPERTY(QColor normalColor READ getNormalColor WRITE setNormalColor)
    Q_PROPERTY(QColor grooveColor READ getGrooveColor WRITE setGrooveColor)
    Q_PROPERTY(QColor handleBorderColor READ getHandleBorderColor WRITE setHandleBorderColor)
    Q_PROPERTY(QColor handleColor READ getHandleColor WRITE setHandleColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit XSlider(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    bool showText;                  //显示值
    int sliderHeight;               //滑动条高度

    QColor normalColor;             //正常颜色
    QColor grooveColor;             //滑过的颜色
    QColor handleBorderColor;       //手柄边框颜色
    QColor handleColor;             //手柄颜色
    QColor textColor;               //文字颜色

private slots:
    void initForm();
    void initStyle();

public:
    bool getShowText()              const;
    int getSliderHeight()           const;

    QColor getNormalColor()         const;
    QColor getGrooveColor()         const;
    QColor getHandleBorderColor()   const;
    QColor getHandleColor()         const;
    QColor getTextColor()           const;

public Q_SLOTS:
    //设置是否显示值
    void setShowText(bool showText);
    //设置滑动条高度
    void setSliderHeight(int sliderHeight);

    //设置正常颜色
    void setNormalColor(const QColor &normalColor);
    //设置滑过的颜色
    void setGrooveColor(const QColor &grooveColor);
    //设置手柄边框颜色
    void setHandleBorderColor(const QColor &handleBorderColor);
    //设置手柄颜色
    void setHandleColor(const QColor &handleColor);
    //设置文字颜色
    void setTextColor(const QColor &textColor);

Q_SIGNALS:
    void clicked();
};

#endif // XSLIDER_H
