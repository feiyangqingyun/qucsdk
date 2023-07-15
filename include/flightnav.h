#ifndef FLIGHTNAV_H
#define FLIGHTNAV_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightNAV : public QGraphicsView
#else
class FlightNAV : public QGraphicsView
#endif

{
    Q_OBJECT

    Q_PROPERTY(float heading READ getHeading WRITE setHeading)
    Q_PROPERTY(float headingBug READ getHeadingBug WRITE setHeadingBug)
    Q_PROPERTY(float course READ getCourse WRITE setCourse)

    Q_PROPERTY(float bearing READ getBearing WRITE setBearing)
    Q_PROPERTY(bool bearingVisible READ getBearingVisible WRITE setBearingVisible)

    Q_PROPERTY(float deviation READ getDeviation WRITE setDeviation)
    Q_PROPERTY(bool deviationVisible READ getDeviationVisible WRITE setDeviationVisible)

    Q_PROPERTY(float distance READ getDistance WRITE setDistance)
    Q_PROPERTY(bool distanceVisible READ getDistanceVisible WRITE setDistanceVisible)

public:
    explicit FlightNAV(QWidget *parent = 0);
    ~FlightNAV();

    void reinit();
    void update();

    float getHeading() const;
    void setHeading(float heading);

    float getHeadingBug() const;
    void setHeadingBug(float headingBug);

    float getCourse() const;
    void setCourse(float course);

    float getBearing() const;
    void setBearing(float bearing);
    bool getBearingVisible() const;
    void setBearingVisible(bool visible);

    float getDeviation() const;
    void setDeviation(float deviation);
    bool getDeviationVisible() const;
    void setDeviationVisible(bool visible);

    float getDistance() const;
    void setDistance(float distance);
    bool getDistanceVisible() const;
    void setDistanceVisible(bool visible);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemBack;
    QGraphicsSvgItem *m_itemMask;
    QGraphicsSvgItem *m_itemMark;

    QGraphicsSvgItem *m_itemBrgArrow;
    QGraphicsSvgItem *m_itemCrsArrow;
    QGraphicsSvgItem *m_itemDevBar;
    QGraphicsSvgItem *m_itemDevScale;
    QGraphicsSvgItem *m_itemHdgBug;
    QGraphicsSvgItem *m_itemHdgScale;

    QGraphicsTextItem *m_itemCrsText;
    QGraphicsTextItem *m_itemHdgText;
    QGraphicsTextItem *m_itemDmeText;

    QColor m_crsTextColor;
    QColor m_hdgTextColor;
    QColor m_dmeTextColor;

    QFont  m_crsTextFont;
    QFont  m_hdgTextFont;
    QFont  m_dmeTextFont;

    float m_heading;
    float m_headingBug;
    float m_course;
    float m_bearing;
    float m_deviation;
    float m_distance;

    bool m_bearingVisible;
    bool m_deviationVisible;
    bool m_distanceVisible;

    float m_devBarDeltaX_new;
    float m_devBarDeltaX_old;
    float m_devBarDeltaY_new;
    float m_devBarDeltaY_old;

    float m_scaleX;
    float m_scaleY;
    float m_originalPixPerDev;

    QPointF m_originalNavCtr;
    QPointF m_originalCrsTextCtr;
    QPointF m_originalHdgTextCtr;
    QPointF m_originalDmeTextCtr;

    int m_originalHeight;
    int m_originalWidth;

    int m_backZ;
    int m_maskZ;
    int m_markZ;

    int m_brgArrowZ;
    int m_crsArrowZ;
    int m_crsTextZ;
    int m_devBarZ;
    int m_devScaleZ;
    int m_hdgBugZ;
    int m_hdgScaleZ;
    int m_hdgTextZ;
    int m_dmeTextZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTNAV_H
