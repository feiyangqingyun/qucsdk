#ifndef MAGICPENGUIN_H
#define MAGICPENGUIN_H

/**
 * 魔幻企鹅 作者:feiyangqingyun(QQ:517216493) 2021-08-06
 * 1. 可设置企鹅身体部位的各种颜色。
 * 2. 可设置基准颜色应用所有。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT MagicPenguin : public QWidget
#else
class MagicPenguin : public QWidget
#endif

{
    Q_OBJECT
public:
    explicit MagicPenguin(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

    void drawBelly1(QPainter *painter);
    void drawBelly2(QPainter *painter);
    void drawBelly3(QPainter *painter);
    void drawBelly4(QPainter *painter);
    void drawBelly5(QPainter *painter);
    void drawBelly6(QPainter *painter);

    void drawShadow1(QPainter *painter);
    void drawShadow2(QPainter *painter);

    void drawRightFoot1(QPainter *painter);
    void drawRightFoot2(QPainter *painter);

    void drawCover1(QPainter *painter);
    void drawCover2(QPainter *painter);

    void drawLeftEye1(QPainter *painter);
    void drawLeftEye2(QPainter *painter);
    void drawLeftEye3(QPainter *painter);
    void drawLeftEye4(QPainter *painter);

    void drawRightEye1(QPainter *painter);
    void drawRightEye2(QPainter *painter);
    void drawRightEye3(QPainter *painter);
    void drawRightEye4(QPainter *painter);

    void drawMouth1(QPainter *painter);
    void drawMouth2(QPainter *painter);
    void drawMouth3(QPainter *painter);

    void drawRightDot1(QPainter *painter);
    void drawRightDot2(QPainter *painter);
    void drawRightDot3(QPainter *painter);
    void drawRightDot4(QPainter *painter);
    void drawRightDot5(QPainter *painter);

    void drawLeftHandArc(QPainter *painter);
    void drawRightHandArc(QPainter *painter);

    void drawBeautify1(QPainter *painter);
    void drawBeautify2(QPainter *painter);
    void drawBeautify3(QPainter *painter);

    void drawLeftFoot1(QPainter *painter);
    void drawLeftFoot2(QPainter *painter);

public:
    QSize sizeHint()            const;
    QSize minimumSizeHint()     const;
};

#endif // MAGICPENGUIN_H
