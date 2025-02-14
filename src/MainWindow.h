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
    void getWord() const;

    void textChanged(const QString& text);

private:
    std::unique_ptr<Ui::MainWindow> ui_;

    void loadData();

    std::multimap<QString, QString> words_;
};
