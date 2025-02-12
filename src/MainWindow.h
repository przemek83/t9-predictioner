#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <map>

#include <QFile>
#include <QMainWindow>
#include <memory>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void getWord();

    void on_lineEdit_textChanged(const QString& arg1);

private:
    std::unique_ptr<Ui::MainWindow> ui_;

    void ladujDane();

    std::multimap<QString, QString> words_;
};

#endif  // MAINWINDOW_H
