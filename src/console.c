#include "console.h"
#include <sys/ioctl.h>
#include <unistd.h>
struct winsize w;

int getConsoleCol(){
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int getConsoleRow(){
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}
