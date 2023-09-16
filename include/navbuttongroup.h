#ifndef NAVBUTTONGROUP_H
#define NAVBUTTONGROUP_H

/**
 * 动画按钮组控件 作者:feiyangqingyun(QQ:517216493) 2018-09-12
 * 参考雨田哥(QQ:3246214072) https://blog.csdn.net/ly305750665/article/details/80736504
 * 1. 可设置线条的宽度。
 * 2. 可设置线条的颜色。
 * 3. 可设置线条的位置 上、下、左、右。
 * 4. 可设置按钮的正常、悬停、选中背景颜色。
 * 5. 可设置文字的正常、悬停、选中背景颜色。
 * 6. 切换位置线条自动跟随。
 * 7. 可设置按钮字符串组合生成按钮组。
 * 8. 可设置线条滑动的速度。
 */

#include <QWidget>

class QBoxLayout;
class QAbstractButton;
class QButtonGroup;
class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT NavButtonGroup : public QWidget
#else
class NavButtonGroup : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(LinePosition)

    Q_PROPERTY(int interval READ getInterval WRITE setInterval)
    Q_PROPERTY(int lineLen READ getLineLen WRITE setLineLen)
    Q_PROPERTY(int index READ getIndex WRITE setIndex)
    Q_PROPERTY(QString texts READ getTexts WRITE setTexts)
    Q_PROPERTY(LinePosition linePosition READ getLinePosition WRITE setLinePosition)

    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor btnNormalColor READ getBtnNormalColor WRITE setBtnNormalColor)
    Q_PROPERTY(QColor btnHoverColor READ getBtnHoverColor WRITE setBtnHoverColor)
    Q_PROPERTY(QColor btnDarkColor READ getBtnDarkColor WRITE setBtnDarkColor)

    Q_PROPERTY(QColor textNormalColor READ getTextNormalColor WRITE setTextNormalColor)
    Q_PROPERTY(QColor textHoverColor READ getTextHoverColor WRITE setTextHoverColor)
    Q_PROPERTY(QColor textDarkColor READ getTextDarkColor WRITE setTextDarkColor)
    Q_PROPERTY(QColor baseColor READ getBaseColor WRITE setBaseColor)

public:
    enum LinePosition {
        LinePosition_Left = 0,     //左边
        LinePosition_Right = 1,    //右边
        LinePosition_Top = 2,      //上边
        LinePosition_Bottom = 3    //下边
    };

    explicit NavButtonGroup(QWidget *parent = 0);
    ~NavButtonGroup();

protected:
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);
    void paintEvent(QPaintEvent *);

private:
    int interval;                   //线条移动的速度
    int lineLen;                    //线条的长度
    int index;                      //当前索引
    QString texts;                  //按钮文本集合
    LinePosition linePosition;      //线条方向

    QColor lineColor;               //线条的颜色
    QColor btnNormalColor;          //按钮正常颜色
    QColor btnHoverColor;           //按钮经过颜色
    QColor btnDarkColor;            //按钮加深选中颜色

    QColor textNormalColor;         //文字正常颜色
    QColor textHoverColor;          //文字经过颜色
    QColor textDarkColor;           //文字加深选中颜色
    QColor baseColor;               //基准颜色

    int previousIndex;              //上一个按钮索引
    int offset;                     //偏移量
    QSize btnSize;                  //按钮的尺寸
    QBoxLayout *layout;             //布局
    QButtonGroup *btnGroup;         //按钮组
    QList<QAbstractButton *> btns;  //按钮集合
    QPropertyAnimation *animation;  //属性动画

private slots:
    void onButtonClicked(int index);
    void onValueChanged(const QVariant &value);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置线条移动的速度
    int getInterval() const;
    void setInterval(int interval);

    //获取和设置线条的尺寸
    int getLineLen() const;
    void setLineLen(int lineLen);

    //获取和设置当前索引,选中按钮
    int getIndex() const;
    void setIndex(int index);

    //获取和设置按钮文本集合
    QString getTexts() const;
    void setTexts(const QString &texts);

    //获取和设置线条方向
    LinePosition getLinePosition() const;
    void setLinePosition(const LinePosition &linePosition);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置按钮正常颜色
    QColor getBtnNormalColor() const;
    void setBtnNormalColor(const QColor &btnNormalColor);

    //获取和设置按钮悬停颜色
    QColor getBtnHoverColor() const;
    void setBtnHoverColor(const QColor &btnHoverColor);

    //获取和设置鼠标选中颜色
    QColor getBtnDarkColor() const;
    void setBtnDarkColor(const QColor &btnDarkColor);

    //获取和设置文字正常颜色
    QColor getTextNormalColor() const;
    void setTextNormalColor(const QColor &textNormalColor);

    //获取和设置文字悬停颜色
    QColor getTextHoverColor() const;
    void setTextHoverColor(const QColor &textHoverColor);

    //获取和设置文字选中颜色
    QColor getTextDarkColor() const;
    void setTextDarkColor(const QColor &textDarkColor);

    //获取和设置基准颜色
    QColor getBaseColor() const;
    void setBaseColor(const QColor &baseColor, bool normal = false);

public Q_SLOTS:
    //初始化按下按钮
    void init();
    //添加按钮
    void addButton(QAbstractButton *btn, int id);
    //清空按钮
    void clearButton();
    //结束添加
    void addFinsh();
    //设置按钮样式
    void setBtnStyle();

Q_SIGNALS:
    void buttonClicked(int index);
    void buttonClicked(QAbstractButton *btn);
};

#endif // NAVBUTTONGROUP_H
