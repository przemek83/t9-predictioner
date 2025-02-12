#include "MainWindow.h"

#include <fstream>

#include <QClipboard>

#include "DataLoader.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() : ui_{std::make_unique<Ui::MainWindow>()}
{
    ui_->setupUi(this);

    ui_->statusBar->showMessage("Loading dictionary...");

    ladujDane();

    ui_->statusBar->showMessage("Loaded " + QString::number(words_.size()) +
                                " unique combinations.");
}

MainWindow::~MainWindow() = default;

void MainWindow::ladujDane()
{
    auto inFile{std::make_unique<std::ifstream>("dictionary.dic")};
    DataLoader loader(std::move(inFile));
    words_ = loader.getData();

    ui_->statusBar->showMessage(tr("Strings loaded ") +
                                QString::number(words_.size()));
}

void MainWindow::on_pushButton_clicked()
{
    ui_->tableWidget->clear();

    auto [first, last]{words_.equal_range(ui_->lineEdit->text())};

    ui_->tableWidget->setRowCount(static_cast<int>(std::distance(first, last)));
    int index{0};
    for (auto it{first}; it != last; ++it)
    {
        const auto& [_, word]{*it};
        ui_->tableWidget->setItem(index, 0, new QTableWidgetItem(word));
        QPushButton* button{new QPushButton(word, ui_->tableWidget)};
        connect(button, SIGNAL(clicked()), this, SLOT(getWord()));
        ui_->tableWidget->setCellWidget(index, 1, button);
        ++index;
    }
}

void MainWindow::on_lineEdit_returnPressed() { on_pushButton_clicked(); }

void MainWindow::getWord() const
{
    QClipboard* clipboard{QApplication::clipboard()};
    clipboard->setText(dynamic_cast<QPushButton*>(sender())->text());
}

void MainWindow::on_lineEdit_textChanged(const QString& /*arg1*/)
{
    on_pushButton_clicked();
}
