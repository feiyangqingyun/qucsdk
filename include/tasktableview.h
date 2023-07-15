#ifndef TASKTABLEVIEW_H
#define TASKTABLEVIEW_H

/**
 * 任务策略表格控件 作者:雨田哥(QQ:3246214072) 整理:feiyangqingyun(QQ:517216493) 2021-02-28
 * 1. 可设置表格背景颜色。
 * 2. 可设置表格线条颜色。
 * 3. 可设置表头背景颜色。
 * 4. 可设置表头文字颜色。
 * 5. 可设置正常状态颜色。
 * 6. 可设置选中状态颜色。
 * 7. 支持撤销上一步操作。
 * 8. 支持全选、反选操作。
 * 9. 支持清空选中。
 */

#include <QTableView>
#include <QColor>
#include <QAbstractTableModel>
#include <QStyledItemDelegate>

//任务策略数据模型
class TaskModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TaskModel(QObject *parent = 0);
    ~TaskModel();

protected:
    //需要重新实现的基类函数
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    //行标题列标题
    QStringList horizontalHeader, verticalHeader;
    //行数列数
    int row, column;

private:
    void internalUpdate();

public:
    //设置行数和列数
    void setRowCount(int row);
    void setColumnCount(int column);
};

//任务策略委托
class TaskDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit TaskDelegate(QWidget *parent = 0);
    ~TaskDelegate();

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    QWidget *widget;        //父类控件
    QModelIndex currentIndex;//当前模型索引

    QColor bgColor;         //表格背景颜色
    QColor gridColor;       //表格线条颜色
    QColor headerTextColor; //表头文字颜色
    QColor headerBgColor;   //表头背景颜色
    QColor normalColor;     //正常状态颜色
    QColor selectColor;     //选中状态颜色

public Q_SLOTS:
    //表格背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &color);

    //表格线条颜色
    QColor getGridColor() const;
    void setGridColor(const QColor &color);

    //表头文字颜色
    QColor getHeaderTextColor() const;
    void setHeaderTextColor(const QColor &color);

    //表头背景颜色
    QColor getHeaderBgColor() const;
    void setHeaderBgColor(const QColor &color);

    //正常状态颜色
    QColor getNormalColor() const;
    void setNormalColor(const QColor &color);

    //选中状态颜色
    QColor getSelectColor() const;
    void setSelectColor(const QColor &color);
};

#ifdef quc
class Q_DECL_EXPORT TaskTableView : public QTableView
#else
class TaskTableView : public QTableView
#endif
{
    Q_OBJECT

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor gridColor READ getGridColor WRITE setGridColor)
    Q_PROPERTY(QColor headerTextColor READ getHeaderTextColor WRITE setHeaderTextColor)
    Q_PROPERTY(QColor headerBgColor READ getHeaderBgColor WRITE setHeaderBgColor)
    Q_PROPERTY(QColor normalColor READ getNormalColor WRITE setNormalColor)
    Q_PROPERTY(QColor selectColor READ getSelectColor WRITE setSelectColor)

public:
    explicit TaskTableView(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void contextMenuEvent(QContextMenuEvent *);

private:
    //右键菜单
    QMenu *menu;
    //数据模型+自定义委托
    TaskModel *taskModel;
    TaskDelegate *taskDelegate;
    //选中操作集合+当前选中操作
    QList<QItemSelection> listSelection;
    QItemSelection currentSelection;

private slots:
    void initForm();        //初始化界面
    void initMenu();        //初始化菜单
    void doAction();        //执行菜单操作
    void updateGridItem();  //更新单元格
    void onSelectChanged(); //撤销触发选择改动

public:
    QSize sizeHint()        const;
    QSize minimumSizeHint() const;

public Q_SLOTS:
    //表格背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &color);

    //表格线条颜色
    QColor getGridColor() const;
    void setGridColor(const QColor &color);

    //表头文字颜色
    QColor getHeaderTextColor() const;
    void setHeaderTextColor(const QColor &color);

    //表头背景颜色
    QColor getHeaderBgColor() const;
    void setHeaderBgColor(const QColor &color);

    //正常状态颜色
    QColor getNormalColor() const;
    void setNormalColor(const QColor &color);

    //选中状态颜色
    QColor getSelectColor() const;
    void setSelectColor(const QColor &color);
};

#endif // TASKTABLEVIEW_H
