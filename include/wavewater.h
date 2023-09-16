#ifndef WAVEWATER_H
#define WAVEWATER_H

/**
 * 水波效果控件 作者:离心泵(QQ:33522) 整理:feiyangqingyun(QQ:517216493) 2019-10-03
 * 1. 可设置显示的图像。
 * 2. 可设置衰减系数，控制消失速度，值越小水波消失越快。
 * 3. 可设置折射系数，控制扩散速度，值越大水波扩散越快。
 * 4. 可设置石头大小，控制水波面积，值越大水波面积越大。
 * 5. 可设置石头重量，控制水波深度，值越大水波深度越浪。
 * 6. 目前采用的是cpu运算和绘制，图片越小越流畅。
 */

#include <QWidget>
#include <QMap>

#ifdef quc
class Q_DECL_EXPORT WaveWater : public QWidget
#else
class WaveWater : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int damping READ getDamping WRITE setDamping)
    Q_PROPERTY(int refractive READ getRefractive WRITE setRefractive)
    Q_PROPERTY(int stoneSize READ getStoneSize WRITE setStoneSize)
    Q_PROPERTY(int stoneWeight READ getStoneWeight WRITE setStoneWeight)
    Q_PROPERTY(QPixmap image READ getImage WRITE setImage)

public:
    explicit WaveWater(QWidget *parent = 0);
    ~WaveWater();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:
    int damping;            //波能衰减系数
    int refractive;         //波能折射系数
    int stoneSize;          //石头大小
    int stoneWeight;        //石头重量
    QPixmap image;          //渲染图片

    QImage imageRender;     //渲染像素图片
    QImage imageOrigin;     //渲染源
    QPixmap pixmap;         //渲染图片

    int	imageWidth;         //图片宽度
    int	imageHeight;        //图片高度
    int **waveBuffer1;      //波能缓冲区1
    int **waveBuffer2;      //波能缓冲区2

    bool isStoped;          //水波是否结束波动
    bool isPressed;         //鼠标是否按下
    QPoint lastPoint;       //鼠标按下出的坐标
    QTimer *timer;          //定时器绘制

private slots:
    //执行计算位图进行绘制
    void drawImage();
    //水波步进扩散
    void waveSpread();
    //渲染水波位图
    void waveRender();
    //扔石子
    void dropStone(int x, int y, int stoneSize, int stoneWeight);

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置衰减率系数
    int getDamping() const;
    void setDamping(int damping);

    //获取和设置折射率系数
    int getRefractive() const;
    void setRefractive(int refractive);

    //获取和设置石头大小
    int getStoneSize() const;
    void setStoneSize(int stoneSize);

    //获取和设置石头重量
    int getStoneWeight() const;
    void setStoneWeight(int stoneWeight);

    //获取和设置背景图片
    QPixmap getImage() const;
    void setImage(const QPixmap &pixmap);
};

#endif // WAVEWATER_H
