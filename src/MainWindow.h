#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QMultiMap>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void getWord();

    void on_lineEdit_textChanged(const QString& arg1);

private:
    Ui::MainWindow* ui;

    void ladujDane();

    QMultiMap<QString, QString> slowa_;
};

#endif  // MAINWINDOW_H
