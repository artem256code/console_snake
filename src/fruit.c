#include <malloc.h>
#include <stdlib.h>

#include "fruit.h"
#include "console.h"

static void _del(Fruit *self){
    free(self);
}

Fruit* initFruit(Fruit *self){
    self = (Fruit*) malloc(sizeof(Fruit));

    int maxX = getConsoleCol();
    int maxY = getConsoleRow();

    self->x = rand() % maxX;
    self->y = rand() % maxY;
    self->del = _del;

    return self;
}
