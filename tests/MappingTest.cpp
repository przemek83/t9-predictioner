#include "MappingTest.h"

#include <QtTest>

#include <src/Mapping.h>

void MappingTest::testGetLanguage() const
{
    QCOMPARE(mapping::getLanguage("dictionary_pl.dic"), mapping::Language::PL);
    QCOMPARE(mapping::getLanguage("dictionary_en.dic"), mapping::Language::EN);
    QCOMPARE(mapping::getLanguage("dictionaryPL.dic"), mapping::Language::PL);
    QCOMPARE(mapping::getLanguage("dictionaryEN.dic"), mapping::Language::EN);
    QCOMPARE(mapping::getLanguage("dictionary.txt"),
             mapping::Language::UNKNOWN);
}