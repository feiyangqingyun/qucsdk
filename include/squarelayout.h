#ifndef SQUARELAYOUT_H
#define SQUARELAYOUT_H

#include <QLayout>
#include <QLayoutItem>
#include <QPointer>
#include <QRect>
#include <QWidgetItem>

#ifdef quc
class Q_DECL_EXPORT SquareLayout : public QLayout
#else
class SquareLayout : public QLayout
#endif

{
    Q_OBJECT

public:
    explicit SquareLayout(QWidget *parent, int spacing = -1);
    explicit SquareLayout(int spacing = -1);
    ~SquareLayout();

    void addItem(QLayoutItem *item);
    void addWidget(QWidget *widget);
    int count() const;

    Qt::Orientations expandingDirections() const;
    QRect geometry();
    bool hasHeightForWidth() const;
    bool hasItem() const;

    QLayoutItem *itemAt(int index) const;
    QSize minimumSize() const;
    QLayoutItem *replaceItem(QLayoutItem *item);

    void setGeometry(const QRect &rect);
    QSize sizeHint() const;

    QLayoutItem *take();
    QLayoutItem *takeAt(int index);

private:
    QLayoutItem *m_item;
    QRect *m_rectLast;
    QRect *m_geometry;

    bool areRectsEqual(const QRect &rect_1, const QRect &rect_2) const;
    QPoint calculateCenterPnt(QSize fromSize, QSize itemSize) const;
    QSize calculateProperSize(QSize fromSize) const;

    void init(int spacing);
    void setRectLast(const QRect &rect);
};

#endif // SQUARELAYOUT_H
