#ifndef FLIGHTTC_H
#define FLIGHTTC_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightTC : public QGraphicsView
#else
class FlightTC : public QGraphicsView
#endif

{
    Q_OBJECT

    Q_PROPERTY(float turnRate READ getTurnRate WRITE setTurnRate)
    Q_PROPERTY(float slipSkid READ getSlipSkid WRITE setSlipSkid)

public:
    explicit FlightTC(QWidget *parent = 0);
    ~FlightTC();

    void reinit();
    void update();

    float getTurnRate() const;
    void setTurnRate(float turnRate);

    float getSlipSkid() const;
    void setSlipSkid(float slipSkid);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemBack;
    QGraphicsSvgItem *m_itemBall;
    QGraphicsSvgItem *m_itemFace_1;
    QGraphicsSvgItem *m_itemFace_2;
    QGraphicsSvgItem *m_itemMark;
    QGraphicsSvgItem *m_itemCase;

    float m_turnRate;
    float m_slipSkid;

    float m_scaleX;
    float m_scaleY;

    int m_originalHeight;
    int m_originalWidth;

    QPointF m_originalMarkCtr;
    QPointF m_originalBallCtr;

    int m_backZ;
    int m_ballZ;
    int m_face1Z;
    int m_face2Z;
    int m_markZ;
    int m_caseZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTTC_H
