#ifndef FLATSHAPE_H
#define FLATSHAPE_H

#include "Shape.h"
#include  <string>

class FlatShape : public Shape {
private:
    char* type;       // Тип (круг, квадрат...)
    double width;     // Размеры
    double height;
    double area;      // Площадь
    std::string drawing;

public:
    FlatShape();
    FlatShape(const char* t, double w, double h);
    FlatShape(const FlatShape& other); // Конструктор копирования
    ~FlatShape() override;

    void inputFromConsole() override;
    void printToConsole() override;
    void saveToFile(std::ofstream& out) override;
    void loadFromFile(std::ifstream& in) override;
    int getType() override { return 1; }
};

#endif // FLATSHAPE_H
