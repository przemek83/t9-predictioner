#include <QApplication>
#include <QDir>

#include "MainWindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QDir directory;
    const QStringList dictionaryFiles{directory.entryList({"*.dic"}, QDir::Files)};
    MainWindow w(dictionaryFiles);
    w.show();

    return QApplication::exec();
}
