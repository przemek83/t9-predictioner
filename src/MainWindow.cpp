#include "MainWindow.h"

#include <fstream>

#include <QClipboard>
#include <QDir>
#include <QPushButton>

#include "DataLoader.h"
#include "Mapping.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() : ui_{std::make_unique<Ui::MainWindow>()}
{
    ui_->setupUi(this);

    initiateDictionariesComboBox();

    loadData(ui_->comboBox->currentText());

    connect(ui_->lineEdit, &QLineEdit::textChanged, this,
            &MainWindow::textChanged);

    connect(ui_->comboBox, &QComboBox::currentTextChanged, this,
            &MainWindow::loadData);
}

MainWindow::~MainWindow() = default;

void MainWindow::loadData(const QString& filename)
{
    ui_->statusBar->showMessage("Loading dictionary " + filename + "...");

    QApplication::processEvents();

    auto inFile{std::make_unique<std::ifstream>(filename.toStdString())};
    DataLoader loader(std::move(inFile), mapping::getMappingPL());
    words_ = loader.getData();

    ui_->statusBar->showMessage("Loaded " + QString::number(words_.size()) +
                                " unique combinations.");
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

void MainWindow::initiateDictionariesComboBox()
{
    QDir directory;
    QStringList dicFiles{directory.entryList({"*.dic"}, QDir::Files)};
    for (const QString& filename : dicFiles)
        ui_->comboBox->addItem(filename);
}
