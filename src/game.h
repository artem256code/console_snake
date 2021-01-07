#ifndef GAME_H
#define GAME_H

#include "render.h"
#include "snake.h"
#include "timer.h"
#include "fruit.h"

#define TRUE    1
#define FALSE   0

typedef struct Game{
    Render *render;
    Snake  *snake;
    Fruit  *fruit;
    Timer  *timer;
    char isRun;

    void (*start) (struct Game *self);
    void (*stop)  (struct Game *self);
} Game;

Game* initGame(Game *self);

#endif // GAME_H
