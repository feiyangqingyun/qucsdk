#ifndef ROUNDMENU_H
#define ROUNDMENU_H

#include <QWidget>
#include <QPainterPath>
class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT RoundMenuButton : public QWidget
#else
class RoundMenuButton : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit RoundMenuButton(QWidget *parent);

protected:
    QPoint getPoint(const QPoint &pos);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private:
    QString menuText1;      //菜单文字1
    QString menuText2;      //菜单文字2

    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色

    int topHeight;          //菜单顶部高度
    bool topSelected;       //菜单顶部选中

    QPainterPath textPath1; //文字路径1
    QPainterPath textPath2; //文字路径2

    QPropertyAnimation *animation;

private slots:
    //动画值变化
    void valueChanged(const QVariant &value);

public Q_SLOTS:
    //获取和设置菜单文字1
    QString getMenuText1() const;
    void setMenuText1(const QString &menuText1);

    //获取和设置菜单文字2
    QString getMenuText2() const;
    void setMenuText2(const QString &menuText2);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置菜单顶部是否选中
    bool getTopSelected() const;
    void setTopSelected(bool topSelected);

Q_SIGNALS:
    //菜单按钮单击切换
    void btnClicked(bool topSelected);
};

#ifdef quc
class Q_DECL_EXPORT RoundMenuItem : public QWidget
#else
class RoundMenuItem : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit RoundMenuItem(QWidget *parent);

protected:
    QPoint getPoint(const QPoint &pos);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private:
    int offset;         //偏移值
    int index;          //菜单索引
    qreal opacity;      //透明度
    QString icon;       //图标路径
    QPainterPath path;  //菜单路径

public:
    //获取和设置菜单索引(用于信号发送作为唯一标识)
    int getIndex() const;
    void setIndex(int index);

    //设置透明度
    void setOpacity(qreal opacity);
    //设置图标路径
    void setIcon(const QString &icon);

Q_SIGNALS:
    //单击信号
    void btnClicked(int index);
};

/**
 * 环绕菜单控件 作者:雨田哥(QQ:3246214072) 整理:feiyangqingyun(QQ:517216493) 2023-8-29
 * 1. 可设置环绕子菜单图标集合。
 * 2. 可设置主菜单文字。
 * 3. 可设置主菜单背景颜色。
 * 4. 可设置主菜单文字颜色。
 * 5. 可设置主菜单顶部是否选中。
 */

#ifdef quc
class Q_DECL_EXPORT RoundMenu : public QWidget
#else
class RoundMenu : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(QString icons READ getIcons WRITE setIcons)
    Q_PROPERTY(QString menuText1 READ getMenuText1 WRITE setMenuText1)
    Q_PROPERTY(QString menuText2 READ getMenuText2 WRITE setMenuText2)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(bool topSelected READ getTopSelected WRITE setTopSelected)

public:
    explicit RoundMenu(QWidget *parent);

protected:
    void resizeEvent(QResizeEvent *);

private:
    qreal opacity;      //透明度
    QRect posRect;      //坐标区域
    QString icons;      //子菜单图标集合

    //中间菜单按钮
    RoundMenuButton *menuBtn;
    //环绕子菜单集合
    QList<RoundMenuItem *> menuItems;

    //透明动画和移动动画
    QPropertyAnimation *opaAnimation;
    QPropertyAnimation *posAnimation;

    //加载子菜单
    void initMenuItem();

private slots:
    //主菜单单击切换
    void btnClicked(bool topSelected);
    //透明度动画
    void opaValueChanged(const QVariant &value);
    //移动坐标动画
    void posValueChanged(const QVariant &value);

public:
    //获取和设置子菜单图标
    QString getIcons() const;
    void setIcons(const QString &icons);

    //获取和设置菜单文字1
    QString getMenuText1() const;
    void setMenuText1(const QString &menuText1);

    //获取和设置菜单文字2
    QString getMenuText2() const;
    void setMenuText2(const QString &menuText2);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置菜单顶部是否选中
    bool getTopSelected() const;
    void setTopSelected(bool topSelected);

    //设置默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

Q_SIGNALS:
    //子菜单单击信号
    void btnClicked(int index);
};

#endif // ROUNDMENU_H
