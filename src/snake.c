#include <malloc.h>

#include "snake.h"
#include "console.h"

static void offsetBody(Snake *self){
    for(int current = self->lenght-1; current  > 0; current--){
        int prevision = current - 1;
        self->body[current].x = self->body[prevision].x;
        self->body[current].y = self->body[prevision].y;
    }
}

static int checkMove(Snake *self, int vector_direction){
    if(self->lenght == 1)                                               return 1;
    if(self->vector_direction == UP     && vector_direction != DOWN)    return 1;
    if(self->vector_direction == DOWN   && vector_direction != UP)      return 1;
    if(self->vector_direction == LEFT   && vector_direction != RIGHT)   return 1;
    if(self->vector_direction == RIGHT  && vector_direction != LEFT)    return 1;
    return 0;
}

void _moveDown(Snake *self){
    if(checkMove(self, DOWN)){
        offsetBody(self);
        self->body[HEAD].y++;
        self->vector_direction = DOWN;
    }
}

void _moveUp(Snake *self){
    if(checkMove(self, UP)){
        offsetBody(self);
        self->body[HEAD].y--;
        self->vector_direction = UP;
    }
}

void _moveRight(Snake *self){
    if(checkMove(self, RIGHT)){
        offsetBody(self);
        self->body[HEAD].x++;
        self->vector_direction = RIGHT;
    }
}

void _moveLeft(Snake *self){
    if(checkMove(self, LEFT)){
        offsetBody(self);
        self->body[HEAD].x--;
        self->vector_direction = LEFT;
    }
}

void _moveTo(Snake *self, int vector_direction){
    switch (vector_direction){
    case UP:
        self->moveUp(self);
        break;
    case DOWN:
        self->moveDown(self);
        break;
    case LEFT:
        self->moveLeft(self);
        break;
    case RIGHT:
        self->moveRight(self);
        break;
    }
}

void _add(Snake *self){
    int newCell = self->lenght;
    int endCell = self->lenght-1;

    if(self->vector_direction == UP || self->vector_direction == DOWN){
        self->body[newCell].x = self->body[endCell].x;
        self->body[newCell].x = self->body[endCell].y + 1;
    }
    else{
        self->body[newCell].x = self->body[endCell].x + 1;
        self->body[newCell].x = self->body[endCell].y;
    }
    self->lenght++;
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
    self->moveTo = _moveTo;
    self->add = _add;
    self->del = _del;

    return self;
}
