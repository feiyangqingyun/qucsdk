#ifndef YSCROLLBARH_H
#define YSCROLLBARH_H

#include <QWidget>

class QScrollBar;

#ifdef quc
class Q_DECL_EXPORT YScrollBarH : public QWidget
#else
class YScrollBarH : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int stepSingle READ getStepSingle WRITE setStepSingle)
    Q_PROPERTY(int stepDouble READ getStepDouble WRITE setStepDouble)

public:
    explicit YScrollBarH(QWidget *parent = 0);

private:
    QScrollBar *scrollBar;
    int stepSingle;
    int stepDouble;

private slots:
    void initStyle();
    void buttonClicked();

public:
    //设置联动的滚动条
    void setScrollBar(QScrollBar *scrollBar);

    //获取和设置单步滚动距离
    int getStepSingle() const;
    void setStepSingle(int stepSingle);

    //获取和设置双倍滚动距离
    int getStepDouble() const;
    void setStepDouble(int stepDouble);
};

#endif // YSCROLLBARH_H
