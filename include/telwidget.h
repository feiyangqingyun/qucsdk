#ifndef TELWIDGET_H
#define TELWIDGET_H

/**
 * 通讯录控件 作者:feiyangqingyun(QQ:517216493) 2018-09-30
 * 1. 可设置信息集合(图标、姓名、类型、电话)以及添加单个联系人。
 * 2. 可设置背景图片、背景颜色。
 * 3. 可设置右侧导航字母的列表、默认颜色、高亮颜色。
 * 4. 可设置联系人按钮姓名颜色、+姓名字体。
 * 5. 可设置联系人按钮类型颜色、姓名字体。
 * 6. 可设置联系人按钮选中背景颜色。
 * 7. 可设置字母导航的风格(背景颜色、线条)。
 * 8. 可设置字母导航的颜色、字体大小。
 * 9. 可设置各种边距、联系人列数、元素间隔等。
 * 10. 支持悬浮滚动条，可设置悬停时间。
 * 11. 可设置悬浮滚动条的正常颜色、高亮颜色。
 * 12. 支持滑动，可设置滑动的步长速度。
 * 13. 支持单击右侧字母导航定位、文本突出显示。
 * 14. 单击发出当前联系人的姓名、类型、电话等信息。
 * 15. 根据汉字字母排序从小到大排列联系人，自带汉字转拼音功能。
 */

#include <QWidget>
#include <QDateTime>
#include <QScrollBar>

class QPropertyAnimation;
class QScrollArea;
class QScrollBar;
class QVBoxLayout;
class QGridLayout;
class QFrame;
class QLabel;
class QSpacerItem;

//字母高亮背景类
#ifdef quc
class Q_DECL_EXPORT TelHigh : public QWidget
#else
class TelHigh : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TelHigh(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    int fontSize;           //字体大小
    QPixmap bgImage;        //背景图片
    QColor bgColor;         //背景颜色
    QString text;           //显示的文字
    QColor textColor;       //文字颜色

public:
    //获取和设置字体大小
    int getFontSize() const;
    void setFontSize(int fontSize);

    //获取和设置背景图片
    QPixmap getBgImage() const;
    void setBgImage(const QPixmap &bgImage);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置显示的文字
    QString getText() const;
    void setText(const QString &text);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);
};

//中间字母分隔类
#ifdef quc
class Q_DECL_EXPORT TelBanner : public QWidget
#else
class TelBanner : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TelBanner(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    bool line;              //绘制线条
    int padding;            //离左侧距离
    int fontSize;           //字体大小
    QString text;           //文字标识

    QColor textColor;       //字体颜色
    QColor bgColor;         //背景颜色
    QColor lineColor;       //线条颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置是否绘制线条
    bool getLine() const;
    void setLine(bool line);

    //获取和设置左侧距离
    int getPadding() const;
    void setPadding(int padding);

    //获取和设置字体大小
    int getFontSize() const;
    void setFontSize(int fontSize);

    //获取和设置要绘制的文字
    QString getText() const;
    void setText(const QString &text);

    //获取和设置字体颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);
};

//右侧字母导航类
#ifdef quc
class Q_DECL_EXPORT TelLetter : public QWidget
#else
class TelLetter : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TelLetter(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private:
    QString letters;        //字母集合
    QString highLetter;     //高亮字母

    QColor normalColor;     //正常文字颜色
    QColor highColor;       //高亮文字颜色

    bool pressed;           //鼠标按下
    void checkPos(const QPoint &pos);

public:
    //获取和设置字母集合
    QString getLetters() const;
    void setLetters(const QString &letters);

    //获取和设置高亮字母
    QString getHighLetter() const;
    void setHighLetter(const QString &highLetter);

    //获取和设置正常文字颜色
    QColor getNormalColor() const;
    void setNormalColor(const QColor &normalColor);

    //获取和设置高亮文字颜色
    QColor getHighColor() const;
    void setHighColor(const QColor &highColor);

Q_SIGNALS:
    void letterClicked(const QString &letter, int letterY);
};

