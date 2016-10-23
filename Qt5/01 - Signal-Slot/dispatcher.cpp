#include "dispatcher.h"

dispatcher::dispatcher(QObject *parent) : QObject(parent)
{

}

void dispatcher::setValue(int value)
{

  m_value = value;
  emit valueChanged(value);

}

