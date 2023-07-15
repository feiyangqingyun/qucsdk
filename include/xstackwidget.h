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
    int duration;       //动画时间

    int offset;         //移动窗体偏移值
    int currentIndex;   //当前窗体索引
    int lastIndex;      //末尾窗体索引

    //动画类+窗体队列
    QPropertyAnimation *animation;
    QWidgetList listWidget;

public:
    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

    int widgetCount()           const;
    int widgetIndex()           const;

    int addWidget(QWidget *widget);
    int indexOf(QWidget *widget)const;
    int insertWidget(int index, QWidget *widget);

    QWidget *currentWidget()    const;
    QWidget *widget(int index)  const;

    void removeWidget(QWidget *widget);
    void setDuration(int duration);

private slots:
    void onValueChanged(const QVariant &);
    void onMoveFinished();

private:
    void moveAnimationStart();
    void setWidgetsVisible();

public Q_SLOTS:
    void setCurrentIndex(int index);
    void setCurrentWidget(QWidget *widget);

Q_SIGNALS:
    void currentChanged(int index);
    void widgetRemoved(int index);
};
