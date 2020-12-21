#include <malloc.h>

#include "timer.h"

void _startTimer(Timer *self){
    self->start_time = time(NULL);
}

int _timePassed(Timer *self, double second){
    self->curr_time = time(NULL);
    if(difftime(self->curr_time, self->start_time) >= second){
        self->start_time = self->curr_time;
        return 1;
    }
    return 0;
}

void _delTimer(Timer *self){
    free(self);
}

Timer* initTimer(Timer *self){
    self = (Timer*) malloc(sizeof(Timer));
    self->start = _startTimer;
    self->timePassed = _timePassed;
    self->del =_delTimer;
    return self;
}
