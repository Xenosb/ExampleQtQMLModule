#pragma once

#include <QObject>
#include <QtQml>

class BackendService : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)

public:
    explicit BackendService(QObject *parent = nullptr);

    static BackendService* getInstance();

    void setValue(int value);
    int getValue();

signals:
    void valueChanged();

private:
    inline static BackendService* m_instance = nullptr;

    int m_value = 49;
};
