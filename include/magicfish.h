#ifndef MAGICFISH_H
#define MAGICFISH_H

/**
 * 魔幻鱼控件 作者:feiyangqingyun(QQ:517216493) 2018-07-15
 * 本控件来源于网络(原作者:tyroneli(http://www.qtcn.org/bbs/read-htm-tid-65412.html))
 * 绘制原理 https://www.jianshu.com/p/3dd3d1524851
 * 1. 可设置鱼头、鱼身、鱼鳍、鱼尾的颜色。
 * 2. 可设置鱼头、鱼身、鱼鳍、鱼尾的比例。
 * 3. 可设置基准颜色，作为所有统一颜色。
 * 4. 可设置鱼鳍是否摆动。
 * 5. 可设置鱼的停留位置旋转角度。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT MagicFish : public QWidget
#else
class MagicFish : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(QColor headColor READ getHeadColor WRITE setHeadColor)
    Q_PROPERTY(QColor bodyColor READ getBodyColor WRITE setBodyColor)
    Q_PROPERTY(QColor finColor READ getFinColor WRITE setFinColor)
    Q_PROPERTY(QColor tailColor READ getTailColor WRITE setTailColor)
    Q_PROPERTY(QColor baseColor READ getBaseColor WRITE setBaseColor)

    Q_PROPERTY(bool finMove READ getFinMove WRITE setFinMove)
    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed)
    Q_PROPERTY(double wave READ getWave WRITE setWave)
    Q_PROPERTY(double currentAngle READ getCurrentAngle WRITE setCurrentAngle)

public:
    explicit MagicFish(QWidget *parent = 0);
    ~MagicFish();

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);
    void drawHead(QPainter *painter);
    void drawBody(QPainter *painter, const QPointF &pos, double angle);
    void drawFin(QPainter *painter, const QPointF &pos, bool left, double angle);
    void drawTail(QPainter *painter, const QPointF &pos, double angle);
    void drawTail1(QPainter *painter, const QPointF &pos, double angle);
    void drawTail2(QPainter *painter, const QPointF &pos, double angle);

private:
    //计算坐标点
    QPointF calcPoint(const QPointF &pos, double len, double angle);
    double qDegreesToRadians(double degrees);
    double qRadiansToDegrees(double radians);

private:
    QColor headColor;       //鱼头颜色
    QColor bodyColor;       //鱼身颜色
    QColor finColor;        //鱼鳍颜色
    QColor tailColor;       //鱼尾颜色
    QColor baseColor;       //基准颜色

    bool finMove;           //鱼鳍是否摆动
    int speed;              //游动的速度即尾巴摆动的频率
    double wave;            //晃动的幅度
    double currentAngle;    //旋转的角度
    int currentValue;       //游动的位置

    double headLen;         //鱼头尺寸
    double bodyLen;         //鱼身尺寸
    double finLen;          //鱼鳍尺寸
    double tailLen;         //鱼尾尺寸

    QPointF headPos;        //鱼头坐标
    QTimer *timer;          //定时器处理游动

private slots:
    void updateValue();     //更新数值

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取鱼头坐标
    QPointF getHeadPos() const;

    //获取和设置鱼头颜色
    QColor getHeadColor() const;
    void setHeadColor(const QColor &headColor);

    //设置鱼身颜色
    QColor getBodyColor() const;
    void setBodyColor(const QColor &bodyColor);

    //设置鱼鳍颜色
    QColor getFinColor() const;
    void setFinColor(const QColor &finColor);

    //设置鱼尾颜色
    QColor getTailColor() const;
    void setTailColor(const QColor &tailColor);

    //设置基准颜色
    QColor getBaseColor() const;
    void setBaseColor(const QColor &baseColor);

    //设置鱼鳍是否摆动
    bool getFinMove() const;
    void setFinMove(bool finMove);

    //设置游动的速度
    int getSpeed() const;
    void setSpeed(int speed);

    //设置滑动的幅度
    double getWave() const;
    void setWave(double wave);

    //设置当前旋转的角度
    double getCurrentAngle() const;
    void setCurrentAngle(double currentAngle);    

    //设置头部的长度
    double getHeadLen() const;
    void setHeadLen(int headLen);

public Q_SLOTS:
    void setCurrentAngle(int currentAngle);
};

#endif // MAGICFISH_H
