#pragma once

#include <QObject>
#include <QtQml>

class BackendObject : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)

public:
    explicit BackendObject(QObject *parent = nullptr);

    void setValue(int value);
    int getValue();

signals:
    void valueChanged();

private:
    int m_value = 99;
};
