#include "DataLoader.h"
#include <qtypes.h>

#include "Converter.h"

#include <QRegularExpression>

// DataLoader::DataLoader(std::unique_ptr<std::istream> stream)
//     : stream_(std::move(stream))
DataLoader::DataLoader(const QString& filePath)
{
    file_.setFileName(filePath);

    file_.open(QIODevice::ReadOnly);
}

QMultiMap<QString, QString> DataLoader::getData()
{
    QByteArray wholeText = file_.readAll();

    QString wholeString(wholeText);

    QStringList stringList = wholeString.split('\n');

    QMultiMap<QString, QString> words;

    foreach (QString text, stringList)
    {
        if (qsizetype index{text.indexOf('/')}; index != -1)
            text.truncate(index);

        if (text.contains('-'))
            continue;

        text.replace(QRegularExpression("\\W"), "");
        QString converted{text};
        Converter::convert(converted);
        words.insert(converted, text);
    }

    return words;
}
