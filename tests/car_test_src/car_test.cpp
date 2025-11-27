#include "car_test.h"
#include "D:\QDocs\lab_8\src\car.h"
#include <QTest>

void QCarTest::initTestCase(){}

void QCarTest::init(){}

void QCarTest::cleanupTestCase(){}

void QCarTest::cleanup(){}

void QCarTest::testConstants()
{
    QCar car;

    QCOMPARE(0.12, car.getConsuption());
    QCOMPARE(50.0, car.getMaxFuel());
    QCOMPARE(0.0, car.getCurrentFuel());
}
void QCarTest::testFuel()
{
    QCar car;
    QCOMPARE(car.refuel(), 50.0);
    QCOMPARE(car.getCurrentFuel(), car.getMaxFuel());
    const double maxDistance = car.getMaxFuel() / car.getConsuption();
    QVERIFY(car.drive(maxDistance));
    QCOMPARE(0.0,car.getCurrentFuel());
    QCOMPARE(car.refuel(), 50.0);
    QCOMPARE(car.getCurrentFuel(), car.getMaxFuel());
    QVERIFY(!car.drive(maxDistance + 1.0));
    QCOMPARE(car.getCurrentFuel(), car.getMaxFuel());
}
