#ifndef XSTACKWIDGET_H
#define XSTACKWIDGET_H

/**
 * 动态堆栈窗体控件 作者:feiyangqingyun(QQ:517216493) 2021-01-01
 * 1. 可设置窗体切换间隔。
 * 2. 可指定索引位置插入窗体。
 * 3. 支持插入和移除窗体对象。
 * 4. 可设置当前窗体索引或者对象。
 */

#include <QWidget>

class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT XStackWidget : public QWidget
#else
class XStackWidget : public QWidget
#endif

{
    Q_OBJECT

public:
    explicit XStackWidget(QWidget *parent = 0);
    ~XStackWidget();

protected:
    void resizeEvent(QResizeEvent *);

private:
    int duration;           //动画时间
    int offset;             //移动窗体偏移值
    int currentIndex;       //当前窗体索引
    int lastIndex;          //末尾窗体索引

    //动画类+窗体队列
    QPropertyAnimation *animation;
    QWidgetList listWidget;

private slots:
    //动画值改变
    void onValueChanged(const QVariant &);
    //移动完成
    void onMoveFinished();

    //开始移动动画
    void moveAnimationStart();
    //设置子窗体可见
    void setWidgetsVisible();

public:
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    int widgetCount() const;
    int widgetIndex() const;

    int indexOf(QWidget *widget) const;
    QWidget *currentWidget() const;
    QWidget *widget(int index) const;

public Q_SLOTS:
    //设置动画间隔时间
    void setDuration(int duration);

    //设置当前窗体索引
    void setCurrentIndex(int index);
    //设置当前窗体对象
    void setCurrentWidget(QWidget *widget);

    //插入窗体
    int addWidget(QWidget *widget);
    //指定索引位置插入窗体
    int insertWidget(int index, QWidget *widget);
    //移除窗体
    void removeWidget(QWidget *widget);

Q_SIGNALS:
    //当前窗体索引改变信号
    void currentChanged(int index);
    //窗体移除信号
    void widgetRemoved(int index);
};

#endif // XSTACKWIDGET_H
