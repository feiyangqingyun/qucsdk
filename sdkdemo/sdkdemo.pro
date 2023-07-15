QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

TARGET      = sdkdemo
TEMPLATE    = app
#指定可执行文件目录 放到这里省了拷贝动态库动作 专为小白懒人考虑
DESTDIR     = $$PWD/quc
SOURCES     += main.cpp

#一次性引入自定义控件的所有头文件 懒得一个个拷贝
INCLUDEPATH += $$PWD/quc/include

#不同的构建套件 debug release 依赖不同的链接库
CONFIG(debug, debug|release){
LIBS += -L$$PWD/quc/ -lqucd
} else {
LIBS += -L$$PWD/quc/ -lquc
}
