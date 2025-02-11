#pragma once

#include <memory>

#include <QFile>
#include <QMultiMap>
#include <QString>

class DataLoader
{
public:
    explicit DataLoader(std::unique_ptr<std::istream> stream);

    QMultiMap<QString, QString> getData();

private:
    std::unique_ptr<std::istream> stream_;
};
