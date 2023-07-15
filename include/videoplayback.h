#ifndef VIDEOPLAYBACK_H
#define VIDEOPLAYBACK_H

/**
 * 视频回放控件 作者:feiyangqingyun(QQ:517216493) 2019-04-19
 * 1. 可设置回放控件部件的边距、间距、左侧文字宽度。
 * 2. 可设置通道1-4的文字。
 * 3. 可设置线条宽度、线条颜色。
 * 4. 可设置文字颜色、背景颜色。
 * 5. 可设置顶部时间标尺文字颜色、背景颜色。
 * 6. 可设置4个通道背景颜色、数据颜色。
 * 7. 可设置4个通道的数据集合，每个视频数据可以多个分段。
 * 8. 自由拓展度极高。
 */

#include <QWidget>

class QGridLayout;
class QLabel;

//顶部时间控件
class VideoTime : public QWidget
{
    Q_OBJECT
public:
    explicit VideoTime(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawRuler(QPainter *painter);

private:
    double minValue;
    double maxValue;
    double value;
    int longStep;
    int shortStep;

    QColor textColor;       //文字颜色
    QColor bgColor;         //背景颜色

public:
    //设置文字颜色+背景颜色
    void setTextColor(const QColor &textColor);
    void setBgColor(const QColor &bgColor);
};

//通道控件
class VideoCh : public QWidget
{
    Q_OBJECT
public:
    struct VideoData {
        int startX; //起始X坐标
        int length; //长度
    };

    explicit VideoCh(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawData(QPainter *painter);

private:
    QColor chColor;         //通道背景颜色
    QColor dataColor;       //通道数据颜色
    QList<VideoData> datas; //数据集合

public:
    //设置通道背景颜色+通道数据颜色
    void setChColor(const QColor &chColor);
    void setDataColor(const QColor &dataColor);

    //设置数据段
    void setDatas(const QList<VideoData> &datas);
};

#ifdef quc
class Q_DECL_EXPORT VideoPlayback : public QWidget
#else
class VideoPlayback : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int margin READ getMargin WRITE setMargin)
    Q_PROPERTY(int spacing READ getSpacing WRITE setSpacing)
    Q_PROPERTY(int labWidth READ getLabWidth WRITE setLabWidth)

    Q_PROPERTY(QString textCh1 READ getTextCh1 WRITE setTextCh1)
    Q_PROPERTY(QString textCh2 READ getTextCh2 WRITE setTextCh2)
    Q_PROPERTY(QString textCh3 READ getTextCh3 WRITE setTextCh3)
    Q_PROPERTY(QString textCh4 READ getTextCh4 WRITE setTextCh4)

    Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

    Q_PROPERTY(QColor videoTextColor READ getVideoTextColor WRITE setVideoTextColor)
    Q_PROPERTY(QColor videoBgColor READ getVideoBgColor WRITE setVideoBgColor)
    Q_PROPERTY(QColor videoChColor READ getVideoChColor WRITE setVideoChColor)
    Q_PROPERTY(QColor videoDataColor READ getVideoDataColor WRITE setVideoDataColor)

public:
    explicit VideoPlayback(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

private:
    int margin;             //边距
    int spacing;            //间距
    int labWidth;           //左侧宽度

    QString textCh1;        //通道1文字
    QString textCh2;        //通道2文字
    QString textCh3;        //通道3文字
    QString textCh4;        //通道4文字

    int lineWidth;          //线条宽度
    QColor lineColor;       //线条颜色
    QColor textColor;       //文字颜色
    QColor bgColor;         //背景颜色

    QColor videoTextColor;  //顶部时间标尺文字颜色
    QColor videoBgColor;    //顶部时间标尺背景颜色
    QColor videoChColor;    //通道背景颜色
    QColor videoDataColor;  //通道数据颜色

    QGridLayout *layout;    //表格布局
    QLabel *labTime;        //时间标签
    VideoTime *videoTime;   //时间控件

    QLabel *labCh1;         //通道1标签
    VideoCh *videoCh1;      //通道1控件

    QLabel *labCh2;         //通道2标签
    VideoCh *videoCh2;      //通道2控件

    QLabel *labCh3;         //通道3标签
    VideoCh *videoCh3;      //通道3控件

    QLabel *labCh4;         //通道4标签
    VideoCh *videoCh4;      //通道4控件

    QLabel *labFlow;        //悬浮标签
    QPoint pressPos;        //鼠标按下的坐标

public:
    int getMargin()         const;
    int getSpacing()        const;
    int getLabWidth()       const;

    QString getTextCh1()    const;
    QString getTextCh2()    const;
    QString getTextCh3()    const;
    QString getTextCh4()    const;

    int getLineWidth()      const;
    QColor getLineColor()   const;
    QColor getTextColor()   const;
    QColor getBgColor()     const;

    QColor getVideoTextColor()const;
    QColor getVideoBgColor()const;
    QColor getVideoChColor()const;
    QColor getVideoDataColor()const;

private slots:
    void initControl();

public Q_SLOTS:
    //设置边距+间距+左侧宽度
    void setMargin(int margin);
    void setSpacing(int spacing);
    void setLabWidth(int labWidth);

    //设置通道文字
    void setTextCh1(const QString &textCh1);
    void setTextCh2(const QString &textCh2);
    void setTextCh3(const QString &textCh3);
    void setTextCh4(const QString &textCh4);
    void setTextCh(const QString &textCh1, const QString &textCh2, const QString &textCh3, const QString &textCh4);

    //设置线条宽度+颜色
    void setLineWidth(int lineWidth);
    void setLineColor(const QColor &lineColor);

    //设置文字颜色+背景颜色
    void setTextColor(const QColor &textColor);
    void setBgColor(const QColor &bgColor);

    //设置时间标尺+通道颜色
    void setVideoTextColor(const QColor &videoTextColor);
    void setVideoBgColor(const QColor &videoBgColor);
    void setVideoChColor(const QColor &videoChColor);
    void setVideoDataColor(const QColor &videoDataColor);

    //设置各个通道的数据段
    void setDatas1(const QList<VideoCh::VideoData> &datas);
    void setDatas2(const QList<VideoCh::VideoData> &datas);
    void setDatas3(const QList<VideoCh::VideoData> &datas);
    void setDatas4(const QList<VideoCh::VideoData> &datas);
};

#endif // VIDEOPLAYBACK_H
