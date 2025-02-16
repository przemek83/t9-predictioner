#include "DataLoaderTest.h"

#include <sstream>
#include <fstream>
#include <map>
#include <memory>

#include <QTest>

#include <src/DataLoader.h>

void DataLoaderTest::testLoading()
{
    std::string dictionary{R"(fobia/ANnp
fochy/lW
focoso
focus/NOsTQ
techno
technocentryczny/bXxY
technocentryzm/NQsT
technofobia/AnNp
wysmakowanie/UV
wysmakowany/bXxY
wysmakowawszy
)"};

    auto input{std::make_unique<std::istringstream>(dictionary)};
    DataLoader loader(std::move(input));
    std::multimap<QString, QString> actual{loader.getData()};

    std::multimap<QString, QString> expected{
        {"36242", "fobia"},
        {"36249", "fochy"},
        {"362676", "focoso"},
        {"36287", "focus"},
        {"832466", "techno"},
        {"8324662368792969", "technocentryczny"},
        {"83246623687996", "technocentryzm"},
        {"83246636242", "technofobia"},
        {"997625692643", "wysmakowanie"},
        {"99762569269", "wysmakowany"},
        {"9976256929799", "wysmakowawszy"}};

    QCOMPARE(actual, expected);
}

void DataLoaderTest::benchmarkLoading()
{
    QSKIP("Skip benchmark.");
    auto inFile{std::make_unique<std::ifstream>("dictionary.dic")};
    DataLoader loader(std::move(inFile));
    QBENCHMARK { loader.getData(); }
}
