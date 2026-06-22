#include "DataLoader.h"

#include <QTextStream>

DataLoader::DataLoader(QTextStream& stream,
                       std::unordered_map<QString, QChar> mapping)
    : stream_(stream), converter_{std::move(mapping)}
{
}

std::multimap<QString, QString> DataLoader::getData()
{
    QString line;
    std::multimap<QString, QString> words;

    while (line = stream_.readLine(), !line.isNull())
    {
        if (qsizetype index{line.indexOf('/')}; index != -1)
            line.truncate(index);

        QString converted{converter_.convert(line)};
        words.emplace(converted, std::move(line));
    }

    return words;
}
