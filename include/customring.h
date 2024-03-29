﻿#ifndef CUSTOMRING_H
#define CUSTOMRING_H

/**
 * 自定义环形图控件 作者:雨田哥(QQ:3246214072) 整理:feiyangqingyun(QQ:517216493) 2019-07-28
 * 1. 可设置是否显示标题、标题文字、标题高度、标题字号。
 * 2. 可设置是否显示图例、图例高度、图例字号。
 * 3. 可设置背景颜色、文字颜色、高亮颜色、标识颜色。
 * 4. 可设置外圆颜色、中间圆颜色、内圆颜色。
 * 5. 可设置外圆数据集合、内圆数据集合。
 * 6. 鼠标悬停突出显示区域并高亮显示文字。
 * 7. 每个区域都可设置对应的颜色、文字描述、百分比。
 * 8. 支持直接字符串设置文字集合和百分比集合。
 * 9. 可设置悬停的偏移值即往外突出多少像素。
 * 10. 可设置悬停突出的颜色透明度。
 */

#include <QWidget>
#include <QPainterPath>

#ifdef quc
class Q_DECL_EXPORT CustomRing : public QWidget
#else
class CustomRing : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool showTitle READ getShowTitle WRITE setShowTitle)
    Q_PROPERTY(int titleHeight READ getTitleHeight WRITE setTitleHeight)
    Q_PROPERTY(int titleFontSize READ getTitleFontSize WRITE setTitleFontSize)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)

    Q_PROPERTY(bool showLegend READ getShowLegend WRITE setShowLegend)
    Q_PROPERTY(int legendHeight READ getLegendHeight WRITE setLegendHeight)
    Q_PROPERTY(int legendFontSize READ getLegendFontSize WRITE setLegendFontSize)

    Q_PROPERTY(int hoverOffset READ getHoverOffset WRITE setHoverOffset)
    Q_PROPERTY(int hoverAlpha READ getHoverAlpha WRITE setHoverAlpha)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor highColor READ getHighColor WRITE setHighColor)
    Q_PROPERTY(QColor flagColor READ getFlagColor WRITE setFlagColor)

    Q_PROPERTY(QColor outCircleColor READ getOutCircleColor WRITE setOutCircleColor)
    Q_PROPERTY(QColor midCircleColor READ getMidCircleColor WRITE setMidCircleColor)
    Q_PROPERTY(QColor inCircleColor READ getInCircleColor WRITE setInCircleColor)

    Q_PROPERTY(QString outPieInfos READ getOutPieInfos WRITE setOutPieInfos)
    Q_PROPERTY(QString inPieInfos READ getInPieInfos WRITE setInPieInfos)

public:
    struct RingData {
        int offset;         //鼠标移上去往外边突出显示的偏移距离
        int percent;        //百分比
        QColor color;       //背景色
        QString text;       //文本
        QPainterPath path;  //区域路径

        RingData() {
            offset = 0;
            percent = 0;
            color = QColor(0, 192, 133);
            text = "";
        }
    };

    explicit CustomRing(QWidget *parent = 0);
    ~CustomRing();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawOutCircle(QPainter *painter);
    void drawOutPie(QPainter *painter, qreal scale, QPoint center);
    void drawMidCircle(QPainter *painter);
    void drawInPie(QPainter *painter, qreal scale, QPoint center);
    void drawInCircle(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawLegendText(QPainter *painter, qreal scale);

private:
    bool showTitle;             //显示标题
    int titleHeight;            //标题高度
    int titleFontSize;          //标题字号
    QString title;              //标题

    bool showLegend;            //显示图例
    int legendHeight;           //图例高度
    int legendFontSize;         //图例字号

    int hoverOffset;            //悬停偏移值
    int hoverAlpha;             //悬停透明度

    QColor bgColor;             //背景颜色
    QColor textColor;           //文字颜色
    QColor highColor;           //高亮颜色
    QColor flagColor;           //标题左侧标识颜色

    QColor outCircleColor;      //外圆颜色
    QColor midCircleColor;      //中间圆颜色
    QColor inCircleColor;       //里边圆颜色

    QString outPieInfos;        //外边饼图数据
    QString inPieInfos;         //里边饼图数据
    QList<QColor> outPieColors; //饼图颜色集合,在设置字符串时候用
    QList<QColor> inPieColors;  //饼图颜色集合,在设置字符串时候用

    QList<RingData> outPieInfo; //外边饼图数据
    QList<RingData> inPieInfo;  //里边饼图数据

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置显示标题
    bool getShowTitle() const;
    void setShowTitle(bool showTitle);

    //获取和设置标题栏高度
    int getTitleHeight() const;
    void setTitleHeight(int titleHeight);

    //获取和设置标题字号
    int getTitleFontSize() const;
    void setTitleFontSize(int titleFontSize);

    //获取和设置标题文字
    QString getTitle() const;
    void setTitle(const QString &title);

    //获取和设置显示图例
    bool getShowLegend() const;
    void setShowLegend(bool showLegend);

    //获取和设置图例高度
    int getLegendHeight() const;
    void setLegendHeight(int legendHeight);

    //获取和设置图例字号
    int getLegendFontSize() const;
    void setLegendFontSize(int legendFontSize);

    //获取和设置鼠标悬停偏移值
    int getHoverOffset() const;
    void setHoverOffset(int hoverOffset);

    //获取和设置鼠标悬停颜色透明度
    int getHoverAlpha() const;
    void setHoverAlpha(int hoverAlpha);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置高亮颜色
    QColor getHighColor() const;
    void setHighColor(const QColor &highColor);

    //获取和设置标识颜色
    QColor getFlagColor() const;
    void setFlagColor(const QColor &flagColor);

    //获取和设置外圆颜色
    QColor getOutCircleColor() const;
    void setOutCircleColor(const QColor &outCircleColor);

    //获取和设置中间圆颜色
    QColor getMidCircleColor() const;
    void setMidCircleColor(const QColor &midCircleColor);

    //获取和设置里边圆颜色
    QColor getInCircleColor() const;
    void setInCircleColor(const QColor &inCircleColor);

    //获取和设置外圆数据
    QString getOutPieInfos() const;
    void setOutPieInfos(const QString &outPieInfos);

    //获取和设置里圆数据
    QString getInPieInfos() const;
    void setInPieInfos(const QString &inPieInfos);

    //设置颜色集合
    void setOutPieColors(const QList<QColor> &outPieColors);
    void setInPieColors(const QList<QColor> &inPieColors);

    //清空饼图数据
    void clearOutPie();
    void clearInPie();

    //设置饼图数据
    void appendOutPie(const RingData &data);
    void appendInPie(const RingData &data);
};

#endif // CUSTOMRING_H
