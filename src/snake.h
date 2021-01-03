#ifndef SNAKE_H
#define SNAKE_H

#define HEAD  0

typedef struct Point{
    int x;
    int y;
} Point;

enum{
    LEFT,
    RIGHT,
    UP,
    DOWN
};


typedef struct Snake{
    int lenght;                // Length of snake
    int vector_direction;      // The direction vector (Up, Down, Left or Right)
    Point *body;               // First - head cell, then - subsequents cells

    void (*moveUp)      (struct Snake *self);
    void (*moveDown)    (struct Snake *self);
    void (*moveLeft)    (struct Snake *self);
    void (*moveRight)   (struct Snake *self);
    void (*del)         (struct Snake *self);
} Snake;


Snake* initSnake(Snake *snake);

#endif // SNAKE_H
