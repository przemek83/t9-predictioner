#pragma once

#include <memory>

#include "Converter.h"
#include "Loader.h"

class QTextStream;

class DataLoader : public Loader
{
public:
    DataLoader(QTextStream& stream,
               std::unordered_map<QString, QChar> mapping);

    std::multimap<QString, QString> getData() override;

private:
    QTextStream& stream_;
    Converter converter_;
    std::unordered_map<QString, QChar> mapping_;
};
