#include "DataLoader.h"

#include <istream>

DataLoader::DataLoader(std::unique_ptr<std::istream> stream,
                       std::unordered_map<QString, QChar> mapping)
    : stream_(std::move(stream)), converter_{std::move(mapping)}
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

        QString converted{converter_.convert(text)};
        words.emplace(converted, std::move(text));
    }

    return words;
}
