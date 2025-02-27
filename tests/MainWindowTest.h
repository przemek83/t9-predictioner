#pragma once

#include <QObject>

#include "src/MainWindow.h"

class MainWindowTest : public QObject
{
    Q_OBJECT

private:
    MainWindow window_;

private Q_SLOTS:
    void testCreatingTableWidget() const;

    void testChangingText() const;

    void testCopyingToClipboard() const;
};
