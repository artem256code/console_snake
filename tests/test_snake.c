#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../src/snake.h"
#include "test_snake.h"

static int test_initSnake(){
    Snake *snake = NULL;

    snake = initSnake(snake);

    assert(snake->lenght == 1);
    assert(snake->body != NULL);
    assert(snake->moveDown != NULL);
    assert(snake->moveLeft != NULL);
    assert(snake->moveRight != NULL);
    assert(snake->moveUp != NULL);
    return 0;
}

static int test_moveDown(){
    Snake *snake = NULL;

    snake = initSnake(snake);
    snake->body[HEAD].y = 5;
    snake->moveDown(snake);

    assert(snake->body[HEAD].y == 6);
    return 0;
}

static int test_moveUp(){
    Snake *snake = NULL;

    snake = initSnake(snake);
    snake->body[HEAD].y = 5;
    snake->moveUp(snake);

    assert(snake->body[HEAD].y == 4);
    return 0;
}

static int test_moveLeft(){
    Snake *snake = NULL;

    snake = initSnake(snake);
    snake->body[HEAD].x = 5;
    snake->moveLeft(snake);

    assert(snake->body[HEAD].x == 4);
    return 0;
}

static int test_moveRight(){
    Snake *snake = NULL;

    snake = initSnake(snake);
    snake->body[HEAD].x = 5;
    snake->moveRight(snake);

    assert(snake->body[HEAD].x == 6);
    return 0;
}

int testing_snake(){
    test_initSnake();
    test_moveDown();
    test_moveUp();
    test_moveLeft();
    test_moveRight();
    return 0;
}
