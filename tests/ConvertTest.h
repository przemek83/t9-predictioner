#pragma once

#include <QObject>

class TestTableModel;

class ConvertTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    static void testConversion_data();
    static void testConversion();
};
