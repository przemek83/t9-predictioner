#include "DataLoader.h"
#include <qtypes.h>

#include "Converter.h"

#include <QRegularExpression>

DataLoader::DataLoader(std::unique_ptr<std::istream> stream)
    : stream_(std::move(stream))
{
}

QMultiMap<QString, QString> DataLoader::getData()
{
    std::string line;
    QMultiMap<QString, QString> words;
    while (std::getline(*stream_, line))
    {
        QString text{QString::fromStdString(line)};
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
