#pragma once

#include <QObject>
#include <memory>

#include "src/MainWindow.h"

class MainWindowTest : public QObject
{
    Q_OBJECT

private:
    QStringList dictionaryFile_{":/res/testDictionaryEN.dic"};
    MainWindow window_{dictionaryFile_};

private Q_SLOTS:
    void testCreatingTableWidget();

    void testChangingText();

    void testCopyingToClipboard();
};
