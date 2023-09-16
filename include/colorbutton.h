#ifndef COLORBUTTON_H
#define COLORBUTTON_H

/**
 * 多样式超级按钮控件 作者:feiyangqingyun(QQ:517216493) 2017-09-24
 * 1. 可设置圆角角度，边框宽度。
 * 2. 可设置角标和正文文字内容、字体、对齐方式、颜色。
 * 3. 可设置边框颜色，正常颜色，按下颜色。
 * 4. 可设置背景图片。
 * 5. 可设置按钮颜色模式。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ColorButton : public QWidget
#else
class ColorButton : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(ColorMode)
    Q_ENUMS(TextAlign)

    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

    Q_PROPERTY(bool showSuperText READ getShowSuperText WRITE setShowSuperText)
    Q_PROPERTY(QString superText READ getSuperText WRITE setSuperText)
    Q_PROPERTY(QFont superTextFont READ getSuperTextFont WRITE setSuperTextFont)
    Q_PROPERTY(TextAlign superTextAlign READ getSuperTextAlign WRITE setSuperTextAlign)
    Q_PROPERTY(QColor superTextColor READ getSuperTextColor WRITE setSuperTextColor)

    Q_PROPERTY(QString text READ getText WRITE setText)
    Q_PROPERTY(QFont textFont READ getTextFont WRITE setTextFont)
    Q_PROPERTY(TextAlign textAlign READ getTextAlign WRITE setTextAlign)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

    Q_PROPERTY(QColor normalColor READ getNormalColor WRITE setNormalColor)
    Q_PROPERTY(QColor pressedColor READ getPressedColor WRITE setPressedColor)

    Q_PROPERTY(bool canMove READ getCanMove WRITE setCanMove)
    Q_PROPERTY(QPixmap bgImage READ getBgImage WRITE setBgImage)
    Q_PROPERTY(ColorMode colorMode READ getColorMode WRITE setColorMode)

public:
    enum ColorMode {
        ColorMode_Normal = 0,       //松开按下两种颜色
        ColorMode_Replace = 1,      //按下松开颜色上下交替
        ColorMode_Shade = 2         //按下松开颜色渐变交替
    };

    enum TextAlign {
        TextAlign_Top_Left = 0,     //顶部左侧
        TextAlign_Top_Center = 1,   //顶部居中
        TextAlign_Top_Right = 2,    //顶部右侧
        TextAlign_Center_Left = 3,  //中间左侧
        TextAlign_Center_Center = 4,//中间居中
        TextAlign_Center_Right = 5, //中间右侧
        TextAlign_Bottom_Left = 6,  //底部左侧
        TextAlign_Bottom_Center = 7,//底部居中
        TextAlign_Bottom_Right = 8  //底部右侧
    };

    explicit ColorButton(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawText(QPainter *painter);

private:
    int borderRadius;           //圆角半径
    int borderWidth;            //边框宽度
    QColor borderColor;         //边框颜色

    bool showSuperText;         //显示角标
    QString superText;          //角标文字
    QFont superTextFont;        //角标文字字体
    TextAlign superTextAlign;   //角标文字对齐方式
    QColor superTextColor;      //角标文字颜色

    QString text;               //文字
    QFont textFont;             //文字字体
    TextAlign textAlign;        //文字对齐方式
    QColor textColor;           //文字颜色

    QColor normalColor;         //正常颜色
    QColor pressedColor;        //按下颜色

    bool canMove;               //是否能移动
    QPixmap bgImage;            //背景图片
    ColorMode colorMode;        //背景色模式

    bool isPressed;             //是否按下

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置边框圆角角度
    int getBorderRadius() const;
    void setBorderRadius(int borderRadius);

    //获取和设置边框宽度
    int getBorderWidth() const;
    void setBorderWidth(int borderWidth);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置是否显示角标
    bool getShowSuperText() const;
    void setShowSuperText(bool showSuperText);

    //获取和设置角标文字
    QString getSuperText() const;
    void setSuperText(const QString &superText);

    //获取和设置角标文字字体
    QFont getSuperTextFont() const;
    void setSuperTextFont(const QFont &superTextFont);

    //获取和设置角标文字对齐方式
    TextAlign getSuperTextAlign() const;
    void setSuperTextAlign(const TextAlign &superTextAlign);

    //获取和设置角标文字颜色
    QColor getSuperTextColor() const;
    void setSuperTextColor(const QColor &superTextColor);

    //获取和设置文字
    QString getText() const;
    void setText(const QString &text);

    //获取和设置文字字体
    QFont getTextFont() const;
    void setTextFont(const QFont &textFont);

    //获取和设置文字对齐方式
    TextAlign getTextAlign() const;
    void setTextAlign(const TextAlign &textAlign);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置正常颜色
    QColor getNormalColor() const;
    void setNormalColor(const QColor &normalColor);

    //获取和设置按下颜色
    QColor getPressedColor() const;
    void setPressedColor(const QColor &pressedColor);

    //获取和设置是否可以移动
    bool getCanMove() const;
    void setCanMove(bool canMove);

    //获取和设置背景图片
    QPixmap getBgImage() const;
    void setBgImage(const QPixmap &bgImage);

    //获取和设置颜色模式
    ColorMode getColorMode() const;
    void setColorMode(const ColorMode &colorMode);

Q_SIGNALS:
    void clicked();
};

#endif // COLORBUTTON_H
