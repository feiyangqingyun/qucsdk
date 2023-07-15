#ifndef NAVPAGE_H
#define NAVPAGE_H

/**
 * 分页导航控件 作者:feiyangqingyun(QQ:517216493) 2020-04-23
 * 1. 可设置页码按钮的个数。
 * 2. 可设置字体大小。
 * 3. 可设置边框圆角角度、大小、颜色。
 * 4. 可设置正常状态背景颜色、文字颜色。
 * 5. 可识别悬停状态背景颜色、文字颜色。
 * 6. 可设置按下状态背景颜色、文字颜色。
 * 7. 可设置选中状态背景颜色、文字颜色。
 * 8. 可设置导航位置居中对齐、左对齐、右对齐。
 * 9. 可设置是否显示提示标签控件。
 * 10. 可设置是否显示跳转页码。
 * 11. 自动计算总页码数显示隐藏多余按钮。
 * 12. 自动计算切换页码导航。
 * 13. 可快速切换到第一页、末一页、上一页、下一页、页码按钮页、指定页码页。
 * 14. 和分页导航功能类无缝对接完美融合。
 */

#include <QWidget>

class QHBoxLayout;
class QSpacerItem;
class QLabel;
class QSpinBox;
class QPushButton;

#ifdef quc
class Q_DECL_EXPORT NavPage : public QWidget
#else
class NavPage : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(NavPosition)

    Q_PROPERTY(bool showStyle READ getShowStyle WRITE setShowStyle)
    Q_PROPERTY(bool showLabInfo READ getShowLabInfo WRITE setShowLabInfo)
    Q_PROPERTY(bool showGoPage READ getShowGoPage WRITE setShowGoPage)
    Q_PROPERTY(NavPosition navPosition READ getNavPosition WRITE setNavPosition)

    Q_PROPERTY(int pageButtonCount READ getPageButtonCount WRITE setPageButtonCount)
    Q_PROPERTY(int spacing READ getSpacing WRITE setSpacing)
    Q_PROPERTY(int fontSize READ getFontSize WRITE setFontSize)

    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)

    Q_PROPERTY(QColor normalBgColor READ getNormalBgColor WRITE setNormalBgColor)
    Q_PROPERTY(QColor normalTextColor READ getNormalTextColor WRITE setNormalTextColor)
    Q_PROPERTY(QColor hoverBgColor READ getHoverBgColor WRITE setHoverBgColor)
    Q_PROPERTY(QColor hoverTextColor READ getHoverTextColor WRITE setHoverTextColor)
    Q_PROPERTY(QColor pressedBgColor READ getPressedBgColor WRITE setPressedBgColor)
    Q_PROPERTY(QColor pressedTextColor READ getPressedTextColor WRITE setPressedTextColor)
    Q_PROPERTY(QColor checkedBgColor READ getCheckedBgColor WRITE setCheckedBgColor)
    Q_PROPERTY(QColor checkedTextColor READ getCheckedTextColor WRITE setCheckedTextColor)

public:
    enum NavPosition {
        NavPosition_Left = 0,   //左边位置
        NavPosition_Center = 1, //中间位置
        NavPosition_Right = 2   //右侧位置
    };

    explicit NavPage(QWidget *parent = 0);

private:
    bool showStyle;             //显示样式
    bool showLabInfo;           //显示提示信息标签
    bool showGoPage;            //显示跳转页码
    NavPosition navPosition;    //导航位置

    int minWidth;               //默认按钮宽度
    int pageButtonCount;        //页码按钮数量
    int spacing;                //控件间隔
    int fontSize;               //字体大小

    int borderWidth;            //边框大小
    int borderRadius;           //边框圆角
    QColor borderColor;         //边框颜色

    QColor normalBgColor;       //正常背景颜色
    QColor normalTextColor;     //正常文字颜色
    QColor hoverBgColor;        //悬停背景颜色
    QColor hoverTextColor;      //悬停文字颜色
    QColor pressedBgColor;      //按下背景颜色
    QColor pressedTextColor;    //按下文字颜色
    QColor checkedBgColor;      //选中背景颜色
    QColor checkedTextColor;    //选中文字颜色

    QFont iconFont;             //图形字体
    QHBoxLayout *layout;        //左右布局
    QSpacerItem *spacerLeft;    //左侧弹簧
    QSpacerItem *spacerRight;   //右侧弹簧

    QLabel *labInfo;            //显示查询结果信息
    QSpinBox *spinbox;          //显示页码
    QPushButton *btnGoPage;     //跳转页码

    //翻页按钮+页码按钮+所有按钮 对象集合
    QList<QPushButton *> btnMove, btnPage, btnAll;

private slots:
    //加载样式
    void initStyle();
    //加载翻页按钮
    void addBtnMove();
    //加载页码按钮
    void addBtnPage();
    //按钮加到布局中
    void addBtnAll();
    //页码按钮单击处理
    void btnClicked();

private slots:
    //查询翻页类传过来的信号
    void receivePage(quint32 pageCurrent, quint32 pageCount, quint32 resultCount, quint32 resultCurrent);

public:
    bool getShowStyle()         const;
    bool getShowLabInfo()       const;
    bool getShowGoPage()        const;
    NavPosition getNavPosition()const;

    int getPageButtonCount()    const;
    int getSpacing()            const;
    int getFontSize()           const;

    int getBorderRadius()       const;
    int getBorderWidth()        const;
    QColor getBorderColor()     const;

    QColor getNormalBgColor()   const;
    QColor getNormalTextColor() const;

    QColor getHoverBgColor()    const;
    QColor getHoverTextColor()  const;

    QColor getPressedBgColor()  const;
    QColor getPressedTextColor()const;

    QColor getCheckedBgColor()  const;
    QColor getCheckedTextColor()const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

    //提供接口获取按钮和标签控件
    QLabel *getLabInfo();
    QList<QPushButton *> getBtnMove();
    QList<QPushButton *> getBtnPage();
    QList<QPushButton *> getBtnAll();

public Q_SLOTS:
    //设置显示样式
    void setShowStyle(bool showStyle);
    //设置显示提示信息标签
    void setShowLabInfo(bool showLabInfo);
    //设置显示跳转页码
    void setShowGoPage(bool showGoPage);
    //设置导航位置
    void setNavPosition(const NavPosition &navPosition);

    //设置页码按钮数量+间隔+字体大小
    void setPageButtonCount(int pageButtonCount);
    void setSpacing(int spacing);
    void setFontSize(int fontSize);

    //设置边框圆角+宽度+颜色
    void setBorderRadius(int borderRadius);
    void setBorderWidth(int borderWidth);
    void setBorderColor(const QColor &borderColor);

    //设置正常状态背景颜色+文字颜色
    void setNormalBgColor(const QColor &normalBgColor);
    void setNormalTextColor(const QColor &normalTextColor);

    //设置悬停状态背景颜色+文字颜色
    void setHoverBgColor(const QColor &hoverBgColor);
    void setHoverTextColor(const QColor &hoverTextColor);

    //设置按下状态背景颜色+文字颜色
    void setPressedBgColor(const QColor &pressedBgColor);
    void setPressedTextColor(const QColor &pressedTextColor);

    //设置选中状态背景颜色+文字颜色
    void setCheckedBgColor(const QColor &checkedBgColor);
    void setCheckedTextColor(const QColor &checkedTextColor);

    //统一设置 普通+加深 颜色
    void setNormalColor(const QColor &bgColor, const QColor &textColor);
    void setDarkColor(const QColor &bgColor, const QColor &textColor);

Q_SIGNALS:
    void selectPage(int page);
};

#endif // NAVPAGE_H
