#include <QTest>

#include "ConvertTest.h"
#include "DataLoaderTest.h"

int main(int argc, char* argv[])
{
    const QApplication a(argc, argv);

    ConvertTest convertTest;
    QTest::qExec(&convertTest);

    DataLoaderTest dataLoaderTest;
    QTest::qExec(&dataLoaderTest);

    return 0;
}
