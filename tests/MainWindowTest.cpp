#include "MainWindowTest.h"

#include <QClipboard>
#include <QLineEdit>
#include <QTableWidget>
#include <QtTest>

void MainWindowTest::testCreatingTableWidget() const
{
    const auto* tableWidget{window_.findChild<QTableWidget*>()};

    QVERIFY(tableWidget != nullptr);
    QVERIFY(tableWidget->rowCount() == 0);
}

void MainWindowTest::testChangingText() const
{
    auto* lineEdit{window_.findChild<QLineEdit*>()};
    const auto* tableWidget{window_.findChild<QTableWidget*>()};

    lineEdit->setText("343");

    QVERIFY(tableWidget->rowCount() == 3);

    QStringList expected{"did", "die", "fie"};

    QStringList current;
    const int rowCount{tableWidget->rowCount()};
    for (int i{0}; i < rowCount; ++i)
        current.append(tableWidget->item(i, 0)->text());

    QVERIFY(expected == current);
}

void MainWindowTest::testCopyingToClipboard() const
{
    auto* lineEdit{window_.findChild<QLineEdit*>()};
    auto* tableWidget{window_.findChild<QTableWidget*>()};

    lineEdit->setText("34");

    tableWidget->selectRow(0);
    QTest::keyClick(tableWidget, Qt::Key_C, Qt::ControlModifier);

    const auto* clipboard{QGuiApplication::clipboard()};
    QVERIFY(clipboard->text() == "eh");
}