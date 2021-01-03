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

    for(int i = 0; i < 5; i++){
        self->body[HEAD+i+1].x = self->body[HEAD].x + i + 1;
        self->body[HEAD+i+1].y = self->body[HEAD].y;
    }
    self->lenght = 6;


    self->moveDown = _moveDown;
    self->moveLeft = _moveLeft;
    self->moveRight = _moveRight;
    self->moveUp = _moveUp;
    self->del = _del;

    return self;
}
