#pragma once

#include <memory>

#include "Converter.h"
#include "Loader.h"

class DataLoader : public Loader
{
public:
    DataLoader(std::unique_ptr<std::istream> stream,
               std::unordered_map<QString, QChar> mapping);

    std::multimap<QString, QString> getData() override;

private:
    std::unique_ptr<std::istream> stream_;
    Converter converter_;
    std::unordered_map<QString, QChar> mapping_;
};
