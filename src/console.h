#ifndef CONSOLE_H
#define CONSOLE_H

typedef struct Console{
    int columns;        // Numbers of console columns
    int rows;           // Numbers of console rows
    char **buffer;      // Buffer that stores the playing field

    void (*addToBuffer) (struct Console *this, int row, int col, char sym);
    void (*clear)  (struct Console *this);
    void (*render) (struct Console *this);
} Console;


/**
 * @brief Create a console object
 * @param this - pointer to the console object
 * @return       pointer to the console object
 */
struct Console* initConsole(Console *this);


/**
 * @brief Adding the symbol in 'buffer' array
 * @param this  - pointer to the console object
 * @param row   - row in the buffer
 * @param col   - column in the buffer
 * @param sym   - the symbol to be added
 */
static void _addToBuffer(Console *this, int row, int col, char sym);


/**
 * @brief Clear the console field
 * @param this  - pointer to the console object
 */
static void _clear(Console *this);


/**
 * @brief _render
 * @param this
 */
static void _render(Console *this);

#endif
