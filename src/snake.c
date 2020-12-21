#include <malloc.h>

#include "snake.h"
#include "console.h"

static void offsetBody(Snake *self){
    for(int current = 1; current < self->lenght; current++){
        int prevision = current - 1;
        self->body[current].x = self->body[prevision].x;
        self->body[current].y = self->body[prevision].y;
    }
}

void _moveDown(Snake *self){
    offsetBody(self);
    self->body[HEAD].y++;
}

void _moveUp(Snake *self){
    offsetBody(self);
    self->body[HEAD].y--;
}

void _moveRight(Snake *self){
    offsetBody(self);
    self->body[HEAD].x++;
}

void _moveLeft(Snake *self){
    offsetBody(self);
    self->body[HEAD].x--;
}


void _del(Snake *self){
    free(self->body);
    free(self);
}

Snake* initSnake(Snake *self){
    self = (Snake*) malloc(sizeof(Snake));

    int col = getConsoleCol();
    int row = getConsoleRow();
    self->body = (Point*) malloc(sizeof(Point) * col * row);

    Point head_coords = {col/2, row/2};
    self->body[HEAD] = head_coords;
    self->lenght = 1;

    self->moveDown = _moveDown;
    self->moveLeft = _moveLeft;
    self->moveRight = _moveRight;
    self->moveUp = _moveUp;
    self->del = _del;

    return self;
}
