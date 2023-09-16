#ifndef XCOMBOBOX_H
#define XCOMBOBOX_H

/**
 * 自定义宽高下拉框控件 作者:feiyangqingyun(QQ:517216493) 2017-04-11
 * 1. 可设置下拉框选项高度。
 * 2. 可设置下拉框选项宽度。
 * 3. 可设置是否自动调整下拉框选项宽度，根据选项宽高自动调整。
 */

#include <QComboBox>

#ifdef quc
class Q_DECL_EXPORT XComboBox : public QComboBox
#else
class XComboBox : public QComboBox
#endif

{
    Q_OBJECT
    Q_PROPERTY(int itemWidth READ getItemWidth WRITE setItemWidth)
    Q_PROPERTY(int itemHeight READ getItemHeight WRITE setItemHeight)
    Q_PROPERTY(bool autoWidth READ getAutoWidth WRITE setAutoWidth)

public:
    explicit XComboBox(QWidget *parent = 0);

protected:
    void showEvent(QShowEvent *);

private:
    int itemWidth;      //下拉选项宽度
    int itemHeight;     //下拉选项高度
    bool autoWidth;     //是否自动调整宽度
    int maxItemWidth;   //下拉选项最大宽度

public Q_SLOTS:
    //设置下拉选项的宽度
    int getItemWidth() const;
    void setItemWidth(int itemWidth);

    //设置下拉选项的高度
    int getItemHeight() const;
    void setItemHeight(int itemHeight);

    //设置下拉选项是否自动调整宽度
    bool getAutoWidth() const;
    void setAutoWidth(bool autoWidth);
};

#endif // XCOMBOBOX_H
