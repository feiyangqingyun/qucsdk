#ifndef FLIGHTASI_H
#define FLIGHTASI_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightASI : public QGraphicsView
#else
class FlightASI : public QGraphicsView
#endif

{
    Q_OBJECT

    Q_PROPERTY(float airspeed READ getAirspeed WRITE setAirspeed)

public:
    explicit FlightASI(QWidget *parent = 0);
    ~FlightASI();

    void reinit();
    void update();

    float getAirspeed() const;
    void setAirspeed(float airspeed);    

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemHand;
    QGraphicsSvgItem *m_itemCase;

    float m_airspeed;
    float m_scaleX;
    float m_scaleY;

    int m_originalHeight;
    int m_originalWidth;
    QPointF m_originalAsiCtr;

    int m_faceZ;
    int m_handZ;
    int m_caseZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTASI_H
