#include <QTest>

#include "ConvertTest.h"
#include "DataLoaderTest.h"
#include "MainWindowTest.h"
#include "MappingTest.h"

int main(int argc, char* argv[])
{
    const QApplication a(argc, argv);

    int status{EXIT_SUCCESS};
    ConvertTest convertTest;
    status = std::max(status, QTest::qExec(&convertTest));

    DataLoaderTest dataLoaderTest;
    status = std::max(status, QTest::qExec(&dataLoaderTest));

    MainWindowTest mainWindowTest;
    status = std::max(status, QTest::qExec(&mainWindowTest));

    MappingTest mappingTest;
    status = std::max(status, QTest::qExec(&mappingTest));

    return status;
}
