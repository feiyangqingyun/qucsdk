#ifndef SLIDERTIP_H
#define SLIDERTIP_H

/**
 * 气泡提示滑块条 作者:feiyangqingyun(QQ:517216493) 2017-12-15
 * 1. 可设置气泡跟随提示。
 * 2. 可设置气泡的圆角角度、箭头大小、背景色、前景色、箭头方向。
 * 3. 可设置是否单击切换到当前。
 * 4. 可设置气泡宽度、高度、字体。
 * 5. 可设置是否换算成时间显示。
 * 6. 支持横向和纵向。
 */

#include <QSlider>

class NavLabel;

#ifdef quc
class Q_DECL_EXPORT SliderTip : public QSlider
#else
class SliderTip : public QSlider
#endif

{
    Q_OBJECT
    Q_ENUMS(ArrowStyle)

    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(int arrowSize READ getArrowSize WRITE setArrowSize)
    Q_PROPERTY(ArrowStyle arrowStyle READ getArrowStyle WRITE setArrowStyle)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground)
    Q_PROPERTY(QColor foreground READ getForeground WRITE setForeground)

    Q_PROPERTY(int labTipWidth READ getLabTipWidth WRITE setLabTipWidth)
    Q_PROPERTY(int labTipHeight READ getLabTipHeight WRITE setLabTipHeight)
    Q_PROPERTY(QFont labTipFont READ getLabTipFont WRITE setLabTipFont)

    Q_PROPERTY(bool showTime READ getShowTime WRITE setShowTime)
    Q_PROPERTY(bool clickEnable READ getClickEnable WRITE setClickEnable)
    Q_PROPERTY(QString unit READ getUnit WRITE setUnit)

public:
    enum ArrowStyle {
        ArrowStyle_Left = 0,    //向左箭头
        ArrowStyle_Right = 1,   //向右箭头
        ArrowStyle_Top = 2,     //向上箭头
        ArrowStyle_Bottom = 3   //向下箭头
    };

    explicit SliderTip(QWidget *parent = 0);
    ~SliderTip();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    int borderRadius;       //边框圆角角度
    int arrowSize;          //箭头大小
    ArrowStyle arrowStyle;  //箭头样式

    QColor background;      //背景色
    QColor foreground;      //前景色

    int labTipWidth;        //气泡提示宽度
    int labTipHeight;       //气泡提示高度
    QFont labTipFont;       //气泡提示字体

    bool showTime;          //是否显示时间
    bool clickEnable;       //是否单击切换到当前
    QString unit;           //单位

    NavLabel *labTip;       //气泡提示标签

public:
    //获取和设置边框圆角角度
    int getBorderRadius() const;
    void setBorderRadius(int borderRadius);

    //获取和设置箭头大小
    int getArrowSize() const;
    void setArrowSize(int arrowSize);

    //获取和设置箭头样式
    ArrowStyle getArrowStyle() const;
    void setArrowStyle(const ArrowStyle &arrowStyle);

    //获取和设置前景色
    QColor getBackground() const;
    void setBackground(const QColor &background);

    //获取和设置前景色
    QColor getForeground() const;
    void setForeground(const QColor &foreground);

    //获取和设置气泡提示宽度
    int getLabTipWidth() const;
    void setLabTipWidth(int labTipWidth);

    //获取和设置气泡提示高度
    int getLabTipHeight() const;
    void setLabTipHeight(int labTipHeight);

    //获取和设置气泡提示字体
    QFont getLabTipFont() const;
    void setLabTipFont(const QFont &labTipFont);

    //获取和设置显示时间
    bool getShowTime() const;
    void setShowTime(bool showTime);

    //获取和设置是否单击切换到当前
    bool getClickEnable() const;
    void setClickEnable(bool clickEnable);

    //获取和设置单位字符
    QString getUnit() const;
    void setUnit(const QString &unit);

Q_SIGNALS:
    void clicked();
};

#endif // SLIDERTIP_H
