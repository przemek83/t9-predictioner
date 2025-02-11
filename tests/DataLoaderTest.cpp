#include "DataLoaderTest.h"

#include <fstream>
#include <memory>

#include <QTest>

#include <src/DataLoader.h>

void DataLoaderTest::benchmarkLoading()
{
    QSKIP("Skip benchmark.");
    auto inFile{std::make_unique<std::ifstream>("dictionary.dic")};
    DataLoader loader(std::move(inFile));
    QBENCHMARK { loader.getData(); }
}
