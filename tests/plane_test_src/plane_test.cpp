#include <QTest>
#include <QSignalSpy>
#include "D:\QDocs\lab_8\src\plane.h"
#include "plane_test.h"

void QPlaneTest::initTestCase() {}
void QPlaneTest::init() {}
void QPlaneTest::cleanupTestCase() {}
void QPlaneTest::cleanup() {}

void QPlaneTest::testConstants()
{
    QPlane plane;

    QCOMPARE(plane.getConsumption(), 0.25);
    QCOMPARE(plane.getMaxFuel(), 200.0);
    QCOMPARE(plane.getCurrentFuel(), 0.0);
    QCOMPARE(plane.getTotalDistance(), 0.0);
    QCOMPARE(plane.getCurrentFlightDistance(), 0.0);
}

void QPlaneTest::testFuelSystem()
{
    QPlane plane;

    QCOMPARE(plane.refuel(), 200.0);
    QCOMPARE(plane.getCurrentFuel(), 200.0);
    QVERIFY(plane.fly(100.0));
    QCOMPARE(plane.getCurrentFuel(), 175.0);
    QVERIFY(!plane.fly(1000.0));
    QCOMPARE(plane.getCurrentFuel(), 175.0);
    QCOMPARE(plane.refuel(), 25.0);
    QCOMPARE(plane.getCurrentFuel(), 200.0);
}

void QPlaneTest::testDistanceSystem()
{
    QPlane plane;
    plane.refuel();

    QVERIFY(plane.fly(50.0));
    QCOMPARE(plane.getTotalDistance(), 50.0);
    QCOMPARE(plane.getCurrentFlightDistance(), 50.0);
    QVERIFY(plane.fly(30.0));
    QCOMPARE(plane.getTotalDistance(), 80.0);
    QCOMPARE(plane.getCurrentFlightDistance(), 80.0);

    plane.refuel();
    QCOMPARE(plane.getCurrentFlightDistance(), 0.0);
    QCOMPARE(plane.getTotalDistance(), 80.0);

    QVERIFY(!plane.fly(1000.0));
    QCOMPARE(plane.getTotalDistance(), 80.0);
}

void QPlaneTest::testSignals()
{
    QPlane plane;

    QSignalSpy lowFuelSpy(&plane, &QPlane::lowFuelWarning);
    QSignalSpy fuelFullSpy(&plane, &QPlane::fuelFull);

    plane.refuel();
    QCOMPARE(fuelFullSpy.count(), 1);

    plane.fly(760.0);
    QCOMPARE(lowFuelSpy.count(), 1);

    lowFuelSpy.clear();
    fuelFullSpy.clear();

    plane.fly(10.0);
    QCOMPARE(lowFuelSpy.count(), 1);

    plane.refuel();
    QCOMPARE(fuelFullSpy.count(), 1);
}
