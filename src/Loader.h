#pragma once

#include <map>

#include <QString>

class Loader
{
public:
    virtual ~Loader() = default;

    virtual std::multimap<QString, QString> getData() = 0;
};
