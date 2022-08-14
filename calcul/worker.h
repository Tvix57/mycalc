#ifndef WORKER_H
#define WORKER_H

#include "./../back/math/back.h"
#include <QObject>

class worker : public QObject, public back
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);


signals:
    void new_coord(double x, double y);
protected:

};

#endif // WORKER_H
