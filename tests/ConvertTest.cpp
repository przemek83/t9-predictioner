#include "ConvertTest.h"

#include <QTest>

#include <src/Converter.h>

void ConvertTest::testConversion_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("expected");

    QString input{"konstantynopolitańczyk"};
    QTest::newRow(input.toStdString().c_str())
        << input << "5667826896676548262995";
    input = "interoperacyjność";
    QTest::newRow(input.toStdString().c_str()) << input << "46837673722956672";
    input = "niewyczarterowywanie";
    QTest::newRow(input.toStdString().c_str())
        << input << "64399292783769992643";
    input = "techniczno-gospodarczy";
    QTest::newRow(input.toStdString().c_str())
        << input << "8324642966-46776327299";
    input = "brząknąwszy";
    QTest::newRow(input.toStdString().c_str()) << input << "27925629799";
}

void ConvertTest::testConversion()
{
    QFETCH(QString, input);
    QFETCH(const QString, expected);

    Converter converter;
    QCOMPARE(converter.convert(input), expected);
}
