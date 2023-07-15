#ifndef CPUMEMORYLABEL_H
#define CPUMEMORYLABEL_H

/**
 * CPU内存显示控件 作者:feiyangqingyun(QQ:517216493) 2016-11-18
 * 1. 实时显示当前CPU及内存使用情况，包括共多少内存已使用多少内存。
 * 2. 全平台通用，包括windows，linux，ARM。
 */

#include <QLabel>

class QProcess;

#ifdef quc
class Q_DECL_EXPORT CpuMemoryLabel : public QLabel
#else
class CpuMemoryLabel : public QLabel
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool showText READ getShowText WRITE setShowText)

public:
    explicit CpuMemoryLabel(QWidget *parent = 0);
    ~CpuMemoryLabel();

private:
    quint64 totalNew, idleNew, totalOld, idleOld;

    quint64 cpuPercent;     //CPU百分比
    quint64 memoryPercent;  //内存百分比
    quint64 memoryAll;      //所有内存
    quint64 memoryUse;      //已用内存
    quint64 memoryFree;     //空闲内存

    QTimer *timerCPU;       //定时器获取CPU信息
    QTimer *timerMemory;    //定时器获取内存信息
    QProcess *process;      //linux执行命令

    bool showText;          //自己显示值

private slots:
    void getCPU();          //获取cpu
    void getMemory();       //获取内存
    void readData();        //读取数据
    void setData();         //设置数据

public:
    bool getShowText()      const;
    void setShowText(bool showText);

    QSize sizeHint()        const;
    QSize minimumSizeHint() const;

public Q_SLOTS:
    void start(int interval);
    void stop();

Q_SIGNALS:
    void textChanged(const QString &text);
    void valueChanged(quint64 cpuPercent, quint64 memoryPercent, quint64 memoryAll, quint64 memoryUse, quint64 memoryFree);
};

#endif // CPUMEMORYLABEL_H
