#include "Keeper.h"
#include <stdexcept>

Keeper::Keeper() : head(nullptr), size(0) {
    std::cout << "[Keeper] Created\n";
}

Keeper::~Keeper() {
    Element* current = head;
    while (current != nullptr) {
        Element* next = current->next;
        delete current->data; // Удаляем саму фигуру
        delete current;       // Удаляем узел списка
        current = next;
    }
    std::cout << "[Keeper] Destroyed\n";
}

void Keeper::addShape(Shape* newShape) {
    Element* newElem = new Element;
    newElem->data = newShape;
    newElem->next = nullptr;

    if (head == nullptr) {
        head = newElem;
    } else {
        Element* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newElem;
    }
    size++;
    std::cout << "Shape added.\n";
}

void Keeper::removeShape(int index) {
    if (head == nullptr || index < 0 || index >= size) {
        throw std::runtime_error("Invalid index or empty list!");
    }

    Element* toDelete = nullptr;
    if (index == 0) {
        toDelete = head;
        head = head->next;
    } else {
        Element* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }

    delete toDelete->data;
    delete toDelete;
    size--;
    std::cout << "Shape removed.\n";
}

void Keeper::printAll() {
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }
    Element* current = head;
    int i = 0;
    while (current != nullptr) {
        std::cout << "#" << i++ << " ";
        current->data->printToConsole();
        current = current->next;
    }
}

void Keeper::save(const char* filename) {
    std::ofstream out(filename);
    if (!out.is_open()) throw std::runtime_error("Cannot open file for saving!");

    out << size << "\n";
    Element* current = head;
    while (current != nullptr) {
        current->data->saveToFile(out);
        current = current->next;
    }
    out.close();
    std::cout << "Saved to " << filename << "\n";
}

void Keeper::load(const char* filename) {
    std::ifstream in(filename);
    if (!in.is_open()) throw std::runtime_error("Cannot open file for loading!");

    // Очистить текущий список
    while(size > 0) removeShape(0);

    int count;
    in >> count;
    for (int i = 0; i < count; ++i) {
        int type;
        in >> type;
        Shape* newShape = nullptr;
        if (type == 1) newShape = new FlatShape();
        else if (type == 2) newShape = new VolumetricShape();
        
        if (newShape) {
            newShape->loadFromFile(in);
            addShape(newShape);
        }
    }
    in.close();
    std::cout << "Loaded from " << filename << "\n";
}
