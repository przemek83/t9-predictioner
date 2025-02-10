#include "MainWindow.h"

#include <QClipboard>
#include <QDebug>
#include <QRegularExpression>

#include "Converter.h"
#include "DataLoader.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->showMessage("Loading dictionary...");

    ladujDane();

    ui->statusBar->showMessage("Loaded " + QString::number(slowa_.size()) +
                               " unique combinations.");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ladujDane()
{
    DataLoader loader("dictionary.dic");
    slowa_ = loader.getData();

    ui->statusBar->showMessage(tr("Strings loaded ") +
                               QString::number(slowa_.count()));
}

QString MainWindow::convert(QString text)
{
    Converter::convert(text);
    return text;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->clear();

    QList<QString> values = slowa_.values(ui->lineEdit->text());
    ui->tableWidget->setRowCount(values.size());
    for (int i = 0; i < values.size(); ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(values.at(i)));
        QPushButton* button = new QPushButton(values.at(i), ui->tableWidget);
        connect(button, SIGNAL(clicked()), this, SLOT(getWord()));
        ui->tableWidget->setCellWidget(i, 1, button);
    }
}

void MainWindow::on_lineEdit_returnPressed() { on_pushButton_clicked(); }

void MainWindow::getWord()
{
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(dynamic_cast<QPushButton*>(sender())->text());
}

void MainWindow::on_lineEdit_textChanged(const QString& /*arg1*/)
{
    on_pushButton_clicked();
}
