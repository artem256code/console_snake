#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests.h"
#include "../src/console.h"


static int test_initConsole(){
    Console *test = NULL;
    test = initConsole(test);
    if(test->columns <= 0 || test->rows <= 0 || test->buffer == NULL){
        printf("test_initConsole() failed...\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}


int testing(){
    test_initConsole();

    return 0;
}
