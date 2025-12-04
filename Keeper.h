#ifndef KEEPER_H
#define KEEPER_H

#include "Shape.h"
#include "FlatShape.h"
#include "VolumetricShape.h"

class Keeper {
private:
    struct Element {
        Shape* data;
        Element* next;
    };
    Element* head;
    int size;

public:
    Keeper();
    ~Keeper();
    
    void addShape(Shape* newShape);
    void removeShape(int index);
    void printAll();
    void save(const char* filename);
    void load(const char* filename);
};

#endif // KEEPER_H
