#ifndef YTABLEWIDGET_H
#define YTABLEWIDGET_H

#include <QTableWidget>

class QScrollBar;
class YScrollBarV;
class YScrollBarH;

#ifdef quc
class Q_DECL_EXPORT YTableWidget : public QTableWidget
#else
class YTableWidget : public QTableWidget
#endif

{
    Q_OBJECT
public:
    explicit YTableWidget(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    bool isShow;
    QScrollBar *vscrollBar;
    QScrollBar *hscrollBar;
    YScrollBarV *scrollBarV;
    YScrollBarH *scrollBarH;

private:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public Q_SLOTS:
    void setPosition();
    void setRangeV(int min, int max);
    void setRangeH(int min, int max);
};

#endif // YTABLEWIDGET_H
