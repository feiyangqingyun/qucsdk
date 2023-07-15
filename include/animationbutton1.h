#ifndef ANIMATIONBUTTON1_H
#define ANIMATIONBUTTON1_H

/**
 * 动画按钮控件 作者:feiyangqingyun(QQ:517216493) 2016-10-22
 * 1. 可设置显示的图像。
 */

#include <QWidget>
#include <QVariant>

class QPropertyAnimation;

#ifdef quc
class Q_DECL_EXPORT AnimationButton1 : public QWidget
#else
class AnimationButton1 : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QString imageName READ getImageName WRITE setImageName)

public:
    explicit AnimationButton1(QWidget *parent = 0);
    ~AnimationButton1();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *);

private:
    bool mousePress;            //鼠标是否按下
    bool mouseEnter;            //鼠标是否进入
    bool mouseLeave;            //鼠标是否离开

    int pixWidth;               //图片宽度
    int pixHeight;              //图片高度
    int oldWidth;               //图片旧宽度
    int oldHeight;              //图片旧高度

    int targetWidth;            //目标宽度
    int targetHeight;           //目标高度
    QString imageName;          //图像路径

    //进入动画+//离开动画
    QPropertyAnimation *enterAnimation;
    QPropertyAnimation *leaveAnimation;

private slots:
    void enterImageChanged(QVariant index);
    void leaveImageChanged(QVariant index);

public:
    QString getImageName()      const;

    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;

public Q_SLOTS:
    //设置显示的图像
    void setImageName(const QString &imageName);

Q_SIGNALS:
    void pressed();
    void released();
    void clicked();
};

#endif // ANIMATIONBUTTON1_H
