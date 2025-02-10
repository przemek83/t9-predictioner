#pragma once

#include <memory>

#include <QFile>
#include <QMultiMap>
#include <QString>

class DataLoader
{
public:
    // explicit DataLoader(std::unique_ptr<std::istream> stream);
    explicit DataLoader(const QString& filePath);

    QMultiMap<QString, QString> getData();

private:
    // std::unique_ptr<std::istream> stream_;

    QFile file_;
};
