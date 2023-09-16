#ifndef XMODELINDEX_H
#define XMODELINDEX_H

/**
 * 复选数据模型 作者:feiyangqingyun(QQ:517216493) 2022-04-10
 * 1. 选中节点任意位置自动设置复选框状态。
 * 2. 自动更新所有父节点复选框状态。
 * 3. 自动更新所有子节点复选框状态。
 */

#include <QModelIndex>

#ifdef quc
class Q_DECL_EXPORT XModelIndex
#else
class XModelIndex
#endif
{
private:
    //检查当前节点是否可用以及是否具备复选属性
    static bool checkIndex(const QModelIndex &index);
    //联动子节点
    static void linkIndexChild(const QModelIndex &index, QAbstractItemModel *model);
    //联动父节点
    static void linkIndexParent(const QModelIndex &index, QAbstractItemModel *model);

public:
    //处理模型节点按下事件
    static void pressed(const QModelIndex &index, QAbstractItemModel *model);
    //处理模型节点单击事件
    static void clicked(const QModelIndex &index, QAbstractItemModel *model);
};

#endif // XMODELINDEX_H
