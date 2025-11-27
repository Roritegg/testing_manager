#include "car.h"
#include <QObject>

QCar::QCar(QObject* parent) :
    QObject(parent){}

double QCar::refuel()
{
    double addedFuel = m_maxFuel - m_currentFuel;
    m_currentFuel = m_maxFuel;
    return addedFuel;
}

bool QCar::drive(double length)
{
    const double needFuel = m_consuptionLperKm * length;

    if(m_currentFuel < needFuel)
        return false;

    m_currentFuel -= needFuel;
    return true;
}
