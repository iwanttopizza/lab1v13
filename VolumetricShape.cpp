#include "VolumetricShape.h"

VolumetricShape::VolumetricShape() : width(0), height(0), depth(0), volume(0) {
    type = new char[1];
    type[0] = '\0';
    std::cout << "[VolumetricShape] Default constructor called\n";
}

VolumetricShape::VolumetricShape(const VolumetricShape& other) {
    width = other.width;
    height = other.height;
    depth = other.depth;
    volume = other.volume;
    type = new char[strlen(other.type) + 1];
    strcpy(type, other.type);
    std::cout << "[VolumetricShape] Copy constructor called\n";
}

VolumetricShape::~VolumetricShape() {
    delete[] type;
    std::cout << "[VolumetricShape] Destructor called\n";
}

void VolumetricShape::inputFromConsole() {
    int choice;
    std::cout << "\n--- Select Volumetric Shape Type ---\n";
    std::cout << "1. Sphere (Shar)\n";
    std::cout << "2. Parallelepiped (Box)\n";
    std::cout << "3. Cone (Konus)\n";
    std::cout << "Selection: ";
    std::cin >> choice;

    delete[] type;

    if (choice == 1) {
        type = new char[7];
        strcpy(type, "Sphere");
        
        std::cout << "Enter Radius: ";
        std::cin >> width;
        height = width; 
        depth = width;
        // V = 4/3 * pi * r^3
        volume = (4.0/3.0) * 3.14159 * width * width * width;
        
    } else if (choice == 2) {
        type = new char[14];
        strcpy(type, "Parallelepiped");
        
        std::cout << "Enter Width: "; std::cin >> width;
        std::cout << "Enter Height: "; std::cin >> height;
        std::cout << "Enter Depth: "; std::cin >> depth;
        volume = width * height * depth;
        
    } else if (choice == 3) {
        type = new char[5];
        strcpy(type, "Cone");
        
        std::cout << "Enter Radius: "; std::cin >> width;
        std::cout << "Enter Height: "; std::cin >> height;
        depth = width;
        // V = 1/3 * pi * r^2 * h
        volume = (1.0/3.0) * 3.14159 * width * width * height;
        
    } else {
        type = new char[8];
        strcpy(type, "Unknown");
        width = 0; height = 0; depth = 0; volume = 0;
        std::cout << "Invalid choice.\n";
    }
}


void VolumetricShape::printToConsole() {
    std::cout << "\n--- Volumetric Figure ---\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Dimensions: " << width << " x " << height << " x " << depth << "\n";
    std::cout << "Volume: " << volume << "\n";
    std::cout << "Drawing: Projected as flat [ " << type << " ] on screen.\n";
}

void VolumetricShape::saveToFile(std::ofstream& out) {
    out << 2 << " " << type << " " << width << " " << height << " " << depth << " " << volume << "\n";
}

void VolumetricShape::loadFromFile(std::ifstream& in) {
    char buffer[100];
    in >> buffer >> width >> height >> depth >> volume;
    delete[] type;
    type = new char[strlen(buffer) + 1];
    strcpy(type, buffer);
}
