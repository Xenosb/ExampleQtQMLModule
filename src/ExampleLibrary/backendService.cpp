#include "backendService.h"

BackendService::BackendService(QObject *parent)
    : QObject{parent}
    , m_value(49)
{
    m_instance = this;
}

void BackendService::setValue(int value)
{
    m_value = value;
    emit valueChanged();
}

int BackendService::getValue()
{
    return m_value;
}
