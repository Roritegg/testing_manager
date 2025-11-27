#include <QObject>

class QCarTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void init();

    void testConstants();
    void testFuel();

    void cleanupTestCase();
    void cleanup();
};
