#pragma once

#include <map>
#include <memory>

#include <QString>

#include "Converter.h"

class DataLoader
{
public:
    DataLoader(std::unique_ptr<std::istream> stream,
               std::unordered_map<QString, QChar> mapping);

    std::multimap<QString, QString> getData();

private:
    std::unique_ptr<std::istream> stream_;
    Converter converter_;
    std::unordered_map<QString, QChar> mapping_;
};
