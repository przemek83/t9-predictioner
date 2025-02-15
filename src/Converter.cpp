#include "Converter.h"

Converter::Converter(std::unordered_map<QString, QChar> mapping)
    : mapping_{std::move(mapping)}
{
}

QString Converter::convert(const QString& word)
{
    QString converted(word);
    int index{0};
    for (const QChar& ch : word)
    {
        if (auto it{mapping_.find(ch)}; it != mapping_.end())
            converted[index] = it->second;
        ++index;
    }

    return converted;
}
