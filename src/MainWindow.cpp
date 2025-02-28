#include "MainWindow.h"

#include <fstream>
#include <memory>

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
    clearTableWidget();
    ui_->lineEdit->clear();

    ui_->statusBar->showMessage("Loading dictionary " + filename + "...");

    QApplication::processEvents();

    auto inFile{std::make_unique<std::ifstream>(filename.toStdString())};
    mapping::Language language{mapping::getLanguage(filename)};
    DataLoader loader(std::move(inFile), mapping::getMapping(language));
    words_ = loader.getData();

    ui_->statusBar->showMessage("Loaded " + QString::number(words_.size()) +
                                " unique combinations.");
}

void MainWindow::clearTableWidget()
{
    const int rowCount{ui_->tableWidget->rowCount()};
    for (int row{0}; row < rowCount; ++row)
    {
        std::unique_ptr<QWidget> widget{ui_->tableWidget->cellWidget(row, 1)};
        ui_->tableWidget->removeCellWidget(row, 1);
    }

    ui_->tableWidget->clear();
}

void MainWindow::getWord() const
{
    QClipboard* clipboard{QApplication::clipboard()};
    clipboard->setText(dynamic_cast<QPushButton*>(sender())->text());
}

void MainWindow::textChanged(const QString& text)
{
    clearTableWidget();

    auto [first, last]{words_.equal_range(text)};

    ui_->tableWidget->setRowCount(static_cast<int>(std::distance(first, last)));
    int row{0};
    QStyle::StandardPixmap pixmap{QStyle::SP_BrowserReload};
    for (auto it{first}; it != last; ++it)
    {
        const auto& [_, word]{*it};
        ui_->tableWidget->setItem(row, 0, new QTableWidgetItem(word));

        QPushButton* button{
            new QPushButton(QApplication::style()->standardIcon(pixmap), word,
                            ui_->tableWidget)};
        connect(button, &QPushButton::clicked, this, &MainWindow::getWord);
        ui_->tableWidget->setCellWidget(row, 1, button);
        ++row;
    }
}

void MainWindow::initiateDictionariesComboBox()
{
    QDir directory;
    QStringList dicFiles{directory.entryList({"*.dic"}, QDir::Files)};
    for (const QString& filename : dicFiles)
        ui_->comboBox->addItem(filename);
}
