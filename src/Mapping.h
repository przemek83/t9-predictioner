#pragma once

#include <unordered_map>

#include <QChar>
#include <QHash>

namespace mapping
{
enum class Language
{
    UNKNOWN,
    PL,
    EN
};

Language getLanguage(const QString& dictionaryFileName);

std::unordered_map<QString, QChar> getMapping(Language language);
}  // namespace mapping
