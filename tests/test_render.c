#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_render.h"
#include "../src/render.h"


static int test_initRender(){
    Render *test = NULL;

    test = initRender(test);

    assert(test->columns > 0);
    assert(test->rows > 0);
    assert(test->buffer != NULL);
    assert(test->addToBuffer != NULL);
    assert(test->clear != NULL);
    assert(test->render != NULL);
    assert(test->del != NULL);
    return 0;
}


static int test_addToBuffer(){
    Render *test = NULL;

    test = initRender(test);
    test->addToBuffer(test, 0, 10, '*');

    assert(test->buffer[0][10] == '*');
    return 0;
}

static int test_clear(){
    Render *test = NULL;

    test = initRender(test);

    for(int i = 0; i < test->rows; i++){
        for(int j = 0; j < test->columns; j++){
            assert(test->buffer[i][j] == ' ');
        }
    }
    return 0;
}

int testing(){
    test_initRender();
    test_addToBuffer();
    test_clear();
    return 0;
}
