#pragma once

#include <QObject>

class TestTableModel;

class ConvertTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testCheck() const;
};
