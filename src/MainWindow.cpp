#include "MainWindow.h"

#include <fstream>

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

    ui->statusBar->showMessage("Loaded " + QString::number(words_.size()) +
                               " unique combinations.");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ladujDane()
{
    auto inFile{std::make_unique<std::ifstream>("dictionary.dic")};
    DataLoader loader(std::move(inFile));
    words_ = loader.getData();

    ui->statusBar->showMessage(tr("Strings loaded ") +
                               QString::number(words_.size()));
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->clear();

    auto [first, last]{words_.equal_range(ui->lineEdit->text())};

    ui->tableWidget->setRowCount(static_cast<int>(std::distance(first, last)));
    int index{0};
    for (auto el = first; el != last; ++el)
    {
        qDebug() << el->first << ": " << el->second << '\n';
        ui->tableWidget->setItem(index, 0, new QTableWidgetItem(el->second));
        QPushButton* button = new QPushButton(el->second, ui->tableWidget);
        connect(button, SIGNAL(clicked()), this, SLOT(getWord()));
        ui->tableWidget->setCellWidget(index, 1, button);
        ++index;
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