//通讯录按钮类
#ifdef quc
class Q_DECL_EXPORT TelButton : public QWidget
#else
class TelButton : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TelButton(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private:
    bool pixVisible;        //图标可见
    int padding;            //左侧图标离左边的距离
    int space;              //图标与右侧文字之间的间隔

    QPixmap pixmap;         //左侧小图标
    QString name;           //姓名
    QString type;           //类型
    QString tel;            //电话

    QColor bgColor;         //背景颜色
    QColor nameColor;       //姓名颜色
    QColor typeColor;       //类型颜色

    bool pressed;           //鼠标是否按下
    QPoint lastPos;         //按下坐标

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置图标可见
    bool getPixVisible() const;
    void setPixVisible(bool pixVisible);

    //获取和设置左侧间隔
    int getPadding() const;
    void setPadding(int padding);

    //获取和设置文字间隔
    int getSpace() const;
    void setSpace(int space);

    //获取和设置小图标
    QPixmap getPixmap() const;
    void setPixmap(const QPixmap &pixmap);

    //获取和设置姓名
    QString getName() const;
    void setName(const QString &name);

    //获取和设置类型
    QString getType() const;
    void setType(const QString &type);

    //获取和设置电话
    QString getTel() const;
    void setTel(const QString &tel);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置姓名颜色
    QColor getNameColor() const;
    void setNameColor(const QColor &nameColor);

    //获取和设置类型颜色
    QColor getTypeColor() const;
    void setTypeColor(const QColor &typeColor);

Q_SIGNALS:
    void btnPressed();
    void btnRelease();
};


//自定义滚动条类
class ScrollBar : public QScrollBar
{
    Q_OBJECT
public:
    explicit ScrollBar(QWidget *parent = 0);
    int getSliderHeight();
};


