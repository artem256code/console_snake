#ifndef SNAKE_H
#define SNAKE_H

#define HEAD  0

typedef struct Point{
    int x;
    int y;
} Point;


typedef struct Snake{
    int lenght;                // Length of snake
    Point *body;               // First - head cell, then - subsequents cells

    void (*moveUp)      (struct Snake *self);
    void (*moveDown)    (struct Snake *self);
    void (*moveLeft)    (struct Snake *self);
    void (*moveRight)   (struct Snake *self);
    void (*del)         (struct Snake *self);
} Snake;


Snake* initSnake(Snake *snake);

#endif // SNAKE_H
