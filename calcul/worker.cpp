#include "worker.h"

worker::worker(QObject *parent)
    : QObject{parent}
{

}
void worker::run()
{
    for(; start < end; start += step) {
        replaceAllX(start);
        double y = calculate();
        emit new_coord(start, y);
    }
}

void worker::getSettings(double start_in, double end_in, double step_in, back& data )
{
    start = start_in;
    end = end_in;
    step = step_in;
    polish_stack = data.getStack();
    position_x = data.getPositions();
}
