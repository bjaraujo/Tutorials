#include "holder.h"

holder::holder(QObject *parent) : QObject(parent)
{

}

void holder::setValue(int value)
{

  m_value = value;

}

int holder::getValue()
{

    return m_value;

}
