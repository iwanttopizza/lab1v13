#include "FlatShape.h"
#include <iomanip>

FlatShape::FlatShape() : width(0), height(0), area(0) {
    type = new char[1];
    type[0] = '\0';
    std::cout << "[FlatShape] Default constructor called\n";
}

FlatShape::FlatShape(const char* t, double w, double h) : width(w), height(h) {
    type = new char[strlen(t) + 1];
    strcpy(type, t);
    area = width * height; // Упрощенный расчет для примера
    std::cout << "[FlatShape] Parameter constructor called\n";
}

FlatShape::FlatShape(const FlatShape& other) {
    width = other.width;
    height = other.height;
    area = other.area;
    type = new char[strlen(other.type) + 1];
    strcpy(type, other.type);
    std::cout << "[FlatShape] Copy constructor called\n";
}

FlatShape::~FlatShape() {
    delete[] type;
    std::cout << "[FlatShape] Destructor called\n";
}

void FlatShape::inputFromConsole() {
    int choice;
    std::cout << "\n--- Select Flat Shape Type ---\n";
    std::cout << "1. Circle\n";
    std::cout << "2. Rectangle\n";
    std::cout << "3. Triangle\n";
    std::cout << "Selection: ";
    std::cin >> choice;

    delete[] type; // Очищаем старое значение

    if (choice == 1) {
        type = new char[7];
        strcpy(type, "Circle");
        
        std::cout << "Enter Radius: ";
        std::cin >> width;
        height = width; // Для круга высота = ширина (диаметр/радиус)
        area = 3.14159 * width * width;
        
    } else if (choice == 2) {
        type = new char[10];
        strcpy(type, "Rectangle");
        
        std::cout << "Enter Width: ";
        std::cin >> width;
        std::cout << "Enter Height: ";
        std::cin >> height;
        area = width * height;
        
    } else if (choice == 3) {
        type = new char[9];
        strcpy(type, "Triangle");
        
        std::cout << "Enter Base: ";
        std::cin >> width;
        std::cout << "Enter Height: ";
        std::cin >> height;
        area = 0.5 * width * height;

    } else {
        // Если ввели ерунду, делаем дефолтную фигуру
        type = new char[8];
        strcpy(type, "Unknown");
        width = 0; height = 0; area = 0;
        std::cout << "Invalid choice. Created empty shape.\n";
    }
}


void FlatShape::printToConsole() {
    std::cout << "\n--- Flat Figure ---\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Dimensions: " << width << " x " << height << "\n";
    std::cout << "Area: " << area << "\n";

    std::string t(type ? type : "Unknown");
    for (auto &c : t) c = tolower(c);

    std::cout << "\nASCII Drawing:\n";
    if (t == "circle") {
        std::cout <<
        "    *****\n"
        "  **     **\n"
        " *         *\n"
        " *         *\n"
        " *         *\n"
        "  **     **\n"
        "    *****\n";
    } else if (t == "rectangle") {
        std::cout <<
        "+----------------+\n"
        "|                |\n"
        "|                |\n"
        "|                |\n"
        "+----------------+\n";
    } else if (t == "triangle") {
        std::cout <<
        "      *\n"
        "     * *\n"
        "    *   *\n"
        "   *     *\n"
        "  *********\n";
    } else {
        std::cout << "[No ASCII drawing for this shape]\n";
    }
}

void FlatShape::saveToFile(std::ofstream& out) {
    out << 1 << " " << type << " " << width << " " << height << " " << area << "\n";
}

void FlatShape::loadFromFile(std::ifstream& in) {
    char buffer[100];
    in >> buffer >> width >> height >> area;
    delete[] type;
    type = new char[strlen(buffer) + 1];
    strcpy(type, buffer);
}
