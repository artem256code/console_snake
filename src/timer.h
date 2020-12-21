#ifndef TIMER_H
#define TIMER_H

#include <time.h>

typedef struct Timer{
    time_t start_time;
    time_t curr_time;

    void (*start)       (struct Timer *self);
    int  (*timePassed)  (struct Timer *self, double second);
    void (*del)         (struct Timer *self);
} Timer;


Timer* initTimer(Timer *self);

#endif // TIMER_H
