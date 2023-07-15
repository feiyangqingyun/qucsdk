#ifndef IMAGEPILOT_H
#define IMAGEPILOT_H

/**
 * 图片指示灯控件 作者:feiyangqingyun(QQ:517216493) 2016-11-25
 * 1. 可设置五种颜色。
 * 2. 可自定义指示灯图片。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ImagePilot : public QWidget
#else
class ImagePilot : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(PilotStyle)
    Q_PROPERTY(PilotStyle pilotStyle READ getPilotStyle WRITE setPilotStyle)

public:
    enum PilotStyle {
        PilotStyle_Blue = 0,        //蓝色风格
        PilotStyle_Gray = 1,        //灰色风格
        PilotStyle_Green = 2,       //绿色风格
        PilotStyle_Red = 3,         //红色风格
        PilotStyle_Yellow = 4       //黄色风格
    };

    explicit ImagePilot(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

private:
    PilotStyle pilotStyle;
    QString imgFile;

public:
    PilotStyle getPilotStyle()      const;
    QString getImgFile()            const;
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    void setPilotStyle(const PilotStyle &pilotStyle);
    void setImage(const QString &imgFile);
};

#endif // IMAGEPILOT_H
