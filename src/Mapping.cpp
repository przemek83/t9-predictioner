#include "Mapping.h"

namespace
{
std::unordered_map<QString, QChar> getMappingPL()
{
    std::unordered_map<QString, QChar> mapping{
        {"a", '2'}, {"ą", '2'}, {"b", '2'}, {"c", '2'}, {"ć", '2'}, {"d", '3'},
        {"e", '3'}, {"ę", '3'}, {"f", '3'}, {"g", '4'}, {"h", '4'}, {"i", '4'},
        {"j", '5'}, {"k", '5'}, {"l", '5'}, {"ł", '5'}, {"m", '6'}, {"n", '6'},
        {"ń", '6'}, {"o", '6'}, {"ó", '6'}, {"p", '7'}, {"q", '7'}, {"r", '7'},
        {"s", '7'}, {"ś", '7'}, {"t", '8'}, {"u", '8'}, {"v", '8'}, {"w", '9'},
        {"x", '9'}, {"y", '9'}, {"z", '9'}, {"ż", '9'}, {"ź", '9'}};

    return mapping;
}

std::unordered_map<QString, QChar> getMappingEN()
{
    std::unordered_map<QString, QChar> mapping{
        {"a", '2'}, {"b", '2'}, {"c", '2'}, {"d", '3'}, {"e", '3'}, {"f", '3'},
        {"g", '4'}, {"h", '4'}, {"i", '4'}, {"j", '5'}, {"k", '5'}, {"l", '5'},
        {"m", '6'}, {"n", '6'}, {"o", '6'}, {"p", '7'}, {"q", '7'}, {"r", '7'},
        {"s", '7'}, {"t", '8'}, {"u", '8'}, {"v", '8'}, {"w", '9'}, {"x", '9'},
        {"y", '9'}, {"z", '9'}};

    return mapping;
}
}  // namespace

namespace mapping
{
Language getLanguage(const QString& dictionaryFileName)
{
    if (dictionaryFileName.toLower().contains("pl"))
        return Language::PL;

    if (dictionaryFileName.toLower().contains("en"))
        return Language::EN;

    return Language::UNKNOWN;
}

std::unordered_map<QString, QChar> getMapping(Language language)
{
    switch (language)
    {
        case Language::PL:
            return getMappingPL();
        case Language::EN:
            return getMappingEN();

        default:
            return {};
    }
}

}  // namespace mapping
