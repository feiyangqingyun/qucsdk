#ifndef IMAGEEFFECT_H
#define IMAGEEFFECT_H

/**
 * 图片效果类 作者:公孙二狗(QQ:26664141) 2019-11-27
 * 1. 支持多种图片效果，后期不断增加。
 * 2. 灰度效果。
 * 3. 复古效果。
 * 4. 红色蒙版。
 * 5. 反转效果。
 * 6. 变亮变暗。
 */

#include <QObject>
#include <QImage>

#ifdef quc
class Q_DECL_EXPORT ImageEffect : public QObject
#else
class ImageEffect : public QObject
#endif

{
    Q_OBJECT
public:
    //通用处理
    static QImage effect(QImage image, int type, int value);
    //灰度效果
    static QImage gray(QImage image);
    //复古效果
    static QImage old(QImage image);
    //红色蒙版
    static QImage red(QImage image);
    //反转效果
    static QImage invert(QImage image);
    //变亮变暗效果
    static QImage brightness(QImage image, int value);

};

#endif // IMAGEEFFECT_H
