#ifndef ADSWIDGET2_H
#define ADSWIDGET2_H

/**
 * 图片轮播控件 作者:feiyangqingyun(QQ:517216493) 2018-09-12
 * 参考雨田哥(QQ:3246214072) https://blog.csdn.net/ly305750665/article/details/82496046
 * 1. 可设置图片路径集合。
 * 2. 可设置提示信息集合。
 * 3. 可设置指示器最小宽度和最大宽度。
 * 4. 可设置图片切换间隔。
 * 5. 可设置指示器颜色和提示文字颜色。
 * 6. 可设置指示器高度。
 * 7. 可设置指示器显示序号。
 * 8. 可设置指示器位置 左边、中间、右边。
 * 9. 可设置指示器的样式 椭圆条状、圆形、矩形、小圆点、长条状。
 * 10. 可设置鼠标悬停停止轮播。
 */

#include <QWidget>

class QLabel;
class QHBoxLayout;
class QSpacerItem;
class QParallelAnimationGroup;
class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT AdsWidget2 : public QWidget
#else
class AdsWidget2 : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(NavPosition)
    Q_ENUMS(NavStyle)

    Q_PROPERTY(bool hoverStop READ getHoverStop WRITE setHoverStop)
    Q_PROPERTY(bool showNumber READ getShowNumber WRITE setShowNumber)

    Q_PROPERTY(int minHeight READ getMinHeight WRITE setMinHeight)
    Q_PROPERTY(int minWidth READ getMinWidth WRITE setMinWidth)
    Q_PROPERTY(int maxWidth READ getMaxWidth WRITE setMaxWidth)
    Q_PROPERTY(int interval READ getInterval WRITE setInterval)
    Q_PROPERTY(int navRadius READ getNavRadius WRITE setNavRadius)

    Q_PROPERTY(QColor navColor READ getNavColor WRITE setNavColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor tipColor READ getTipColor WRITE setTipColor)
    Q_PROPERTY(QColor darkColor READ getDarkColor WRITE setDarkColor)

    Q_PROPERTY(QString imageNames READ getImageNames WRITE setImageNames)
    Q_PROPERTY(QString imageTips READ getImageTips WRITE setImageTips)

    Q_PROPERTY(NavPosition navPosition READ getNavPosition WRITE setNavPosition)
    Q_PROPERTY(NavStyle navStyle READ getNavStyle WRITE setNavStyle)

public:
    enum NavPosition {
        NavPosition_Left = 0,   //左边位置
        NavPosition_Center = 1, //中间位置
        NavPosition_Right = 2   //右侧位置
    };

    enum NavStyle {
        NavStyle_Ellipse = 0,   //椭圆条状
        NavStyle_Circle = 1,    //圆形
        NavStyle_Rect = 2,      //矩形
        NavStyle_Dot = 3,       //小圆点
        NavStyle_LongRect = 4   //长条状
    };

    explicit AdsWidget2(QWidget *parent = 0);
    ~AdsWidget2();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void showEvent(QShowEvent *);
    void paintEvent(QPaintEvent *);

private:
    bool hoverStop;             //鼠标悬停停止轮播
    bool showNumber;            //是否显示序号

    int minHeight;              //指示器最小高度
    int minWidth;               //指示器最小拉伸宽度
    int maxWidth;               //指示器最大拉伸宽度
    int interval;               //图片切换间隔,单位毫秒
    int navRadius;              //指示器圆角角度

    QColor navColor;            //指示器颜色
    QColor textColor;           //指示器文字颜色
    QColor tipColor;            //提示文字颜色
    QColor darkColor;           //当前指示器加深颜色

    QString imageNames;         //图片名称
    QString imageTips;          //提示信息

    NavPosition navPosition;    //指示器位置
    NavStyle navStyle;          //指示器样式

    QList<QString> names;       //图片名称集合
    QList<QString> tips;        //提示信息集合
    QList<QLabel *> labs;       //存储指示器集合

    bool leftToRight;           //从左往右切换
    int offset;                 //图片切换偏移量
    int currentIndex;           //当前图片索引
    int previousIndex;          //上一张图片索引

    QString qssNormal;          //正常状态样式
    QString qssCurrent;         //当前状态样式

    QTimer *timer;              //定时器切换
    QHBoxLayout *layout;        //指示器所在布局
    QSpacerItem *spacerLeft;    //左侧弹簧
    QSpacerItem *spacerRight;   //右侧弹簧
    QWidget *widgetNav;         //存放导航指示器的容器

    //动画切换
    QParallelAnimationGroup *animationGroup;
    QPropertyAnimation *animationImage;
    QPropertyAnimation *animationMin;
    QPropertyAnimation *animationMax;

private slots:
    void initWidget();
    void initForm();
    void initQss();
    void changedAds();
    void changedAds(QLabel *lab);
    void changedImage(const QVariant &);
    void changedMin(const QVariant &);
    void changedMax(const QVariant &);

public:
    bool getHoverStop()         const;
    bool getShowNumber()        const;

    int getMinHeight()          const;
    int getMinWidth()           const;
    int getMaxWidth()           const;
    int getInterval()           const;
    int getNavRadius()          const;

    QColor getNavColor()        const;
    QColor getTextColor()       const;
    QColor getTipColor()        const;
    QColor getDarkColor()       const;

    QString getImageNames()     const;
    QString getImageTips()      const;

    NavPosition getNavPosition()const;
    NavStyle getNavStyle()      const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置鼠标悬停停止轮播
    void setHoverStop(bool hoverStop);
    //设置是否显示序号
    void setShowNumber(bool showNumber);

    //设置指示器高度
    void setMinHeight(int minHeight);
    //设置最小拉伸宽度
    void setMinWidth(int minWidth);
    //设置最大拉伸宽度
    void setMaxWidth(int maxWidth);
    //设置切换间隔
    void setInterval(int interval);
    //设置指示器圆角角度
    void setNavRadius(int navRadius);

    //设置指示器颜色
    void setNavColor(const QColor &navColor);
    //设置指示器文字颜色
    void setTextColor(const QColor &textColor);
    //设置提示信息颜色
    void setTipColor(const QColor &tipColor);
    //设置加深颜色
    void setDarkColor(const QColor &darkColor);

    //设置图片名称
    void setImageNames(const QString &imageNames);
    //设置提示信息
    void setImageTips(const QString &imageTips);

    //设置指示器位置
    void setNavPosition(const NavPosition &navPosition);
    //设置指示器样式
    void setNavStyle(const NavStyle &navStyle);
};

#endif // ADSWIDGET2_H
