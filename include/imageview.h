#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

/**
 * 图片浏览器控件 作者:feiyangqingyun(QQ:517216493) 2016-10-16
 * 本控件来源于网络(原作者:kimtaikee(http://www.qtcn.org/bbs/read-htm-tid-45436-ds-1.html#tpc))
 * 1. 增加鼠标右键清空。
 * 2. 增加设置背景色。
 * 3. 增加设置间距和翻页图标大小。
 * 4. 增加设置是否拉伸填充显示。
 * 5. 增加设置是否渐变显示图像。
 * 6. 增加设置键盘翻页。
 * 7. 增加移动到第一张、末一张、上一张、下一张。
 * 8. 修正内存泄露和其他bug。
 */

#include <QWidget>

class QToolButton;

#ifdef quc
class Q_DECL_EXPORT ImageNum : public QWidget
#else
class ImageNum : public QWidget
#endif

{
    Q_OBJECT
public:
    ImageNum(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawText(QPainter *painter);

private:
    int totalNum;       //总数
    int currentIndex;   //当前索引

public Q_SLOTS:
    //设置总数
    void setTotalNum(int totalNum);
    //设置当前索引
    void setCurrentIndex(int currentIndex);
};

#ifdef quc
class Q_DECL_EXPORT ImageView : public QWidget
#else
class ImageView : public QWidget
#endif

{
    Q_OBJECT
    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(int bottomSpace READ getBottomSpace WRITE setBottomSpace)
    Q_PROPERTY(int buttonSpace READ getButtonSpace WRITE setButtonSpace)
    Q_PROPERTY(QSize icoSize READ getIcoSize WRITE setIcoSize)

    Q_PROPERTY(bool fill READ getFill WRITE setFill)
    Q_PROPERTY(bool fade READ getFade WRITE setFade)
    Q_PROPERTY(bool keyMove READ getKeyMove WRITE setKeyMove)

public:
    explicit ImageView(QWidget *parent = 0);
    ~ImageView();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawImage(QPainter *painter);
    void keyPressEvent(QKeyEvent *);
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

private:
    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色

    int bottomSpace;        //底部间距
    int buttonSpace;        //按钮间距
    QSize icoSize;          //翻页按钮图标大小

    bool fill;              //是否填充
    bool fade;              //是否渐变显示
    bool keyMove;           //是否支持按键移动

    QToolButton *preButton; //向前移按钮
    QToolButton *nextButton;//向后移按钮

    QStringList imageNames; //图片名称集合
    int currentIndex;       //当前图片索引
    QImage currentImage;    //当前图片数据

    ImageNum *num;          //显示当前索引和总数的对象

    int totalNum;           //总数
    double opacity;         //当前透明值
    QTimer *timer;          //定时器改变透明值

private slots:
    void calcGeo();         //重新计算
    void doFading();        //渐变显示

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置背景开始颜色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    //获取和设置背景结束颜色
    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设置底部间距
    int getBottomSpace() const;
    void setBottomSpace(int bottomSpace);

    //获取和设置按钮间距
    int getButtonSpace() const;
    void setButtonSpace(int buttonSpace);

    //获取和设置翻页图标大小
    QSize getIcoSize() const;
    void setIcoSize(const QSize &icoSize);

    //获取和设置图像是否拉伸填充
    bool getFill() const;
    void setFill(bool fill);

    //获取和设置是否渐变显示
    bool getFade() const;
    void setFade(bool fade);

    //获取和设置键盘按键是否能够移动
    bool getKeyMove() const;
    void setKeyMove(bool keyMove);

public Q_SLOTS:
    //载入图像文件夹
    void load();
    void load(const QString &strFolder);
    //清除图像
    void clear();

    //移动到第一张
    void moveFirst();
    //移动到末一张
    void moveLast();
    //上一张
    void movePrevious();
    //下一张
    void moveNext();
    //移动到指定索引图片
    void moveTo(int index);

Q_SIGNALS:
    //总数发生改变时触发
    void totalNumChanged(int totalNum);
    //当前图片索引发生改变时触发
    void currentIndexChanged(int currentIndex);
};

#endif // IMAGEVIEW_H
