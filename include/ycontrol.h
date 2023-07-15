#ifndef YCONTROL_H
#define YCONTROL_H

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT YControl
#else
class YControl
#endif

{
public:
    static void initStyle(QWidget *widget);
};

#endif // YCONTROL_H
