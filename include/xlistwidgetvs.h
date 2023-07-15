#ifndef XLISTWIDGETVS_H
#define XLISTWIDGETVS_H

/**
 * 视频源面板控件 作者:feiyangqingyun(QQ:517216493) 2019-03-31
 * 1. 可设置视频源个数。
 * 2. 可设置文字颜色、背景颜色。
 * 3. 可设置鼠标选中文字颜色、鼠标选中背景颜色。
 * 4. 可设置鼠标悬停文字颜色、鼠标悬停背景颜色。
 * 5. 可设置标题+标题颜色。
 * 6. 可设置节点的最小宽度高度。
 * 7. 可设置节点字符串集合。
 * 8. 可设置节点个数，自动生成节点。
 * 9. 可设置滚动条位置左侧右侧、宽度、颜色。
 */

#include <QListWidget>

class QLabel;

#ifdef quc
class Q_DECL_EXPORT XListWidgetVS : public QListWidget
#else
class XListWidgetVS : public QListWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor selectTextColor READ getSelectTextColor WRITE setSelectTextColor)
    Q_PROPERTY(QColor selectBgColor READ getSelectBgColor WRITE setSelectBgColor)
    Q_PROPERTY(QColor hoverTextColor READ getHoverTextColor WRITE setHoverTextColor)
    Q_PROPERTY(QColor hoverBgColor READ getHoverBgColor WRITE setHoverBgColor)

    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(QColor titleColor READ getTitleColor WRITE setTitleColor)
    Q_PROPERTY(QString itemTexts READ getItemTexts WRITE setItemTexts)
    Q_PROPERTY(QColor itemColor READ getItemColor WRITE setItemColor)

    Q_PROPERTY(int itemCount READ getItemCount WRITE setItemCount)
    Q_PROPERTY(int itemWidth READ getItemWidth WRITE setItemWidth)
    Q_PROPERTY(int itemHeight READ getItemHeight WRITE setItemHeight)

    Q_PROPERTY(int scrollWidth READ getScrollWidth WRITE setScrollWidth)
    Q_PROPERTY(bool scrollLeft READ getScrollLeft WRITE setScrollLeft)
    Q_PROPERTY(QColor scrollColor READ getScrollColor WRITE setScrollColor)

public:
    explicit XListWidgetVS(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QColor textColor;           //文字颜色
    QColor bgColor;             //背景颜色
    QColor selectTextColor;     //选中文字颜色
    QColor selectBgColor;       //选中背景颜色
    QColor hoverTextColor;      //悬停文字颜色
    QColor hoverBgColor;        //悬停背景颜色

    QString title;              //标题
    QColor titleColor;          //标题颜色
    QColor itemColor;           //元素背景颜色
    QString itemTexts;          //节点文本集合

    int itemCount;              //节点个数
    int itemWidth;              //节点宽度
    int itemHeight;             //节点高度

    int scrollWidth;            //滚动条宽度
    bool scrollLeft;            //滚动条在左侧
    QColor scrollColor;         //滚动条颜色

    QPixmap pixCursor;          //鼠标按下样式
    QScrollBar *scrollBar;      //悬浮滚动条
    QLabel *labTitle;           //标题文字

private slots:
    void initForm();
    void initTitle();
    void initStyle();
    void initScroll();
    void initItem();
    void itemClicked();
    void setRange(int min, int max);

public:
    QColor getTextColor()       const;
    QColor getBgColor()         const;
    QColor getSelectTextColor() const;
    QColor getSelectBgColor()   const;
    QColor getHoverTextColor()  const;
    QColor getHoverBgColor()    const;

    QString getTitle()          const;
    QColor getTitleColor()      const;
    QString getItemTexts()      const;
    QColor getItemColor()       const;

    int getItemCount()          const;
    int getItemWidth()          const;
    int getItemHeight()         const;

    int getScrollWidth()        const;
    bool getScrollLeft()        const;
    QColor getScrollColor()     const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置文字颜色
    void setTextColor(const QColor &textColor);
    //设置背景颜色
    void setBgColor(const QColor &bgColor);
    //设置选中文字颜色
    void setSelectTextColor(const QColor &selectTextColor);
    //设置选中背景颜色
    void setSelectBgColor(const QColor &selectBgColor);
    //设置悬停文字颜色
    void setHoverTextColor(const QColor &hoverTextColor);
    //设置悬停背景颜色
    void setHoverBgColor(const QColor &hoverBgColor);

    //设置标题+标题颜色
    void setTitle(const QString &title);
    void setTitleColor(const QColor &titleColor);
    //设置节点文本集合+颜色
    void setItemTexts(const QString &itemTexts);
    void setItemColor(const QColor &itemColor);

    //设置节点个数
    void setItemCount(int itemCount);
    //设置节点宽度
    void setItemWidth(int itemWidth);
    //设置节点高度
    void setItemHeight(int itemHeight);

    //设置滚动条宽度
    void setScrollWidth(int scrollWidth);
    //设置滚动条位置
    void setScrollLeft(bool scrollLeft);
    //设置滚动条颜色
    void setScrollColor(const QColor &scrollColor);

Q_SIGNALS:
    void itemClicked(int index, const QString &text);

};

#endif // XLISTWIDGETVS_H
