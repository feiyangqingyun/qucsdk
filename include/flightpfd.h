#ifndef FLIGHTPFD_H
#define FLIGHTPFD_H

#include <QGraphicsView>
class QGraphicsSvgItem;

#ifdef quc
class Q_DECL_EXPORT FlightPFD : public QGraphicsView
#else
class FlightPFD : public QGraphicsView
#endif

{
    Q_OBJECT

public:
    enum PressureUnit {
        STD = 0,
        MB,
        IN
    };

    explicit FlightPFD(QWidget *parent = 0);
    ~FlightPFD();

    void reinit();
    void update();

    void setRoll(float roll);
    void setPitch(float pitch);
    void setFlightPathMarker(float aoa, float sideslip, bool visible);
    void setSlipSkid(float slipSkid);
    void setTurnRate(float turnRate);

    void setBarH(float barH, bool visible);
    void setBarV(float barV, bool visible);
    void setDotH(float dotH, bool visible);
    void setDotV(float dotV, bool visible);

    void setAltitude(float altitude);
    void setPressure(float pressure, PressureUnit pressureUnit);

    void setAirspeed(float airspeed);
    void setMachNo(float machNo);

    void setHeading(float heading);
    void setClimbRate(float climbRate);
    void setIdent(const QString &ident, bool visible);
    void setDistance(float dist, bool visible);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    class ADI
    {
    public:
        ADI(QGraphicsScene *scene);
        void init(float scaleX, float scaleY);
        void update(float scaleX, float scaleY);
        void setRoll(float roll);
        void setPitch(float pitch);
        void setFlightPathMarker(float aoa, float sideslip, bool visible = true);
        void setSlipSkid(float slipSkid);
        void setTurnRate(float turnRate);
        void setBarH(float barH, bool visible = true);
        void setBarV(float barV, bool visible = true);
        void setDotH(float dotH, bool visible = true);
        void setDotV(float dotV, bool visible = true);

    private:
        QGraphicsScene *m_scene;
        QGraphicsSvgItem *m_itemBack;
        QGraphicsSvgItem *m_itemLadd;
        QGraphicsSvgItem *m_itemRoll;
        QGraphicsSvgItem *m_itemSlip;
        QGraphicsSvgItem *m_itemTurn;
        QGraphicsSvgItem *m_itemPath;
        QGraphicsSvgItem *m_itemMark;
        QGraphicsSvgItem *m_itemBarH;
        QGraphicsSvgItem *m_itemBarV;
        QGraphicsSvgItem *m_itemDotH;
        QGraphicsSvgItem *m_itemDotV;
        QGraphicsSvgItem *m_itemMask;
        QGraphicsSvgItem *m_itemScaleH;
        QGraphicsSvgItem *m_itemScaleV;

        float m_roll;
        float m_pitch;
        float m_angleOfAttack;
        float m_sideslipAngle;
        float m_slipSkid;
        float m_turnRate;
        float m_barH;
        float m_barV;
        float m_dotH;
        float m_dotV;

        bool m_pathValid;
        bool m_pathVisible;
        bool m_barHVisible;
        bool m_barVVisible;
        bool m_dotHVisible;
        bool m_dotVVisible;

        float m_laddDeltaX_new;
        float m_laddDeltaX_old;
        float m_laddBackDeltaX_new;
        float m_laddBackDeltaX_old;
        float m_laddBackDeltaY_new;
        float m_laddBackDeltaY_old;
        float m_laddDeltaY_new;
        float m_laddDeltaY_old;
        float m_slipDeltaX_new;
        float m_slipDeltaX_old;
        float m_slipDeltaY_new;
        float m_slipDeltaY_old;
        float m_turnDeltaX_new;
        float m_turnDeltaX_old;
        float m_pathDeltaX_new;
        float m_pathDeltaX_old;
        float m_pathDeltaY_new;
        float m_pathDeltaY_old;
        float m_markDeltaX_new;
        float m_markDeltaX_old;
        float m_markDeltaY_new;
        float m_markDeltaY_old;
        float m_barHDeltaX_new;
        float m_barHDeltaX_old;
        float m_barVDeltaY_new;
        float m_barVDeltaY_old;
        float m_dotHDeltaX_new;
        float m_dotHDeltaX_old;
        float m_dotVDeltaY_new;
        float m_dotVDeltaY_old;

        float m_scaleX;
        float m_scaleY;

        float m_originalPixPerDeg;
        float m_deltaLaddBack_max;
        float m_deltaLaddBack_min;
        float m_maxSlipDeflection;
        float m_maxTurnDeflection;
        float m_maxBarsDeflection;
        float m_maxDotsDeflection;

        QPointF m_originalAdiCtr;
        QPointF m_originalBackPos;
        QPointF m_originalLaddPos;
        QPointF m_originalRollPos;
        QPointF m_originalSlipPos;
        QPointF m_originalTurnPos;
        QPointF m_originalPathPos;
        QPointF m_originalBarHPos;
        QPointF m_originalBarVPos;
        QPointF m_originalDotHPos;
        QPointF m_originalDotVPos;
        QPointF m_originalScaleHPos;
        QPointF m_originalScaleVPos;

        int m_backZ;
        int m_laddZ;
        int m_rollZ;
        int m_slipZ;
        int m_pathZ;
        int m_barsZ;
        int m_dotsZ;
        int m_scalesZ;
        int m_maskZ;
        int m_turnZ;

        void reset();
        void updateLadd(float delta, float sinRoll, float cosRoll);
        void updateLaddBack(float delta, float sinRoll, float cosRoll);
        void updateRoll();
        void updateSlipSkid(float sinRoll, float cosRoll);
        void updateTurnRate();
        void updateFlightPath();
        void updateBars();
        void updateDots();
    };

    class ALT
    {
    public:
        ALT(QGraphicsScene *scene);
        void init(float scaleX, float scaleY);
        void update(float scaleX, float scaleY);
        void setAltitude(float altitude);
        void setPressure(float pressure, int pressureUnit);

    private:
        QGraphicsScene *m_scene;
        QGraphicsSvgItem  *m_itemBack;
        QGraphicsSvgItem  *m_itemScale1;
        QGraphicsSvgItem  *m_itemScale2;
        QGraphicsTextItem *m_itemLabel1;
        QGraphicsTextItem *m_itemLabel2;
        QGraphicsTextItem *m_itemLabel3;
        QGraphicsSvgItem  *m_itemGround;
        QGraphicsSvgItem  *m_itemFrame;
        QGraphicsTextItem *m_itemAltitude;
        QGraphicsTextItem *m_itemPressure;

        QColor m_frameTextColor;
        QColor m_pressTextColor;
        QColor m_labelsColor;

        QFont  m_frameTextFont;
        QFont  m_labelsFont;

        float m_altitude;
        float m_pressure;
        int m_pressureUnit;

        float m_scale1DeltaY_new;
        float m_scale1DeltaY_old;
        float m_scale2DeltaY_new;
        float m_scale2DeltaY_old;
        float m_groundDeltaY_new;
        float m_groundDeltaY_old;
        float m_labelsDeltaY_new;
        float m_labelsDeltaY_old;

        float m_scaleX;
        float m_scaleY;

        const float m_originalPixPerAlt;
        const float m_originalScaleHeight;
        const float m_originalLabelsX;
        const float m_originalLabel1Y;
        const float m_originalLabel2Y;
        const float m_originalLabel3Y;

        QPointF m_originalBackPos;
        QPointF m_originalScale1Pos;
        QPointF m_originalScale2Pos;
        QPointF m_originalGroundPos;
        QPointF m_originalFramePos;
        QPointF m_originalAltitudeCtr;
        QPointF m_originalPressureCtr;

        const int m_backZ;
        const int m_scaleZ;
        const int m_labelsZ;
        const int m_groundZ;
        const int m_frameZ;
        const int m_frameTextZ;

        void reset();
        void updateAltitude();
        void updatePressure();
        void updateScale();
        void updateScaleLabels();
    };

    class ASI
    {
    public:
        ASI(QGraphicsScene *scene);
        void init(float scaleX, float scaleY);
        void update(float scaleX, float scaleY);
        void setAirspeed(float airspeed);
        void setMachNo(float machNo);

    private:
        QGraphicsScene *m_scene;
        QGraphicsSvgItem  *m_itemBack;
        QGraphicsSvgItem  *m_itemScale1;
        QGraphicsSvgItem  *m_itemScale2;
        QGraphicsTextItem *m_itemLabel1;
        QGraphicsTextItem *m_itemLabel2;
        QGraphicsTextItem *m_itemLabel3;
        QGraphicsTextItem *m_itemLabel4;
        QGraphicsTextItem *m_itemLabel5;
        QGraphicsTextItem *m_itemLabel6;
        QGraphicsTextItem *m_itemLabel7;
        QGraphicsSvgItem  *m_itemFrame;
        QGraphicsTextItem *m_itemAirspeed;
        QGraphicsTextItem *m_itemMachNo;

        QColor m_frameTextColor;
        QColor m_labelsColor;

        QFont  m_frameTextFont;
        QFont  m_labelsFont;

        float m_airspeed;
        float m_machNo;

        float m_scale1DeltaY_new;
        float m_scale1DeltaY_old;
        float m_scale2DeltaY_new;
        float m_scale2DeltaY_old;
        float m_labelsDeltaY_new;
        float m_labelsDeltaY_old;

        float m_scaleX;
        float m_scaleY;

        const float m_originalPixPerSpd;
        const float m_originalScaleHeight;
        const float m_originalLabelsX;
        const float m_originalLabel1Y;
        const float m_originalLabel2Y;
        const float m_originalLabel3Y;
        const float m_originalLabel4Y;
        const float m_originalLabel5Y;
        const float m_originalLabel6Y;
        const float m_originalLabel7Y;

        QPointF m_originalBackPos;
        QPointF m_originalScale1Pos;
        QPointF m_originalScale2Pos;
        QPointF m_originalFramePos;
        QPointF m_originalAirspeedCtr;
        QPointF m_originalMachNoCtr;

        const int m_backZ;
        const int m_scaleZ;
        const int m_labelsZ;
        const int m_frameZ;
        const int m_frameTextZ;

        void reset();
        void updateAirspeed();
        void updateScale();
        void updateScaleLabels();
    };

    class HSI
    {
    public:
        HSI(QGraphicsScene *scene);
        void init(float scaleX, float scaleY);
        void update(float scaleX, float scaleY);
        void setHeading(float heading);

    private:
        QGraphicsScene *m_scene;
        QGraphicsSvgItem  *m_itemBack;
        QGraphicsSvgItem  *m_itemFace;
        QGraphicsSvgItem  *m_itemMarks;
        QGraphicsTextItem *m_itemFrameText;

        QColor m_frameTextColor;
        QFont  m_frameTextFont;

        float m_heading;
        float m_scaleX;
        float m_scaleY;

        QPointF m_originalHsiCtr;
        QPointF m_originalBackPos;
        QPointF m_originalFacePos;
        QPointF m_originalMarksPos;
        QPointF m_originalFrameTextCtr;

        const int m_backZ;
        const int m_faceZ;
        const int m_marksZ;
        const int m_frameTextZ;

        void reset();
        void updateHeading();
    };

    class VSI
    {
    public:
        VSI(QGraphicsScene *scene);
        void init(float scaleX, float scaleY);
        void update(float scaleX, float scaleY);
        void setClimbRate(float climbRate);

    private:
        QGraphicsScene *m_scene;
        QGraphicsSvgItem  *m_itemScale;
        QGraphicsSvgItem  *m_itemArrow;

        float m_climbRate;
        float m_arrowDeltaY_new;
        float m_arrowDeltaY_old;

        float m_scaleX;
        float m_scaleY;

        const float m_originalMarkeHeight;
        const float m_originalPixPerSpd1;
        const float m_originalPixPerSpd2;
        const float m_originalPixPerSpd4;

        QPointF m_originalScalePos;
        QPointF m_originalArrowPos;

        const int m_scaleZ;
        const int m_arrowZ;

        void reset();
        void updateVSI();
    };

    class ILS
    {
    public:
        ILS(QGraphicsScene *scene);
        void init(float scaleX, float scaleY);
        void update(float scaleX, float scaleY);
        void setIdentifier(const QString &ident, bool visible);
        void setDistance(float dist, bool visible);

    private:
        QGraphicsScene *m_scene;
        QGraphicsTextItem *m_itemIdentText;
        QGraphicsTextItem *m_itemDistText;

        float m_distance;
        QString m_identifier;

        bool m_Dist_Visible;
        bool m_Ident_Visible;

        float m_scaleX;
        float m_scaleY;

        QPointF m_originalIdentPos;
        QPointF m_originalDistPos;

        const int m_identZ;
        const int m_distZ;

        QColor m_textColor;
        QFont  m_identFont;
        QFont  m_distFont;

        void reset();
        void updateILS();
    };

    QGraphicsScene *m_scene;

    ADI *m_adi;
    ALT *m_alt;
    ASI *m_asi;
    HSI *m_hsi;
    VSI *m_vsi;
    ILS *m_ils;

    QGraphicsSvgItem *m_itemBack;
    QGraphicsSvgItem *m_itemMask;

    float m_scaleX;
    float m_scaleY;

    int m_originalHeight;
    int m_originalWidth;

    int m_backZ;
    int m_maskZ;

    void init();
    void reset();
    void updateView();
};

#endif // FLIGHTPFD_H
