#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
#include <cstring>

// Базовый класс
class Shape {
public:
    Shape();
    virtual ~Shape();
    
    // Чисто виртуальные методы (интерфейс)
    virtual void inputFromConsole() = 0;
    virtual void printToConsole() = 0;
    virtual void saveToFile(std::ofstream& out) = 0;
    virtual void loadFromFile(std::ifstream& in) = 0;
    virtual int getType() = 0; // 1 - Плоская, 2 - Объемная
};

#endif // SHAPE_H
