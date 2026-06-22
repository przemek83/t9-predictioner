#pragma once

#include <QObject>
#include <memory>

#include "src/MainWindow.h"

class MainWindowTest : public QObject
{
    Q_OBJECT

private:
    std::unique_ptr<MainWindow> window_;

private Q_SLOTS:
    void initTestCase();

    void cleanupTestCase();

    void testCreatingTableWidget();

    void testChangingText();

    void testCopyingToClipboard();
};
