#pragma once

#include <unordered_map>

#include <QChar>
#include <QHash>

class QString;

class Converter
{
public:
    Converter();

    QString convert(const QString& word);

private:
    static std::unordered_map<QString, QChar> createMapping();

    std::unordered_map<QString, QChar> mapping_;
};
