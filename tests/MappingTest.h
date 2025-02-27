#pragma once

#include <QObject>

class MappingTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testGetLanguage() const;
};
