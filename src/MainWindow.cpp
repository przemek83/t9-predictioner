#include "MainWindow.h"

#include <QClipboard>
#include <QDebug>
#include <QRegularExpression>

#include "Converter.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->showMessage("Loading dictionary...");

    file_.setFileName("dictionary.dic");

    file_.open(QIODevice::ReadOnly);

    if (file_.isOpen())
        ui->statusBar->showMessage("Dictionary opened...");

    ladujDane();

    ui->statusBar->showMessage("Loaded " + QString::number(slowa_.size()) +
                               " unique combinations.");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ladujDane()
{
    QByteArray wholeText = file_.readAll();

    QString wholeString(wholeText);

    QStringList stringList = wholeString.split('\n');

    ui->statusBar->showMessage(tr("Strings loaded ") +
                               QString::number(stringList.count()));

    // int counter = 0;
    foreach (QString text, stringList)
    {
        int index = text.indexOf('/');

        if (index != -1)
            text.truncate(index);

        //        if(counter <500)
        //        {
        //            qDebug() << text;
        //            counter++;
        //        }

        if (text.contains('-'))
            continue;

        text.replace(QRegularExpression("\\W"), "");
        slowa_.insert(convert(text), text);
    }

    //    counter = 0;
    //    QMultiMap<QString, QString>::iterator i = slowa_.begin();
    //    while (i != slowa_.end())
    //    {
    //        qDebug() << i.value();
    //         ++i;
    //     }
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
