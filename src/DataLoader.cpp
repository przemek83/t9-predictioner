#include "DataLoader.h"

#include <istream>

#include "Converter.h"

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

        QString converted{converter::convert(text)};
        words.emplace(converted, std::move(text));
    }

    return words;
}
