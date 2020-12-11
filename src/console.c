#include <malloc.h>
#include <sys/ioctl.h>
#include <unistd.h>

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

    return this;
}


static void _addToBuffer(struct Console *this, int row, int col, char sym){
    this->buffer[row][col] = sym;
}
