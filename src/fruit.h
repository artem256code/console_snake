#ifndef FRUIT_H
#define FRUIT_H

typedef struct Fruit{
    int x;
    int y;
    void (*del) (struct Fruit *self);
} Fruit;

Fruit* initFruit(Fruit *self);

#endif // FRUIT_H
