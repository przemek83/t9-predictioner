#pragma once

#include <unordered_map>

#include <QChar>
#include <QHash>

class QString;

class Converter
{
public:
    explicit Converter(std::unordered_map<QString, QChar> mapping);

    QString convert(const QString& word);

private:
    std::unordered_map<QString, QChar> mapping_;
};
