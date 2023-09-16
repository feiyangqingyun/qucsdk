#ifndef IMAGEPOWER_H
#define IMAGEPOWER_H

/**
 * 图片电源控件 作者:feiyangqingyun(QQ:517216493) 2016-11-25
 * 1. 可设置五种电源状态。
 * 2. 可自定义电源图片。
 */

#include <QWidget>
#include <QImage>

#ifdef quc
class Q_DECL_EXPORT ImagePower : public QWidget
#else
class ImagePower : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QImage image READ getImage WRITE setImage)
    Q_PROPERTY(int value READ getValue WRITE setValue)

public:
    explicit ImagePower(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QImage image;       //电池电量图片
    int value;          //当前电量

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置电池图片
    QImage getImage() const;
    void setImage(const QImage &image);

    //获取和设置电量值(范围 0-5)
    int getValue() const;
    void setValue(int value);
};

#endif // IMAGEPOWER_H
