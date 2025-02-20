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
    void initiateDictionariesComboBox();

    std::unique_ptr<Ui::MainWindow> ui_;

    void loadData(const QString& filename);

    std::multimap<QString, QString> words_;
};
