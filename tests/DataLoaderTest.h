#pragma once

#include <QObject>

class DataLoaderTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    static void testLoading();

    static void benchmarkLoading();
};
