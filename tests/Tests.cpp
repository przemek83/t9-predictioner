#include <QTest>

#include "ConvertTest.h"
#include "DataLoaderTest.h"
#include "MainWindowTest.h"
#include "MappingTest.h"

int main(int argc, char* argv[])
{
    const QApplication a(argc, argv);

    ConvertTest convertTest;
    QTest::qExec(&convertTest);

    DataLoaderTest dataLoaderTest;
    QTest::qExec(&dataLoaderTest);

    MainWindowTest mainWindowTest;
    QTest::qExec(&mainWindowTest);

    MappingTest mappingTest;
    QTest::qExec(&mappingTest);

    return 0;
}
