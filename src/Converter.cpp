#include "Converter.h"

#include <unordered_map>

#include <QHash>

namespace
{

std::unordered_map<QString, QChar> getMap()
{
    return {{"a", '2'}, {"ą", '2'}, {"b", '2'}, {"c", '2'}, {"ć", '2'},
            {"d", '3'}, {"e", '3'}, {"ę", '3'}, {"f", '3'}, {"g", '4'},
            {"h", '4'}, {"i", '4'}, {"j", '5'}, {"k", '5'}, {"l", '5'},
            {"ł", '5'}, {"m", '6'}, {"n", '6'}, {"ń", '6'}, {"o", '6'},
            {"ó", '6'}, {"p", '7'}, {"q", '7'}, {"r", '7'}, {"s", '7'},
            {"ś", '7'}, {"t", '8'}, {"u", '8'}, {"v", '8'}, {"w", '9'},
            {"x", '9'}, {"y", '9'}, {"z", '9'}, {"ż", '9'}, {"ź", '9'}};
}
}  // namespace

namespace converter
{
QString convert(const QString& word)
{
    static std::unordered_map<QString, QChar> map{getMap()};

    QString converted(word);
    int index{0};
    for (const QChar& ch : word)
    {
        if (auto it{map.find(ch)}; it != map.end())
            converted[index] = it->second;
        ++index;
    }

    return converted;
}

}  // namespace converter
