#include <malloc.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

#include "console.h"

struct winsize w;

int getConsoleCol(){
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int getConsoleRow(){
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}


struct Console* initConsole(struct Console *this){
    this = (Console*) malloc(sizeof(Console));
    this->columns   = getConsoleCol();
    this->rows      = getConsoleRow();
    char **buffer   = (char**) malloc(sizeof(char*) * this->rows);
    for(int i = 0; i < this->rows; i++){
        buffer[i] = (char*) malloc(sizeof(char) * this->columns);
    }
    this->buffer = buffer;
    this->addToBuffer = _addToBuffer;
    this->clear = _clear;
    this->render = _render;
    return this;
}


static void _addToBuffer(struct Console *this, int row, int col, char sym){
    this->buffer[row][col] = sym;
}

static void _clear(Console *this){
    system("clear");
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; i++){
            this->buffer[i][j] = ' ';
        }
    }
}

static void _render(Console *this){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++){
            putchar(this->buffer[i][j]);
        }
    }
}
