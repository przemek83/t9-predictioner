#pragma once

#include <map>
#include <memory>

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void getWord() const;

    void on_lineEdit_textChanged(const QString& arg1);

private:
    std::unique_ptr<Ui::MainWindow> ui_;

    void ladujDane();

    std::multimap<QString, QString> words_;
};
