#include "DataLoaderTest.h"

#include <QTest>

#include <src/DataLoader.h>

void DataLoaderTest::benchmarkLoading()
{
    QSKIP("Skip benchmark.");
    DataLoader loader("dictionary.dic");
    QBENCHMARK { loader.getData(); }
}
