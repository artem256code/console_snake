#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_render.h"
#include "../src/render.h"


static int test_initRender(){
    Render *test = NULL;
    test = initRender(test);
    if(test->columns <= 0 || test->rows <= 0 || test->buffer == NULL ||
            test->addToBuffer == NULL || test->clear == NULL ||
            test->render == NULL){
        printf("test_initRender() failed...\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}


static int test_addToBuffer(){
    Render *test = NULL;
    test = initRender(test);

    test->addToBuffer(test, 0, 10, '*');
    if(test->buffer[0][10] != '*'){
        printf("test_addToBuffer() failed...\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int testing(){
    test_initRender();
    test_addToBuffer();
    return 0;
}