//通讯录面板类
#ifdef quc
class Q_DECL_EXPORT TelPanel : public QWidget
#else
class TelPanel : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit TelPanel(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void resizeEvent(QResizeEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    int step;                       //移动的步长
    int margin;                     //边距
    int space;                      //设备之间的间隔
    bool autoWidth;                 //宽度自动拉伸
    bool autoHeight;                //高度自动拉伸

    QColor normalColor;             //滚动条正常颜色
    QColor highColor;               //滚动条高亮颜色

    int columnCount;                //面板列数
    QList<QWidget *> items;         //元素窗体集合
    QList<int> indexs;              //分割窗体位置索引
    QList<QWidget *> banners;       //分割窗体集合

    QPropertyAnimation *animation;  //动画滑动
    QScrollArea *scrollArea;        //滚动区域
    QScrollBar *scrollBar;          //滚动条
    QWidget *widget;                //滚动区域载体,自动变宽变高
    QGridLayout *gridLayout;        //表格布局
    QSpacerItem *hSpacer;           //横向弹簧
    QSpacerItem *vSpacer;           //垂直弹簧

    bool movetop;                   //是否上滑
    bool pressed;                   //鼠标按下
    int pressedY;                   //鼠标按下处Y轴坐标
    QPoint pressedPos;              //鼠标按下处坐标
    QDateTime pressedTime;          //鼠标按下时间
    QTimer *timer;                  //定时器控制滚动条隐藏

private slots:
    void initControl();             //初始化控件
    void initForm();                //初始化窗体
    void initBar();                 //初始化滚动条
    void checkBar();                //处理滚动条隐藏
    void setRange(int min, int max);//设置滚动条范围值

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置每次滚动条移动的步长
    int getStep() const;
    void setStep(int step);

    //获取和设置四个方位边距
    void setMargin(int left, int top, int right, int bottom);
    int getMargin() const;
    void setMargin(int margin);

    //获取和设置元素间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置是否自动宽度
    bool getAutoWidth() const;
    void setAutoWidth(bool autoWidth);

    //获取和设置是否自动高度
    bool getAutoHeight() const;
    void setAutoHeight(bool autoHeight);

    //获取和设置滚动条正常颜色
    QColor getNormalColor() const;
    void setNormalColor(const QColor &normalColor);

    //获取和设置滚动条高亮颜色
    QColor getHighColor() const;
    void setHighColor(const QColor &highColor);

    //获取和设置滚动条位置
    int getPosition() const;
    void setPosition(int value);

    //获取和设置分割窗体
    int getColumnCount() const;
    void setColumnCount(int columnCount);

    //获取和设置索引位置
    QList<int> getIndexs() const;
    void setIndexs(const QList<int> indexs);

    //获取和设置元素集合
    QList<QWidget *> getItems() const;
    void setItems(QList<QWidget *> items);

    //获取和设置顶部集合
    QList<QWidget *> getBanners() const;
    void setBanners(QList<QWidget *> banners);

Q_SIGNALS:
    void positionChanged(int value);
};


#ifdef quc
class Q_DECL_EXPORT TelWidget : public QWidget
#else
class TelWidget : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QString names READ getNames WRITE setNames)
    Q_PROPERTY(QString types READ getTypes WRITE setTypes)
    Q_PROPERTY(QString tels READ getTels WRITE setTels)

    Q_PROPERTY(QPixmap bgImage READ getBgImage WRITE setBgImage)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

    Q_PROPERTY(int telHighFontSize READ getTelHighFontSize WRITE setTelHighFontSize)
    Q_PROPERTY(QPixmap telHighBgImage READ getTelHighBgImage WRITE setTelHighBgImage)
    Q_PROPERTY(QColor telHighBgColor READ getTelHighBgColor WRITE setTelHighBgColor)
    Q_PROPERTY(QColor telHighTextColor READ getTelHighTextColor WRITE setTelHighTextColor)

    Q_PROPERTY(QColor telBannerBgColor READ getTelBannerBgColor WRITE setTelBannerBgColor)
    Q_PROPERTY(QColor telBannerTextColor READ getTelBannerTextColor WRITE setTelBannerTextColor)
    Q_PROPERTY(QColor telBannerLineColor READ getTelBannerLineColor WRITE setTelBannerLineColor)

    Q_PROPERTY(QColor telLetterNormalColor READ getTelLetterNormalColor WRITE setTelLetterNormalColor)
    Q_PROPERTY(QColor telLetterHighColor READ getTelLetterHighColor WRITE setTelLetterHighColor)

    Q_PROPERTY(QColor telButtonBgColor READ getTelButtonBgColor WRITE setTelButtonBgColor)
    Q_PROPERTY(QColor telButtonNameColor READ getTelButtonNameColor WRITE setTelButtonNameColor)
    Q_PROPERTY(QColor telButtonTypeColor READ getTelButtonTypeColor WRITE setTelButtonTypeColor)

    Q_PROPERTY(QColor telPanelNormalColor READ getTelPanelNormalColor WRITE setTelPanelNormalColor)
    Q_PROPERTY(QColor telPanelHighColor READ getTelPanelHighColor WRITE setTelPanelHighColor)

public:
    //联系人结构体
    struct TelInfo {
        QString letter;
        QString name;
        QString type;
        QString tel;
        QPixmap pixmap;

        bool operator < (const TelInfo &telInfo) const {
            return letter < telInfo.letter;
            //return (letter == "#") ? false : (letter < telInfo.letter);
        }

        bool operator > (const TelInfo &telInfo) const {
            return letter > telInfo.letter;
            //return (letter == "#") ? true : (letter > telInfo.letter);
        }
    };

    explicit TelWidget(QWidget *parent = 0);
    ~TelWidget();

protected:
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);
    void paintEvent(QPaintEvent *);

