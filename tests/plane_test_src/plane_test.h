#include <QObject>

class QPlaneTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void init();

    void testConstants();
    void testFuelSystem();
    void testDistanceSystem();
    void testSignals();

    void cleanupTestCase();
    void cleanup();
};
