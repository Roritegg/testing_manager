#include "plane.h"
#include <QDebug>

QPlane::QPlane(QObject* parent) : QObject(parent) {}

double QPlane::refuel()
{
    double addedFuel = m_maxFuel - m_currentFuel;
    m_currentFuel = m_maxFuel;

    m_currentFlightDistance = 0.0;

    emit fuelFull();

    return addedFuel;
}

bool QPlane::fly(double length)
{
    const double needFuel = m_consuptionLperKm * length;

    if (m_currentFuel < needFuel) {
        return false;
    }

    m_currentFuel -= needFuel;
    m_totalDistance += length;
    m_currentFlightDistance += length;

    checkFuelLevel();

    return true;
}

void QPlane::checkFuelLevel()
{
    double fuelPercentage = (m_currentFuel / m_maxFuel) * 100.0;

    if (fuelPercentage < 10.0) {
        emit lowFuelWarning();
    }
    if (fuelPercentage >= 100.0) {
        emit fuelFull();
    }
}
