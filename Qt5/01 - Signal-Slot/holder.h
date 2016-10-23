#ifndef HOLDER_H
#define HOLDER_H

#include <QObject>

class holder : public QObject
{
    Q_OBJECT
public:
    explicit holder(QObject *parent = 0);
    void setValue(int value);

signals:
    int getValue();

public slots:
};

#endif // HOLDER_H
