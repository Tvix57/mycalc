#ifndef WORKER_H
#define WORKER_H

#include "./../back/math/back.h"
#include <QObject>

class worker : public QObject, public back
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);
    void getSettings(double, double, double, back&);
public slots:
    void run();
signals:
    void new_coord(double x, double y);
protected:
    double start, end, step;
};

#endif // WORKER_H
