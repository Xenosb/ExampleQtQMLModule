#include "backendObject.h"

BackendObject::BackendObject(QObject *parent)
    : QObject{parent}
    , m_value(49)
{

}

void BackendObject::setValue(int value)
{
    m_value = value;
    emit valueChanged();
}

int BackendObject::getValue()
{
    return m_value;
}
