#ifndef FLIGHTALT_H
#define FLIGHTALT_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightALT : public QGraphicsView
#else
class FlightALT : public QGraphicsView
#endif

{
    Q_OBJECT

    Q_PROPERTY(float altitude READ getAltitude WRITE setAltitude)
    Q_PROPERTY(float pressure READ getPressure WRITE setPressure)

public:
    explicit FlightALT(QWidget *parent = 0);
    ~FlightALT();

    void reinit();
    void update();

    float getAltitude() const;
    void setAltitude(float altitude);

    float getPressure() const;
    void setPressure(float aressure);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemFace_1;
    QGraphicsSvgItem *m_itemFace_2;
    QGraphicsSvgItem *m_itemFace_3;
    QGraphicsSvgItem *m_itemHand_1;
    QGraphicsSvgItem *m_itemHand_2;
    QGraphicsSvgItem *m_itemCase;

    float m_altitude;
    float m_pressure;

    float m_scaleX;
    float m_scaleY;

    int m_originalHeight;
    int m_originalWidth;
    QPointF m_originalAltCtr;

    int m_face1Z;
    int m_face2Z;
    int m_face3Z;
    int m_hand1Z;
    int m_hand2Z;
    int m_caseZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTALT_H
