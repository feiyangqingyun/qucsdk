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
 * 7. 可设置阴影轮廓粗细和颜色。
 * 8. 支持全选、反选、清空选中等操作。
 * 9. 可设置和获取每一行的选中和未选中状态集合。
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
    explicit TaskModel(const QStringList &horizontalLabel, const QStringList &verticalLabel, QObject *parent);

protected:
    //需要重新实现的基类函数
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    //行标题列标题
    QStringList horizontalLabel;
    QStringList verticalLabel;
};

//任务策略委托
class TaskDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit TaskDelegate(QWidget *parent = 0);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    QWidget *widget;            //委托所在控件

    QColor bgColor;             //表格背景颜色
    QColor gridColor;           //表格线条颜色
    QColor headerTextColor;     //表头文字颜色
    QColor headerBgColor;       //表头背景颜色
    QColor normalColor;         //正常状态颜色
    QColor selectColor;         //选中状态颜色

    int shadowWidth;            //阴影轮廓大小
    QColor shadowColor;         //阴影轮廓颜色

public:
    //获取和设置表格背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &color);

    //获取和设置表格线条颜色
    QColor getGridColor() const;
    void setGridColor(const QColor &color);

    //获取和设置表头文字颜色
    QColor getHeaderTextColor() const;
    void setHeaderTextColor(const QColor &color);

    //获取和设置表头背景颜色
    QColor getHeaderBgColor() const;
    void setHeaderBgColor(const QColor &color);

    //获取和设置正常状态颜色
    QColor getNormalColor() const;
    void setNormalColor(const QColor &color);

    //获取和设置选中状态颜色
    QColor getSelectColor() const;
    void setSelectColor(const QColor &color);

    //获取和设置阴影轮廓大小
    int getShadowWidth() const;
    void setShadowWidth(int width);

    //获取和设置阴影轮廓颜色
    QColor getShadowColor() const;
    void setShadowColor(const QColor &color);
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

    Q_PROPERTY(QColor headerBgColor READ getHeaderBgColor WRITE setHeaderBgColor)
    Q_PROPERTY(QColor headerTextColor READ getHeaderTextColor WRITE setHeaderTextColor)

    Q_PROPERTY(QColor normalColor READ getNormalColor WRITE setNormalColor)
    Q_PROPERTY(QColor selectColor READ getSelectColor WRITE setSelectColor)

    Q_PROPERTY(int shadowWidth READ getShadowWidth WRITE setShadowWidth)
    Q_PROPERTY(QColor shadowColor READ getShadowColor WRITE setShadowColor)

public:
    explicit TaskTableView(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void contextMenuEvent(QContextMenuEvent *);

private:
    //行标题列标题
    QStringList horizontalLabel;
    QStringList verticalLabel;

    //行数列数
    int rowCount;
    int columnCount;

    //右键菜单
    QMenu *menu;
    //自定义委托
    TaskDelegate *taskDelegate;

private slots:
    //初始化界面
    void initForm();
    //初始化菜单
    void initMenu();
    //执行菜单操作
    void doAction();

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置选中单元格(1,1,0,1... 选中是1不选中是0每行48个值)
    QString getSelectRow(int row) const;
    void setSelectRow(int row, const QString &flag);

    //获取和设置表格背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &color);

    //获取和设置表格线条颜色
    QColor getGridColor() const;
    void setGridColor(const QColor &color);

    //获取和设置表头背景颜色
    QColor getHeaderBgColor() const;
    void setHeaderBgColor(const QColor &color);

    //获取和设置表头文字颜色
    QColor getHeaderTextColor() const;
    void setHeaderTextColor(const QColor &color);

    //获取和设置正常状态颜色
    QColor getNormalColor() const;
    void setNormalColor(const QColor &color);

    //获取和设置选中状态颜色
    QColor getSelectColor() const;
    void setSelectColor(const QColor &color);

    //获取和设置阴影轮廓大小
    int getShadowWidth() const;
    void setShadowWidth(int width);

    //获取和设置阴影轮廓颜色
    QColor getShadowColor() const;
    void setShadowColor(const QColor &color);

Q_SIGNALS:
    void selectChanged();
};

#endif // TASKTABLEVIEW_H
