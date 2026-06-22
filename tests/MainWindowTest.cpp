#include "MainWindowTest.h"

#include <QClipboard>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QtTest>

void MainWindowTest::initTestCase()
{
    const QString dicName{"dictionaryEN.dic"};
    QFile file(dicName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "did\n";
        out << "die\n";
        out << "fie\n";
        out << "eh\n";
        file.close();
    }

    window_ = std::make_unique<MainWindow>(QStringList() << dicName);
}

void MainWindowTest::cleanupTestCase()
{
    window_.reset();
    const QString dicName{"dictionaryEN.dic"};
    QFile::remove(dicName);
}

void MainWindowTest::testCreatingTableWidget()
{
    const auto* tableWidget{window_->findChild<QTableWidget*>()};

    QVERIFY(tableWidget != nullptr);
    QVERIFY(tableWidget->rowCount() == 0);
}

void MainWindowTest::testChangingText()
{
    auto* lineEdit{window_->findChild<QLineEdit*>()};
    const auto* tableWidget{window_->findChild<QTableWidget*>()};

    lineEdit->setText("343");

    QVERIFY(tableWidget->rowCount() == 3);

    QStringList expected{"did", "die", "fie"};

    QStringList current;
    const int rowCount{tableWidget->rowCount()};
    for (int i{0}; i < rowCount; ++i)
        current.append(tableWidget->item(i, 0)->text());

    QVERIFY(expected == current);
}

void MainWindowTest::testCopyingToClipboard()
{
    auto* lineEdit{window_->findChild<QLineEdit*>()};
    lineEdit->setText("34");

    auto* button{window_->findChild<QPushButton*>()};
    button->click();

    const auto* clipboard{QGuiApplication::clipboard()};
    QVERIFY(clipboard->text() == "eh");
}
