#ifndef FLIGHTADI_H
#define FLIGHTADI_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightADI : public QGraphicsView
#else
class FlightADI : public QGraphicsView
#endif

{
    Q_OBJECT

    Q_PROPERTY(float roll READ getRoll WRITE setRoll)
    Q_PROPERTY(float pitch READ getPitch WRITE setPitch)

public:
    explicit FlightADI(QWidget *parent = 0);
    ~FlightADI();

    void reinit();
    void update();

    float getRoll() const;
    void setRoll(float roll);

    float getPitch() const;
    void setPitch(float pitch);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemBack;
    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemRing;
    QGraphicsSvgItem *m_itemCase;

    float m_roll;
    float m_pitch;

    float m_faceDeltaX_new;
    float m_faceDeltaX_old;
    float m_faceDeltaY_new;
    float m_faceDeltaY_old;

    float m_scaleX;
    float m_scaleY;

    int m_originalHeight;
    int m_originalWidth;

    float m_originalPixPerDeg;
    QPointF m_originalAdiCtr;

    int m_backZ;
    int m_faceZ;
    int m_ringZ;
    int m_caseZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTADI_H
