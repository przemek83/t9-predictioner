#include "DataLoader.h"
#include <qtypes.h>

#include "Converter.h"

#include <QRegularExpression>
#include <map>

DataLoader::DataLoader(std::unique_ptr<std::istream> stream)
    : stream_(std::move(stream))
{
}

std::multimap<QString, QString> DataLoader::getData()
{
    std::string line;
    std::multimap<QString, QString> words;
    while (std::getline(*stream_, line))
    {
        QString text{QString::fromStdString(line)};
        if (qsizetype index{text.indexOf('/')}; index != -1)
            text.truncate(index);

        words.emplace(converter::convert(text), std::move(text));
    }

    return words;
}
