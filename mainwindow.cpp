#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->showMessage("Loading dictionary...");

    file_.setFileName("dictionary.dic");

    file_.open(QIODevice::ReadOnly);

    if(file_.isOpen())
        ui->statusBar->showMessage("Dictionary opened...");

    ladujDane();

    ui->statusBar->showMessage("Loaded " + QString::number(slowa_.size()) + " unique combinations.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ladujDane()
{
    QByteArray wholeText = file_.readAll();

    QString wholeString(wholeText);

    QStringList stringList = wholeString.split('\n');

    ui->statusBar->showMessage(tr("Strings loaded ") + QString::number(stringList.count()));

    //int counter = 0;
    foreach(QString text, stringList)
    {
        int index = text.indexOf('/');


        if(index != -1)
            text.truncate(index);

//        if(counter <500)
//        {
//            qDebug() << text;
//            counter++;
//        }

        if(text.contains('-'))
            continue;

        text.replace(QRegExp("\\W"), "");
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
//    a ą b c ć
//    d e ę f
//    g h i
//    j k l ł
//    m n ń o ó
//    p q r s ś
//    t u v
//    w x y z ź ż;

    static QString dwa("2");
    text.replace(QString("a"), dwa, Qt::CaseInsensitive);
    text.replace(QString("ą"), dwa, Qt::CaseInsensitive);
    text.replace(QString("b"), dwa, Qt::CaseInsensitive);
    text.replace(QString("c"), dwa, Qt::CaseInsensitive);
    text.replace(QString("ć"), dwa, Qt::CaseInsensitive);

    static QString trzy("3");
    text.replace(QString("d"), trzy, Qt::CaseInsensitive);
    text.replace(QString("e"), trzy, Qt::CaseInsensitive);
    text.replace(QString("ę"), trzy, Qt::CaseInsensitive);
    text.replace(QString("f"), trzy, Qt::CaseInsensitive);

    static QString cztery("4");
    text.replace(QString("g"), cztery, Qt::CaseInsensitive);
    text.replace(QString("h"), cztery, Qt::CaseInsensitive);
    text.replace(QString("i"), cztery, Qt::CaseInsensitive);

    static QString piec("5");
    text.replace(QString("j"), piec, Qt::CaseInsensitive);
    text.replace(QString("k"), piec, Qt::CaseInsensitive);
    text.replace(QString("l"), piec, Qt::CaseInsensitive);
    text.replace(QString("ł"), piec, Qt::CaseInsensitive);

    static QString szesc("6");
    text.replace(QString("m"), szesc, Qt::CaseInsensitive);
    text.replace(QString("n"), szesc, Qt::CaseInsensitive);
    text.replace(QString("ń"), szesc, Qt::CaseInsensitive);
    text.replace(QString("o"), szesc, Qt::CaseInsensitive);
    text.replace(QString("ó"), szesc, Qt::CaseInsensitive);

    static QString siedem("7");
    text.replace(QString("p"), siedem, Qt::CaseInsensitive);
    text.replace(QString("q"), siedem, Qt::CaseInsensitive);
    text.replace(QString("r"), siedem, Qt::CaseInsensitive);
    text.replace(QString("s"), siedem, Qt::CaseInsensitive);
    text.replace(QString("ś"), siedem, Qt::CaseInsensitive);

    static QString osiem("8");
    text.replace(QString("t"), osiem, Qt::CaseInsensitive);
    text.replace(QString("u"), osiem, Qt::CaseInsensitive);
    text.replace(QString("v"), osiem, Qt::CaseInsensitive);

    static QString dziewiec("9");
    text.replace(QString("w"), dziewiec, Qt::CaseInsensitive);
    text.replace(QString("x"), dziewiec, Qt::CaseInsensitive);
    text.replace(QString("y"), dziewiec, Qt::CaseInsensitive);
    text.replace(QString("z"), dziewiec, Qt::CaseInsensitive);
    text.replace(QString("ż"), dziewiec, Qt::CaseInsensitive);
    text.replace(QString("ź"), dziewiec, Qt::CaseInsensitive);

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

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::getWord()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(dynamic_cast< QPushButton*>(sender())->text());
}

void MainWindow::on_lineEdit_textChanged(const QString &/*arg1*/)
{
    on_pushButton_clicked();
}
