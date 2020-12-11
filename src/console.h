#ifndef CONSOLE_H
#define CONSOLE_H

typedef struct Console{
    int columns;        // Numbers of console columns
    int rows;           // Numbers of console rows
    char **buffer;      // Buffer that stores the playing field
} Console;

/**
 * @brief initConsole   Create a console object
 * @param this          Pointer to the console object
 * @return              Pointer to the console object
 */
struct Console* initConsole(struct Console *this);

#endif
