#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

/**
 * 底部状态栏控件 作者:feiyangqingyun(QQ:517216493) 2016-11-23
 * 1. 可设置软件标题。
 * 2. 可设置软件版本。
 * 3. 可设置版权所有。
 * 4. 可设置当前用户、当前用户类型。
 * 5. 可实时显示当前时间。
 * 6. 可实时显示已运行时间。
 * 7. 可设置每个部件是否可见。
 * 8. 可设置整体字体和字号。
 */

#include <QWidget>

class QLabel;

#ifdef quc
class Q_DECL_EXPORT BottomWidget : public QWidget
#else
class BottomWidget : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    QString title;                  //软件标题
    QString version;                //软件版本
    QString copyright;              //版权所有
    QString currentUserName;        //当前用户
    QString currentUserType;        //当前用户类型
    QString fontName;               //字体
    int fontSize;                   //字号
    bool lineFixedWidth;            //分隔符固定宽度

    int day;                        //天数
    int hour;                       //时钟数
    int minute;                     //分钟数
    int seconds;                    //秒钟数
    QTimer *timer;                  //定时器获取时间

    QLabel *labTitle;               //软件标题标签
    QLabel *labCopyright;           //版权所有标签
    QLabel *labUser;                //当前用户标签
    QLabel *labLive;                //已运行时间标签
    QLabel *labDateTime;            //当前时间标签

    bool labTitleVisible;           //标题标签是否可见
    bool labCopyrightVisible;       //版权所有标签是否可见
    bool labUserVisible;            //当前用户标签是否可见
    bool labLiveVisible;            //已运行时间标签是否可见
    bool labDateTimeVisible;        //当前时间标签是否可见

private slots:
    void showTime();

public:
    QString getTitle()              const;
    QString getVersion()            const;
    QString getCopyright()          const;
    QString getCurrentUserName()    const;
    QString getCurrentUserType()    const;

public Q_SLOTS:
    void setLabTitleVisible(bool labTitleVisible);
    void setLabCopyrightVisible(bool labCopyrightVisible);
    void setLabUserVisible(bool labUserVisible);
    void setLabLiveVisible(bool labLiveVisible);
    void setLabDateTimeVisible(bool labDateTimeVisible);

    void setTitle(const QString &title);
    void setVersion(const QString &version);
    void setCopyright(const QString &copyright);
    void setCurrentUserName(const QString &currentUserName);
    void setCurrentUserType(const QString &currentUserType);
    void setFontName(const QString &fontName);
    void setFontSize(int fontSize);
    void setLineFixedWidth(bool lineFixedWidth);
    void start(int interval = 1000);
};

#endif // BOTTOMWIDGET_H
