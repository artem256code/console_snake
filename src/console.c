#include <termios.h>
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

void ignoreCarriageReturns(){
    struct termios term;
    tcgetattr( STDIN_FILENO, &term );
    term.c_lflag = IGNCR;
    term.c_iflag = IGNBRK;

    tcsetattr( STDIN_FILENO, TCSANOW, &term);
}
