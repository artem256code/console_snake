#include <malloc.h>
#include <stdlib.h>

#include "console.h"
#include "render.h"

static void _addToBuffer(Render *render, int row, int col, char sym){
    render->buffer[row][col] = sym;
}

static void _clear(Render *render){
    system("clear");
    for(int i = 0; i < render->rows; i++){
        for(int j = 0; j < render->columns; j++){
            render->buffer[i][j] = ' ';
        }
    }
}

static void _render(Render *render){
    for(int i = 0; i < render->rows; i++){
        for(int j = 0; j < render->columns; j++){
            putchar(render->buffer[i][j]);
        }
    }
}

struct Render* initRender(struct Render *render){
    render = (Render*) malloc(sizeof(Render));
    render->columns   = getConsoleCol();
    render->rows      = getConsoleRow();
    char **buffer   = (char**) malloc(sizeof(char*) * render->rows);
    for(int i = 0; i < render->rows; i++){
        buffer[i] = (char*) malloc(sizeof(char) * render->columns);
        for(int j = 0; j < render->columns; j++){
            buffer[i][j] = ' ';
        }
    }
    render->buffer = buffer;
    render->addToBuffer = _addToBuffer;
    render->clear = _clear;
    render->render = _render;
    return render;
}


