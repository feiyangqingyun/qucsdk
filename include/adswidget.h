#ifndef ADSWIDGET_H
#define ADSWIDGET_H

/**
 * 广告轮播控件 作者:feiyangqingyun(QQ:517216493) 2016-12-22
 * 1. 可设置显示的图像。
 * 2. 可添加多个广告。
 * 3. 可设置指示器样式 迷你型样式、数字型样式。
 * 4. 可设置指示器大小。
 * 5. 可设置切换间隔。
 */

#include <QWidget>

class QLabel;

#ifdef quc
class Q_DECL_EXPORT AdsWidget : public QWidget
#else
class AdsWidget : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(BannerStyle)

    Q_PROPERTY(int interval READ getInterval WRITE setInterval)
    Q_PROPERTY(QSize bannerFixedSize READ getBannerFixedSize WRITE setBannerFixedSize)
    Q_PROPERTY(QString imageNames READ getImageNames WRITE setImageNames)
    Q_PROPERTY(BannerStyle bannerStyle READ getBannerStyle WRITE setBannerStyle)

public:
    enum BannerStyle {
        BannerStyle_Min = 0,    //迷你型样式
        BannerStyle_Num = 1     //数字型样式
    };

    explicit AdsWidget(QWidget *parent = 0);
    ~AdsWidget();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    int interval;               //自动切换间隔
    QSize bannerFixedSize;      //导航指示器固定尺寸
    BannerStyle bannerStyle;    //导航指示器样式
    QString imageNames;         //导航图片集合字符串

    int currentIndex;           //当前显示的广告对应索引
    QTimer *timer;              //定时器轮播广告
    QList<QLabel *> labs;       //导航标签链表
    QList<QString> names;       //导航图片链表

    QWidget *widgetBg;          //存放广告图片的容器
    QWidget *widgetBanner;      //存放导航指示器的容器

private slots:
    void initWidget();
    void initForm();
    void changedAds();
    void changedAds(QLabel *lab);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置切换间隔
    int getInterval() const;
    void setInterval(int interval);

    //获取和设置导航指示器固定尺寸
    QSize getBannerFixedSize() const;
    void setBannerFixedSize(const QSize &bannerFixedSize);

    //获取和设置导航指示器样式
    BannerStyle getBannerStyle() const;
    void setBannerStyle(const BannerStyle &bannerStyle);

    //获取和设置图片路径集合
    QString getImageNames() const;
    void setImageNames(const QString &imageNames);
};

#endif // ADSWIDGET_H
