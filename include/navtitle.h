#ifndef NAVTITLE_H
#define NAVTITLE_H

/**
 * 导航标题栏控件 作者:feiyangqingyun(QQ:517216493) 2019-03-28
 * 1. 可设置标题文字。
 * 2. 可设置左侧图标和右侧五个图标。
 * 3. 可设置图标的正常颜色、悬停颜色、按下颜色。
 * 4. 可识别各图标按下信号、松开信号，用索引标识。
 * 5. 可以自行拓展图标大小。
 * 6. 可设置标题是否居中。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT NavTitle : public QWidget
#else
class NavTitle : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int leftIcon READ getLeftIcon WRITE setLeftIcon)
    Q_PROPERTY(int rightIcon1 READ getRightIcon1 WRITE setRightIcon1)
    Q_PROPERTY(int rightIcon2 READ getRightIcon2 WRITE setRightIcon2)
    Q_PROPERTY(int rightIcon3 READ getRightIcon3 WRITE setRightIcon3)
    Q_PROPERTY(int rightIcon4 READ getRightIcon4 WRITE setRightIcon4)
    Q_PROPERTY(int rightIcon5 READ getRightIcon5 WRITE setRightIcon5)

    Q_PROPERTY(int padding READ getPadding WRITE setPadding)
    Q_PROPERTY(int iconSize READ getIconSize WRITE setIconSize)
    Q_PROPERTY(bool textCenter READ getTextCenter WRITE setTextCenter)
    Q_PROPERTY(QString text READ getText WRITE setText)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

    Q_PROPERTY(QColor iconNormalColor READ getIconNormalColor WRITE setIconNormalColor)
    Q_PROPERTY(QColor iconHoverColor READ getIconHoverColor WRITE setIconHoverColor)
    Q_PROPERTY(QColor iconPressColor READ getIconPressColor WRITE setIconPressColor)

public:
    explicit NavTitle(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawIcon(QPainter *painter, const QRect &rect, int icon);

private:
    int leftIcon;               //左侧图标
    int rightIcon1;             //右侧图标1
    int rightIcon2;             //右侧图标2
    int rightIcon3;             //右侧图标3
    int rightIcon4;             //右侧图标4
    int rightIcon5;             //右侧图标5

    int padding;                //左侧右侧间距
    int iconSize;               //图标大小
    bool textCenter;            //文字居中
    QString text;               //标题文字

    QColor bgColor;             //背景颜色
    QColor textColor;           //文本颜色
    QColor borderColor;         //边框颜色

    QColor iconNormalColor;     //图标正常颜色
    QColor iconHoverColor;      //图标悬停颜色
    QColor iconPressColor;      //图标按下颜色

    bool pressed;               //鼠标是否按下
    QPoint lastPoint;           //鼠标按下处的坐标

    QFont iconFont;             //图形字体
    QRect leftRect;             //左侧图标区域
    QRect rightRect1;           //右侧图标1区域
    QRect rightRect2;           //右侧图标2区域
    QRect rightRect3;           //右侧图标3区域
    QRect rightRect4;           //右侧图标4区域
    QRect rightRect5;           //右侧图标5区域

public:
    int getLeftIcon()           const;
    int getRightIcon1()         const;
    int getRightIcon2()         const;
    int getRightIcon3()         const;
    int getRightIcon4()         const;
    int getRightIcon5()         const;

    int getPadding()            const;
    int getIconSize()           const;
    bool getTextCenter()        const;
    QString getText()           const;

    QColor getBgColor()         const;
    QColor getTextColor()       const;
    QColor getBorderColor()     const;

    QColor getIconNormalColor() const;
    QColor getIconHoverColor()  const;
    QColor getIconPressColor()  const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置左侧图标
    void setLeftIcon(int leftIcon);
    //设置右侧多个图标
    void setRightIcon1(int rightIcon1);
    void setRightIcon2(int rightIcon2);
    void setRightIcon3(int rightIcon3);
    void setRightIcon4(int rightIcon4);
    void setRightIcon5(int rightIcon5);

    //设置间隔
    void setPadding(int padding);
    //设置图标大小
    void setIconSize(int iconSize);
    //设置文字是否居中
    void setTextCenter(bool textCenter);
    //设置标题
    void setText(const QString &text);

    //设置背景颜色
    void setBgColor(const QColor &bgColor);
    //设置文字颜色
    void setTextColor(const QColor &textColor);
    //设置边框颜色
    void setBorderColor(const QColor &borderColor);

    //设置图标正常颜色
    void setIconNormalColor(const QColor &iconNormalColor);
    //设置图标悬停颜色
    void setIconHoverColor(const QColor &iconHoverColor);
    //设置图标按下颜色
    void setIconPressColor(const QColor &iconPressColor);

Q_SIGNALS:
    //鼠标单击对应图标发出信号
    //index 1-左侧图标 2-右侧图标1 3-右侧图标2 ...
    void mousePressed(int index);
    void mouseReleased(int index);
};

#endif // NAVTITLE_H
