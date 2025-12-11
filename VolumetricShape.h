#ifndef VOLUMETRICSHAPE_H
#define VOLUMETRICSHAPE_H

#include "Shape.h"
#include <string>

class VolumetricShape : public Shape {
private:
    char* type;
    double width, height, depth;
    double volume;
    std::string drawing;
public:
    VolumetricShape();
    VolumetricShape(const VolumetricShape& other);
    ~VolumetricShape() override;

    void inputFromConsole() override;
    void printToConsole() override;
    void saveToFile(std::ofstream& out) override;
    void loadFromFile(std::ifstream& in) override;
    int getType() override { return 2; }
};

#endif // VOLUMETRICSHAPE_H
