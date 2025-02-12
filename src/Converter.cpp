#include "Converter.h"

namespace Converter
{
QString convert(const QString& word)
{
    //    a ą b c ć
    //    d e ę f
    //    g h i
    //    j k l ł
    //    m n ń o ó
    //    p q r s ś
    //    t u v
    //    w x y z ź ż;

    QString converted{word};

    static QString dwa("2");
    converted.replace(QString("a"), dwa, Qt::CaseInsensitive);
    converted.replace(QString("ą"), dwa, Qt::CaseInsensitive);
    converted.replace(QString("b"), dwa, Qt::CaseInsensitive);
    converted.replace(QString("c"), dwa, Qt::CaseInsensitive);
    converted.replace(QString("ć"), dwa, Qt::CaseInsensitive);

    static QString trzy("3");
    converted.replace(QString("d"), trzy, Qt::CaseInsensitive);
    converted.replace(QString("e"), trzy, Qt::CaseInsensitive);
    converted.replace(QString("ę"), trzy, Qt::CaseInsensitive);
    converted.replace(QString("f"), trzy, Qt::CaseInsensitive);

    static QString cztery("4");
    converted.replace(QString("g"), cztery, Qt::CaseInsensitive);
    converted.replace(QString("h"), cztery, Qt::CaseInsensitive);
    converted.replace(QString("i"), cztery, Qt::CaseInsensitive);

    static QString piec("5");
    converted.replace(QString("j"), piec, Qt::CaseInsensitive);
    converted.replace(QString("k"), piec, Qt::CaseInsensitive);
    converted.replace(QString("l"), piec, Qt::CaseInsensitive);
    converted.replace(QString("ł"), piec, Qt::CaseInsensitive);

    static QString szesc("6");
    converted.replace(QString("m"), szesc, Qt::CaseInsensitive);
    converted.replace(QString("n"), szesc, Qt::CaseInsensitive);
    converted.replace(QString("ń"), szesc, Qt::CaseInsensitive);
    converted.replace(QString("o"), szesc, Qt::CaseInsensitive);
    converted.replace(QString("ó"), szesc, Qt::CaseInsensitive);

    static QString siedem("7");
    converted.replace(QString("p"), siedem, Qt::CaseInsensitive);
    converted.replace(QString("q"), siedem, Qt::CaseInsensitive);
    converted.replace(QString("r"), siedem, Qt::CaseInsensitive);
    converted.replace(QString("s"), siedem, Qt::CaseInsensitive);
    converted.replace(QString("ś"), siedem, Qt::CaseInsensitive);

    static QString osiem("8");
    converted.replace(QString("t"), osiem, Qt::CaseInsensitive);
    converted.replace(QString("u"), osiem, Qt::CaseInsensitive);
    converted.replace(QString("v"), osiem, Qt::CaseInsensitive);

    static QString dziewiec("9");
    converted.replace(QString("w"), dziewiec, Qt::CaseInsensitive);
    converted.replace(QString("x"), dziewiec, Qt::CaseInsensitive);
    converted.replace(QString("y"), dziewiec, Qt::CaseInsensitive);
    converted.replace(QString("z"), dziewiec, Qt::CaseInsensitive);
    converted.replace(QString("ż"), dziewiec, Qt::CaseInsensitive);
    converted.replace(QString("ź"), dziewiec, Qt::CaseInsensitive);

    return converted;
}

}  // namespace Converter
