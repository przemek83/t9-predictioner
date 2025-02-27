#include "MainWindowTest.h"

#include <QTableWidget>
#include <QtTest>

void MainWindowTest::testCreatingTableWidget() const
{
    const auto* tableWidget{window_.findChild<QTableWidget*>()};

    QVERIFY(tableWidget != nullptr);
    QVERIFY(tableWidget->rowCount() == 0);
}