#ifndef FLIGHTHSI_H
#define FLIGHTHSI_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightHSI : public QGraphicsView
#else
class FlightHSI : public QGraphicsView
#endif

{
    Q_OBJECT

    Q_PROPERTY(float heading READ getHeading WRITE setHeading)

public:
    explicit FlightHSI(QWidget *parent = 0);
    ~FlightHSI();

    void reinit();
    void update();

    float getHeading() const;
    void setHeading(float heading);    

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemCase;

    float m_heading;
    float m_scaleX;
    float m_scaleY;

    int m_originalHeight;
    int m_originalWidth;
    QPointF m_originalHsiCtr;

    int m_faceZ;
    int m_caseZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTHSI_H
