#include <QTest>

#include "ConvertTest.h"

int main(int argc, char* argv[])
{
    const QApplication a(argc, argv);

    ConvertTest convertTest;
    QTest::qExec(&convertTest);

    return 0;
}
