#ifndef NAVBAR_H
#define NAVBAR_H

/**
 * 滑动导航条控件 作者:feiyangqingyun(QQ:517216493) 2016-10-08
 * 1. 可键盘按键上下移动元素功能。
 * 2. 支持窗体大小改变控件自动拉伸。
 * 3. 支持移动到第一个、末一个、上移、下移、移动到指定索引、移动到指定元素。
 * 4. 支持扁平处理。
 * 5. 支持纵向风格。
 * 6. 可设置圆角角度，包括主背景和选中元素背景。
 * 7. 可设置间距。
 * 8. 可设置导航条主背景渐变色。
 * 9. 可设置当前条目选中背景渐变色。
 * 10. 可设置条目未选中和选中的文字颜色。
 * 11. 可设置五种选中风格样式。
 * 12. 可设置线条颜色和宽度。
 * 13. 选中条目的宽度为条目文字集合中最长的一个。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT NavBar : public QWidget
#else
class NavBar : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(BarStyle)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(QColor barColorStart READ getBarColorStart WRITE setBarColorStart)
    Q_PROPERTY(QColor barColorEnd READ getBarColorEnd WRITE setBarColorEnd)

    Q_PROPERTY(QColor textNormalColor READ getTextNormalColor WRITE setTextNormalColor)
    Q_PROPERTY(QColor textSelectColor READ getTextSelectColor WRITE setTextSelectColor)

    Q_PROPERTY(QString items READ getItems WRITE setItems)
    Q_PROPERTY(int currentIndex READ getCurrentIndex WRITE setCurrentIndex)
    Q_PROPERTY(QString currentItem READ getCurrentItem WRITE setCurrentItem)

    Q_PROPERTY(int bgRadius READ getBgRadius WRITE setBgRadius)
    Q_PROPERTY(int barRadius READ getBarRadius WRITE setBarRadius)
    Q_PROPERTY(int space READ getSpace WRITE setSpace)

    Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

    Q_PROPERTY(BarStyle barStyle READ getBarStyle WRITE setBarStyle)

    Q_PROPERTY(bool keyMove READ getKeyMove WRITE setKeyMove)
    Q_PROPERTY(bool horizontal READ getHorizontal WRITE setHorizontal)
    Q_PROPERTY(bool flat READ getFlat WRITE setFlat)

public:
    enum BarStyle {
        BarStyle_Rect = 0,              //圆角矩形
        BarStyle_Line_Top = 1,          //上边线条
        BarStyle_Line_Right = 2,        //右边线条
        BarStyle_Line_Bottom = 3,       //下边线条
        BarStyle_Line_Left = 4          //左边线条
    };

    explicit NavBar(QWidget *parent = 0);
    ~NavBar();

protected:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawBar(QPainter *painter);
    void drawText(QPainter *painter);

private:
    QColor bgColorStart;    //导航条主背景渐变开始颜色
    QColor bgColorEnd;      //导航条主背景渐变结束颜色

    QColor barColorStart;   //导航条当前条目渐变开始颜色
    QColor barColorEnd;     //导航条当前条目渐变结束颜色

    QColor textNormalColor; //文字正常颜色
    QColor textSelectColor; //文字选中颜色

    QColor old_bgColorEnd;  //用于扁平化切换
    QColor old_barColorEnd; //用于扁平化切换

    QString items;          //所有条目文字信息
    int currentIndex;       //当前选中条目索引
    QString currentItem;    //当前选中条目文字

    int bgRadius;           //背景圆角半径
    int barRadius;          //选中条目背景圆角半径
    int space;              //条目元素之间的间距

    int lineWidth;          //线条宽度
    QColor lineColor;       //线条颜色
    BarStyle barStyle;      //选中元素样式

    bool keyMove;           //是否支持按键移动
    bool horizontal;        //是否横向显示
    bool flat;              //是否扁平化

    //元素集合,成对出现,元素的名字,矩形区域范围
    QVector<QPair<QString, QRectF> > listItem;

    QRectF barRect;         //选中区域矩形
    QRectF targetRect;      //目标区域的矩形
    double barLen;          //选中区域长度
    double targetLen;       //目标区域长度

    double initLen;         //导航条的长度
    int step;               //每次移动的步长

    //计算步长
    int initStep(int distance);

    bool isForward;         //是否往前移动
    bool isVirgin;          //是否首次处理
    QTimer *timer;          //滑动绘制定时器

private slots:
    void slide();           //执行滑动

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置导航条主背景渐变开始颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    //获取和设置导航条主背景渐变结束颜色
    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置当前条目选中背景渐变开始颜色
    QColor getBarColorStart() const;
    void setBarColorStart(const QColor &barColorStart);

    //获取和设置当前条目选中背景渐变结束颜色
    QColor getBarColorEnd() const;
    void setBarColorEnd(const QColor &barColorEnd);

    //获取和设置正常文字颜色
    QColor getTextNormalColor() const;
    void setTextNormalColor(const QColor &textNormalColor);

    //获取和设置选中文字颜色
    QColor getTextSelectColor() const;
    void setTextSelectColor(const QColor &textSelectColor);

    //获取和设置子项元素及当前索引及值
    QString getItems() const;
    void setItems(const QString &items);

    //获取和设置当前索引
    int getCurrentIndex() const;
    void setCurrentIndex(int index);

    //获取和设置当前值
    QString getCurrentItem() const;
    void setCurrentItem(const QString &item);

    //获取和设置背景圆角
    int getBgRadius() const;
    void setBgRadius(int bgRadius);

    //获取和设置柱状圆角
    int getBarRadius() const;
    void setBarRadius(int barRadius);

    //获取和设置条目间距
    int getSpace() const;
    void setSpace(int space);

    //获取和设置线条宽度
    int getLineWidth() const;
    void setLineWidth(int lineWidth);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置选中元素样式
    BarStyle getBarStyle() const;
    void setBarStyle(const BarStyle &barStyle);

    //获取和设置键盘按键是否能够移动条目
    bool getKeyMove() const;
    void setKeyMove(bool keyMove);

    //获取和设置横向显示,如果为假则纵向显示
    bool getHorizontal() const;
    void setHorizontal(bool horizontal);

    //获取和设置扁平,默认不扁平
    bool getFlat() const;
    void setFlat(bool flat);

public Q_SLOTS:
    //删除所有条目
    void clearItem();
    //移动到第一个条目
    void moveFirst();
    //移动到最后一个条目
    void moveLast();
    //往前移动条目
    void movePrevious();
    //往后移动条目
    void moveNext();
    //移动到指定索引条目
    void moveTo(int index);
    //移动到指定文字条目
    void moveTo(const QString &item);
    //移动到指定坐标位置条目
    void moveTo(const QPointF &point);

Q_SIGNALS:
    //当前条目改变信号,index为当前条目索引索引 item为当前条目文字
    void currentItemChanged(int index, const QString &item);
};

#endif // NAVBAR_H
