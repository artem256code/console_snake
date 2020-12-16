#include <malloc.h>

#include "snake.h"
#include "console.h"

void _moveDown(Snake *snake){
    snake->cells[HEAD].y++;
}

void _moveUp(Snake *snake){
    snake->cells[HEAD].y--;
}

void _moveRight(Snake *snake){
    snake->cells[HEAD].x++;
}

void _moveLeft(Snake *snake){
    snake->cells[HEAD].x--;
}


Snake* initSnake(Snake *snake){
    snake = (Snake*) malloc(sizeof(Snake));
    snake->lenght = 1;
    int col = getConsoleCol();
    int row = getConsoleRow();
    snake->cells = (Point*) malloc(sizeof(Point) * col * row);
    snake->moveDown = _moveDown;
    snake->moveLeft = _moveLeft;
    snake->moveRight = _moveRight;
    snake->moveUp = _moveUp;
    return snake;
}
