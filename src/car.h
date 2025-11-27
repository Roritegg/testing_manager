#include <QObject>

class QCar : public QObject
{
    Q_OBJECT
public:
    QCar(QObject* parent = nullptr);
    double refuel();
    bool drive(double length);

    inline double getCurrentFuel()
    {return m_currentFuel;}
    inline double getMaxFuel()
    {return m_maxFuel;}
    inline const double getConsuption()
    {return m_consuptionLperKm;}
private:
    const double m_consuptionLperKm = 0.12;
    const double m_maxFuel = 50;
    double m_currentFuel = 0;
};
