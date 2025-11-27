#include <QObject>

class QPlane : public QObject
{
    Q_OBJECT
public:
    QPlane(QObject* parent = nullptr);
    double refuel();
    bool fly(double length);

    inline double getCurrentFuel(){
        return m_currentFuel;
    }
    inline double getMaxFuel(){
        return m_maxFuel;
    }
    inline double getConsumption(){
        return m_consuptionLperKm;
    }
    inline double getTotalDistance(){
        return m_totalDistance;
    }
    inline double getCurrentFlightDistance(){
        return m_currentFlightDistance;
    }

signals:
    void lowFuelWarning();
    void fuelFull();

private:
    const double m_consuptionLperKm = 0.25;
    const double m_maxFuel = 200.0;
    double m_currentFuel = 0.0;
    double m_totalDistance = 0.0;
    double m_currentFlightDistance = 0.0;

    void checkFuelLevel();
};
