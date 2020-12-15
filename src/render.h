#ifndef RENDER_H
#define RENDER_H

typedef struct Render{
    int columns;        // Numbers of console columns
    int rows;           // Numbers of consolerows
    char **buffer;      // Buffer that stores the playing field

    void (*addToBuffer) (struct Render *render, int row, int col, char sym);
    void (*clear)  (struct Render *render);
    void (*render) (struct Render *render);
} Render;


Render* initRender(Render *render);

#endif
