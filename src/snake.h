#ifndef SNAKE_H
#define SNAKE_H

#define HEAD  0

typedef struct Point{
    int x;
    int y;
} Point;


typedef struct Snake{
    int lenght;                // Length of snake
    Point *cells;              // First - head cell, then - subsequents cells

    void (*moveUp)      (struct Snake *snake);
    void (*moveDown)    (struct Snake *snake);
    void (*moveLeft)    (struct Snake *snake);
    void (*moveRight)   (struct Snake *snake);
} Snake;


Snake* initSnake(Snake *snake);

#endif // SNAKE_H
