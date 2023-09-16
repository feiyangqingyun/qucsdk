#ifndef ICONEDITOR_H
#define ICONEDITOR_H

/**
 * 图标编辑控件 作者:feiyangqingyun(QQ:517216493) 2017-02-10
 * 来源于Qt官方教材
 * 1. 可设置缩放因子。
 * 2. 可设置宫格线条颜色。
 * 3. 可设置画笔颜色。
 * 4. 可设置ico图片。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT IconEditor : public QWidget
#else
class IconEditor : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int zoomFactor READ getZoomFactor WRITE setZoomFactor)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor penColor READ getPenColor WRITE setPenColor)
    Q_PROPERTY(QImage iconImage READ getIconImage WRITE setIconImage)

public:
    explicit IconEditor(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void drawBg(QPainter *painter);
    void drawIcon(QPainter *painter, QPaintEvent *event);

private:
    int zoomFactor;                 //伸缩因子
    QColor lineColor;               //线条颜色
    QColor penColor;                //画笔颜色
    QImage iconImage;               //ico图片

private:
    void setImagePixel(const QPoint &pos, bool opaque);
    QRect pixelRect(int i, int j) const;

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置伸缩因子
    int getZoomFactor() const;
    void setZoomFactor(int zoomFactor);

    //获取和设置线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置画笔颜色
    QColor getPenColor() const;
    void setPenColor(const QColor &penColor);

    //获取和设置图标图片
    QImage getIconImage() const;
    void setIconImage(const QImage &iconImage);
    void setIconImage(const QString &iconFile);

    //保存图标文件
    void saveIcon(const QString &file);
    void saveBg(const QString &file);
};

#endif // ICONEDITOR_H
