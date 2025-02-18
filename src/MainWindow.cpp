#include "MainWindow.h"

#include <fstream>

#include <QClipboard>
#include <QPushButton>

#include "DataLoader.h"
#include "Mapping.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() : ui_{std::make_unique<Ui::MainWindow>()}
{
    ui_->setupUi(this);

    ui_->statusBar->showMessage("Loading dictionary...");

    loadData();

    ui_->statusBar->showMessage("Loaded " + QString::number(words_.size()) +
                                " unique combinations.");

    connect(ui_->lineEdit, &QLineEdit::textChanged, this,
            &MainWindow::textChanged);
}

MainWindow::~MainWindow() = default;

void MainWindow::loadData()
{
    auto inFile{std::make_unique<std::ifstream>("dictionaryPL.dic")};
    DataLoader loader(std::move(inFile), mapping::getMappingPL());
    words_ = loader.getData();
}

void MainWindow::getWord() const
{
    QClipboard* clipboard{QApplication::clipboard()};
    clipboard->setText(dynamic_cast<QPushButton*>(sender())->text());
}

void MainWindow::textChanged(const QString& text)
{
    ui_->tableWidget->clear();

    auto [first, last]{words_.equal_range(text)};

    ui_->tableWidget->setRowCount(static_cast<int>(std::distance(first, last)));
    int index{0};
    for (auto it{first}; it != last; ++it)
    {
        const auto& [_, word]{*it};
        ui_->tableWidget->setItem(index, 0, new QTableWidgetItem(word));
        QPushButton* button{new QPushButton(word, ui_->tableWidget)};
        connect(button, &QPushButton::clicked, this, &MainWindow::getWord);
        ui_->tableWidget->setCellWidget(index, 1, button);
        ++index;
    }
}
