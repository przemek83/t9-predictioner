#include <QApplication>
#include "mainwindow.h"

// #include <QTextCodec>
#include <QTranslator>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("qt_pl.qm", QCoreApplication::applicationDirPath());
    a.installTranslator(&translator);

    //    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));

    MainWindow w;
    w.show();

    return a.exec();
}
