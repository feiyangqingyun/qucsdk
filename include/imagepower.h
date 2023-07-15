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
    Q_PROPERTY(int imageValue READ getImageValue WRITE setImageValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)

public:
    explicit ImagePower(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QImage image;                   //电池电量图片
    int imageValue;                 //电池电量图片表示的电量
    int value;                      //当前电量

public:
    QImage getImage()               const;
    int getImageValue()             const;
    int getValue()                  const;
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    void setImage(const QImage &image);
    void setImageValue(int imageValue);
    void setValue(int value);
};

#endif // IMAGEPOWER_H
