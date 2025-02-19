#include "DataLoaderTest.h"

#include <fstream>
#include <map>
#include <memory>
#include <sstream>

#include <QTest>
#include "src/Mapping.h"

#include <src/DataLoader.h>

namespace
{
std::string getDictionaryEN()
{
    return R"(biology/M
biomarker/MS
biomass/M
biomedical
bionic/S
embraceable
embrasure/MS
embrocation/MS
embroider/SDRZG
marmalade/M
marmoreal
marmoset/SM
scammer/S
scanned
scanner/SM
scanning
scansion/M
)";
}

std::string getDictionaryPL()
{
    return R"(dobić
fobia/ANnp
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
)";
}

std::multimap<QString, QString> getExpectedDataPL()
{
    return {{"36242", "dobić"},
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
}

std::multimap<QString, QString> getExpectedDataEN()
{
    return {{"2465649", "biology"},     {"246627537", "biomarker"},
            {"2466277", "biomass"},     {"2466334225", "biomedical"},
            {"246642", "bionic"},       {"36272232253", "embraceable"},
            {"362727873", "embrasure"}, {"36276228466", "embrocation"},
            {"362764337", "embroider"}, {"627625233", "marmalade"},
            {"627667325", "marmoreal"}, {"62766738", "marmoset"},
            {"7226637", "scammer"},     {"7226633", "scanned"},
            {"7226637", "scanner"},     {"72266464", "scanning"},
            {"72267466", "scansion"}};
}

}  // namespace

void DataLoaderTest::testLoadingPL()
{
    std::string dictionary{getDictionaryPL()};

    auto input{std::make_unique<std::istringstream>(dictionary)};
    DataLoader loader(std::move(input), mapping::getMappingPL());
    std::multimap<QString, QString> actual{loader.getData()};

    std::multimap<QString, QString> expected{getExpectedDataPL()};

    QCOMPARE(actual, expected);
}

void DataLoaderTest::testLoadingEN()
{
    std::string dictionary{getDictionaryEN()};

    auto input{std::make_unique<std::istringstream>(dictionary)};
    DataLoader loader(std::move(input), mapping::getMappingEN());
    std::multimap<QString, QString> actual{loader.getData()};

    std::multimap<QString, QString> expected{getExpectedDataEN()};

    QCOMPARE(actual, expected);
}

void DataLoaderTest::benchmarkLoading()
{
    QSKIP("Skip benchmark.");
    auto inFile{std::make_unique<std::ifstream>("dictionaryPL.dic")};
    DataLoader loader(std::move(inFile), mapping::getMappingPL());
    QBENCHMARK { loader.getData(); }
}
