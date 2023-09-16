#ifndef ADSWIDGETX_H
#define ADSWIDGETX_H

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
class Q_DECL_EXPORT AdsWidgetx : public QWidget
#else
class AdsWidgetx : public QWidget
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

    explicit AdsWidgetx(QWidget *parent = 0);
    ~AdsWidgetx();

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
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置鼠标悬停停止轮播
    bool getHoverStop() const;
    void setHoverStop(bool hoverStop);

    //获取和设置是否显示序号
    bool getShowNumber() const;
    void setShowNumber(bool showNumber);

    //获取和设置指示器高度
    int getMinHeight() const;
    void setMinHeight(int minHeight);

    //获取和设置最小拉伸宽度
    int getMinWidth() const;
    void setMinWidth(int minWidth);

    //获取和设置最大拉伸宽度
    int getMaxWidth() const;
    void setMaxWidth(int maxWidth);

    //获取和设置切换间隔
    int getInterval() const;
    void setInterval(int interval);

    //获取和设置指示器圆角角度
    int getNavRadius() const;
    void setNavRadius(int navRadius);

    //获取和设置指示器颜色
    QColor getNavColor() const;
    void setNavColor(const QColor &navColor);

    //获取和设置指示器文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置提示信息颜色
    QColor getTipColor() const;
    void setTipColor(const QColor &tipColor);

    //获取和设置加深颜色
    QColor getDarkColor() const;
    void setDarkColor(const QColor &darkColor);

    //获取和设置图片名称
    QString getImageNames() const;
    void setImageNames(const QString &imageNames);

    //获取和设置提示信息
    QString getImageTips() const;
    void setImageTips(const QString &imageTips);

    //获取和设置指示器位置
    NavPosition getNavPosition() const;
    void setNavPosition(const NavPosition &navPosition);

    //获取和设置指示器样式
    NavStyle getNavStyle() const;
    void setNavStyle(const NavStyle &navStyle);
};

#endif // ADSWIDGETX_H
