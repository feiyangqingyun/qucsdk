#ifndef PANELFRAME_H
#define PANELFRAME_H

/**
 * 面板区域控件 作者:feiyangqingyun(QQ:517216493) 2017-10-21
 * 1. 可设置标题栏文字、字体、对齐方式。
 * 2. 可设置标题栏高度、颜色。
 * 3. 可设置边框宽度、边框圆角角度、边框颜色。
 * 4. 可设置报警加深颜色、报警普通颜色。
 * 5. 可设置报警颜色切换间隔。
 * 6. 可设置启用状态和禁用状态时文字和边框颜色。
 * 7. 可设置是否整体换色比如绘制背景。
 */

#include <QWidget>

class QTimer;

#ifdef quc
class Q_DECL_EXPORT PanelItem : public QWidget
#else
class PanelItem : public QWidget
#endif

{
    Q_OBJECT
    Q_ENUMS(Alignment)

    Q_PROPERTY(int titleHeight READ getTitleHeight WRITE setTitleHeight)
    Q_PROPERTY(QString titleText READ getTitleText WRITE setTitleText)
    Q_PROPERTY(QFont titleFont READ getTitleFont WRITE setTitleFont)
    Q_PROPERTY(Alignment titleAlignment READ getTitleAlignment WRITE setTitleAlignment)
    Q_PROPERTY(QColor titleColor READ getTitleColor WRITE setTitleColor)
    Q_PROPERTY(QColor titleDisableColor READ getTitleDisableColor WRITE setTitleDisableColor)

    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)
    Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(QColor borderDisableColor READ getBorderDisableColor WRITE setBorderDisableColor)

    Q_PROPERTY(int alarmInterval READ getAlarmInterval WRITE setAlarmInterval)
    Q_PROPERTY(QColor alarmTextColor READ getAlarmTextColor WRITE setAlarmTextColor)
    Q_PROPERTY(QColor alarmDarkColor READ getAlarmDarkColor WRITE setAlarmDarkColor)
    Q_PROPERTY(QColor alarmNormalColor READ getAlarmNormalColor WRITE setAlarmNormalColor)

    Q_PROPERTY(bool isAlarm READ getIsAlarm WRITE setAlarm)
    Q_PROPERTY(bool isEnable READ getIsEnable WRITE setEnable)

public:
    enum Alignment {
        Alignment_Left = 0,     //左对齐
        Alignment_Center = 1,   //居中对齐
        Alignment_Right = 2     //右对齐
    };

    explicit PanelItem(QWidget *parent = 0);
    ~PanelItem();

protected:
    void paintEvent(QPaintEvent *);
    void drawBorder(QPainter *painter);
    void drawTitle(QPainter *painter);

private:
    int titleHeight;            //标题高度
    QString titleText;          //标题文字
    QFont titleFont;            //标题字体
    Alignment titleAlignment;   //标题对齐方式
    QColor titleColor;          //标题颜色
    QColor titleDisableColor;   //禁用状态下文字颜色

    int borderWidth;            //边框宽度
    int borderRadius;           //边框圆角角度
    QColor borderColor;         //边框颜色
    QColor borderDisableColor;  //禁用状态下边框颜色

    int alarmInterval;          //报警切换间隔
    QColor alarmTextColor;      //报警文字颜色
    QColor alarmDarkColor;      //报警加深颜色
    QColor alarmNormalColor;    //报警普通颜色

    bool drawAll;               //整体绘制背景
    bool isAlarm;               //是否报警
    bool isEnable;              //是否启用

    bool isDark;                //是否加深
    QColor tempColor;           //临时颜色
    QTimer *timer;              //报警切换定时器

private slots:
    void doAlarm();             //报警切换颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置报警状态
    bool getIsAlarm() const;
    void setAlarm(bool alarm);

    //获取和设置启用状态
    bool getIsEnable() const;
    void setEnable(bool enable);

    //获取和设置标题栏高度
    int getTitleHeight() const;
    void setTitleHeight(int titleHeight);

    //获取和设置标题文字
    QString getTitleText() const;
    void setTitleText(const QString &titleText);

    //获取和设置标题字体
    QFont getTitleFont() const;
    void setTitleFont(const QFont &titleFont);

    //获取和设置标题文字对齐方式
    Alignment getTitleAlignment() const;
    void setTitleAlignment(const Alignment &titleAlignment);

    //获取和设置标题文字颜色
    QColor getTitleColor() const;
    void setTitleColor(const QColor &titleColor);

    //获取和设置禁用状态下标题文字颜色
    QColor getTitleDisableColor() const;
    void setTitleDisableColor(const QColor &titleDisableColor);

    //获取和设置边框宽度
    int getBorderWidth() const;
    void setBorderWidth(int borderWidth);

    //获取和设置边框圆角角度
    int getBorderRadius() const;
    void setBorderRadius(int borderRadius);

    //获取和设置边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置禁用状态下边框颜色
    QColor getBorderDisableColor() const;
    void setBorderDisableColor(const QColor &borderDisableColor);

    //获取和设置报警切换间隔
    int getAlarmInterval() const;
    void setAlarmInterval(int alarmInterval);
    //获取和设置报警文字颜色
    QColor getAlarmTextColor() const;
    void setAlarmTextColor(const QColor &alarmTextColor);

    //获取和设置报警加深颜色
    QColor getAlarmDarkColor() const;
    void setAlarmDarkColor(const QColor &alarmDarkColor);

    //获取和设置报警普通颜色
    QColor getAlarmNormalColor() const;
    void setAlarmNormalColor(const QColor &alarmNormalColor);
};

#endif // PANELFRAME_H