private:
    QString names;              //姓名集合
    QString types;              //类型集合
    QString tels;               //电话集合

    QPixmap bgImage;            //背景图片
    QColor bgColor;             //背景颜色

    int lastPosition;           //最后滚动条位置
    TelHigh *telHigh;           //高亮字母标签
    TelBanner *telBanner;       //顶部间隔字母导航
    TelLetter *telLetter;       //右侧字母标签
    TelPanel *telPanel;         //通讯录面板

    QList<QWidget *> items;     //通讯录按钮集合
    QList<QWidget *> banners;   //通讯录字母分割集合
    QList<QPixmap> pixmaps;     //联系人图片集合
    QTimer *timer;              //隐藏高亮标签定时器

private slots:
    void initControl();
    void initForm();
    void btnPressed();
    void btnRelease();
    void positionChanged(int value);
    void letterClicked(const QString &letter, int letterY);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置姓名
    QString getNames() const;
    void setNames(const QString &names);

    //获取和设置类型
    QString getTypes() const;
    void setTypes(const QString &types);

    //获取和设置电话集合
    QString getTels() const;
    void setTels(const QString &tels);

    //批量设置姓名/类型/电话
    void setInfo(const QString &names, const QString &types, const QString &tels);
    void setInfo(const QStringList &names, const QStringList &types, const QStringList &tels, const QList<QPixmap> &pixmaps);

    //添加单个联系人
    void addInfo(const QString &name, const QString &type, const QString &tel, const QPixmap &pixmap);
    //删除单个联系人
    void deleteInfo(const QString &name, const QString &tel, bool one = true);
    //清空联系人
    void clearInfo();

    //获取和设置背景图
    QPixmap getBgImage() const;
    void setBgImage(const QPixmap &bgImage);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置高亮字母字体大小
    int getTelHighFontSize() const;
    void setTelHighFontSize(int telHighFontSize);

    //获取和设置高亮字母背景图片
    QPixmap getTelHighBgImage() const;
    void setTelHighBgImage(const QPixmap &telHighBgImage);

    //获取和设置高亮字母背景颜色
    QColor getTelHighBgColor() const;
    void setTelHighBgColor(const QColor &telHighBgColor);

    //获取和设置高亮字母文字颜色
    QColor getTelHighTextColor() const;
    void setTelHighTextColor(const QColor &telHighTextColor);

    //获取和设置顶部字母导航背景颜色
    QColor getTelBannerBgColor() const;
    void setTelBannerBgColor(const QColor &telBannerBgColor);

    //获取和设置顶部字母导航文字颜色
    QColor getTelBannerTextColor() const;
    void setTelBannerTextColor(const QColor &telBannerTextColor);

    //获取和设置顶部字母导航线条颜色
    QColor getTelBannerLineColor() const;
    void setTelBannerLineColor(const QColor &telBannerLineColor);

    //获取和设置右侧字母导航正常颜色
    QColor getTelLetterNormalColor() const;
    void setTelLetterNormalColor(const QColor &telLetterNormalColor);

    //获取和设置右侧字母导航加深颜色
    QColor getTelLetterHighColor() const;
    void setTelLetterHighColor(const QColor &telLetterHighColor);

    //获取和设置通讯录按钮背景颜色
    QColor getTelButtonBgColor() const;
    void setTelButtonBgColor(const QColor &telButtonBgColor);

    //获取和设置通讯录按钮姓名颜色
    QColor getTelButtonNameColor() const;
    void setTelButtonNameColor(const QColor &telButtonNameColor);

    //获取和设置通讯录按钮类型颜色
    QColor getTelButtonTypeColor() const;
    void setTelButtonTypeColor(const QColor &telButtonTypeColor);

    //获取和设置滚动条正常颜色
    QColor getTelPanelNormalColor() const;
    void setTelPanelNormalColor(const QColor &telPanelNormalColor);

    //获取和设置滚动条高亮颜色
    QColor getTelPanelHighColor() const;
    void setTelPanelHighColor(const QColor &telPanelHighColor);

Q_SIGNALS:
    void telClicked(const QString &name, const QString &type, const QString &tel);
};

#endif // TELWIDGET_H
