#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H

/**
 * 流式布局 - qt自带demo
 */

#include <QLayout>
#include <QRect>
#include <QStyle>
#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT FlowLayout : public QLayout
#else
class FlowLayout : public QLayout
#endif

{
    Q_OBJECT

public:
    explicit FlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);
    explicit FlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
    ~FlowLayout();

    void addItem(QLayoutItem *item);
    int horizontalSpacing() const;
    int verticalSpacing() const;

    bool hasHeightForWidth() const;
    int heightForWidth(int) const;
    int count() const;

    QLayoutItem *itemAt(int index) const;
    QLayoutItem *takeAt(int index);
    Qt::Orientations expandingDirections() const;

    void setGeometry(const QRect &rect);
    QSize sizeHint() const;
    QSize minimumSize() const;

private:
    int doLayout(const QRect &rect, bool testOnly) const;
    int smartSpacing(QStyle::PixelMetric pm) const;

    QList<QLayoutItem *> itemList;
    int m_hSpace;
    int m_vSpace;
};

#endif
