#ifndef FLIGHTVSI_H
#define FLIGHTVSI_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightVSI : public QGraphicsView
#else
class FlightVSI : public QGraphicsView
#endif

{
    Q_OBJECT

    Q_PROPERTY(float climbRate READ getClimbRate WRITE setClimbRate)

public:
    explicit FlightVSI(QWidget *parent = 0);
    ~FlightVSI();

    void reinit();
    void update();

    float getClimbRate() const;
    void setClimbRate(float climbRate);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemHand;
    QGraphicsSvgItem *m_itemCase;

    float m_climbRate;
    float m_scaleX;
    float m_scaleY;

    int m_originalHeight;
    int m_originalWidth;
    QPointF m_originalVsiCtr;

    int m_faceZ;
    int m_handZ;
    int m_caseZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTVSI_H
