#include "Converter.h"

Converter::Converter() { mapping_ = createMapping(); }

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

std::unordered_map<QString, QChar> Converter::createMapping()
{
    return {{"a", '2'}, {"ą", '2'}, {"b", '2'}, {"c", '2'}, {"ć", '2'},
            {"d", '3'}, {"e", '3'}, {"ę", '3'}, {"f", '3'}, {"g", '4'},
            {"h", '4'}, {"i", '4'}, {"j", '5'}, {"k", '5'}, {"l", '5'},
            {"ł", '5'}, {"m", '6'}, {"n", '6'}, {"ń", '6'}, {"o", '6'},
            {"ó", '6'}, {"p", '7'}, {"q", '7'}, {"r", '7'}, {"s", '7'},
            {"ś", '7'}, {"t", '8'}, {"u", '8'}, {"v", '8'}, {"w", '9'},
            {"x", '9'}, {"y", '9'}, {"z", '9'}, {"ż", '9'}, {"ź", '9'}};
}
