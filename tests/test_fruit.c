#include <assert.h>
#include <stdlib.h>

#include "test_fruit.h"
#include "../src/console.h"
#include "../src/fruit.h"

static int test_initFruit(){
    Fruit* fruit = NULL;

    fruit = initFruit(fruit);

    assert(fruit != NULL);
    assert(fruit->x < getConsoleCol() && fruit->x >= 0);
    assert(fruit->y < getConsoleRow() && fruit->x >= 0);
    assert(fruit->del != NULL);
    return 0;
}

int testing_fruit(){
    test_initFruit();
    return 0;
}
