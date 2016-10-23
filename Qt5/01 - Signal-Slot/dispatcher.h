#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>

class dispatcher : public QObject
{
    Q_OBJECT
private:
    int m_value;

public:
    explicit dispatcher(QObject *parent = 0);
    void setValue(int value);

signals:
    void valueChanged(int);

public slots:
};

#endif // DISPATCHER_H
