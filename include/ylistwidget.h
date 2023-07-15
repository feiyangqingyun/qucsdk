#ifndef YLISTWIDGET_H
#define YLISTWIDGET_H

#include <QListWidget>

class QScrollBar;
class YScrollBarV;

#ifdef quc
class Q_DECL_EXPORT YListWidget : public QListWidget
#else
class YListWidget : public QListWidget
#endif

{
    Q_OBJECT
public:
    explicit YListWidget(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    bool isShow;
    QScrollBar *vscrollBar;
    YScrollBarV *scrollBarV;

public:
    QSize sizeHint()        const;
    QSize minimumSizeHint() const;

private slots:
    void setPosition();
    void setRange(int min, int max);
};

#endif // YLISTWIDGET_H
