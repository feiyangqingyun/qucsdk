#ifndef WAVEDATA_H
#define WAVEDATA_H

/**
 * 音量采样值波形控件 作者:feiyangqingyun(QQ:517216493) 2017-09-10
 * 1. 可设置采样深度。
 * 2. 可设置当前位置线条宽度、线条颜色。
 * 3. 可设置背景颜色。
 * 4. 可设置三条数据曲线的颜色。
 * 5. 可设置数据展示样式。
 * 6. 支持最多3条数据曲线。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT WaveData : public QWidget
#else
class WaveData : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(WaveStyle)

    Q_PROPERTY(double deep READ getDeep WRITE setDeep)
    Q_PROPERTY(bool showLine READ getShowLine WRITE setShowLine)
    Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor dataColor READ getDataColor WRITE setDataColor)
    Q_PROPERTY(QColor dataColor2 READ getDataColor2 WRITE setDataColor2)
    Q_PROPERTY(QColor dataColor3 READ getDataColor3 WRITE setDataColor3)
    Q_PROPERTY(WaveStyle waveStyle READ getWaveStyle WRITE setWaveStyle)

public:
    enum WaveStyle {
        WaveStyle_Line = 0,     //线条样式
        WaveStyle_Smooth = 1,   //平滑样式
        WaveStyle_Bar = 2       //柱状样式
    };

    explicit WaveData(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawData(QPainter *painter, const QVector<float> &data, const QColor &dataColor);
    void drawLine(QPainter *painter);

private:
    double deep;            //采集深度
    bool showLine;          //显示线条
    int lineWidth;          //线条宽度

    QColor bgColor;         //背景色
    QColor lineColor;       //线条颜色
    QColor dataColor;       //数据曲线颜色
    QColor dataColor2;      //数据曲线颜色2
    QColor dataColor3;      //数据曲线颜色3
    WaveStyle waveStyle;    //数据样式

    int length;             //采样点长度
    int position;           //当前位置

    QVector<float> data;    //采样点数据
    QVector<float> data2;   //采样点数据2
    QVector<float> data3;   //采样点数据3

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置采样深度
    double getDeep() const;
    void setDeep(double deep);

    //获取和设置是否显示线条
    bool getShowLine() const;
    void setShowLine(bool showLine);

    //获取和设置是否线条宽度
    int getLineWidth() const;
    void setLineWidth(int lineWidth);

    //获取和设置是否线条颜色
    QColor getLineColor() const;
    void setLineColor(const QColor &lineColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置数据颜色
    QColor getDataColor() const;
    void setDataColor(const QColor &dataColor);

    //获取和设置数据颜色2
    QColor getDataColor2() const;
    void setDataColor2(const QColor &dataColor2);

    //获取和设置数据颜色3
    QColor getDataColor3() const;
    void setDataColor3(const QColor &dataColor3);

    //获取和设置数据样式
    WaveStyle getWaveStyle() const;
    void setWaveStyle(const WaveStyle &waveStyle);

    //获取和设置总长度+当前位置
    int getLength() const;
    void setLength(int length);

    int getPosition() const;
    void setPosition(int position);

    //获取和设置当前数据
    QVector<float> getData() const;
    void setData(const QVector<float> &data);

    //获取和设置当前数据2
    QVector<float> getData2() const;
    void setData2(const QVector<float> &data2);

    //获取和设置当前数据3
    QVector<float> getData3() const;
    void setData3(const QVector<float> &data3);

    //清空数据
    void clearData();

Q_SIGNALS:
    void positionChanged(int position);
};

#endif // WAVEDATA_H
