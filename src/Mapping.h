#pragma once

#include <unordered_map>

#include <QChar>
#include <QHash>

namespace mapping
{
std::unordered_map<QString, QChar> getMappingPL();

std::unordered_map<QString, QChar> getMappingEN();
}  // namespace mapping
