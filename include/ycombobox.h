#ifndef YCOMBOBOX_H
#define YCOMBOBOX_H

#include <QComboBox>

class QListView;
class QScrollBar;
class YScrollBarV;

#ifdef quc
class Q_DECL_EXPORT YComboBox : public QComboBox
#else
class YComboBox : public QComboBox
#endif

{
    Q_OBJECT
public:
    explicit YComboBox(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    bool isShow;
    QListView *listView;
    QScrollBar *vscrollBar;
    YScrollBarV *scrollBarV;

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

private slots:
    void initStyle();
    void setPosition();
    void setRange(int min, int max);
};

#endif // YCOMBOBOX_H
