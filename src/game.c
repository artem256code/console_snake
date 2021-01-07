#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "game.h"
#include "console.h"
#include "keys.h"

static void inputProcessing(Game *self)
{
    switch (getchar()) {
    case KEY_DOWN:
        self->snake->moveDown(self->snake);
        break;
    case KEY_LEFT:
        self->snake->moveLeft(self->snake);
        break;
    case KEY_RIGHT:
        self->snake->moveRight(self->snake);
        break;
    case KEY_UP:
        self->snake->moveUp(self->snake);
        break;
    }
}


static int checkColisionWithFruit(Snake *snake, Fruit *fruit){
    if(snake->body[HEAD].x == fruit->x && snake->body[HEAD].y == fruit->y)  return 1;
    return 0;
}


static void drawing(Game *self)
{
    self->render->clear(self->render);

    // Add fruit
    self->render->addToBuffer(self->render,
                              self->fruit->y,
                              self->fruit->x,
                              '$');

    // Add snake
    for(int i = 0; i < self->snake->lenght; i++){
        self->render->addToBuffer(self->render,
                                  self->snake->body[i].y,
                                  self->snake->body[i].x,
                                  '*');
    }

    self->render->render(self->render);
}

static void colisionProcessing(Game *self)
{
    if(checkColisionWithFruit(self->snake, self->fruit)){
        self->snake->add(self->snake);
        free(self->fruit);
        self->fruit = initFruit(self->fruit);
    }
}

void game_start(Game *self){
    self->timer->start(self->timer);

    while(self->isRun){
        inputProcessing(self);
        colisionProcessing(self);
        drawing(self);
        usleep(10);
    }
}

void game_stop(Game *self){
    self->render->del(self->render);
    self->snake->del(self->snake);
    self->fruit->del(self->fruit);

    self->render = NULL;
    self->snake  = NULL;
    self->timer  = NULL;
    self->fruit  = NULL;
    self = NULL;
}

Game* initGame(Game *self){
    ignoreCarriageReturns();

    self = (Game*) malloc(sizeof(Game));
    if(self == NULL){
        printf("Failed to allocate memory for the 'Game' object\n");
        exit(EXIT_FAILURE);
    }

    self->render = initRender(self->render);
    self->snake  = initSnake(self->snake);
    self->fruit  = initFruit(self->fruit);
    self->timer  = initTimer(self->timer);
    self->start  = game_start;
    self->stop   = game_stop;
    self->isRun  = TRUE;
    return self;
}


