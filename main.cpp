#include <iostream>
#include "Keeper.h"

int main() {
    Keeper keeper;
    int choice;

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Add Flat Shape\n";
        std::cout << "2. Add Volumetric Shape\n";
        std::cout << "3. Remove Shape\n";
        std::cout << "4. Show All\n";
        std::cout << "5. Save to File\n";
        std::cout << "6. Load from File\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        try {
            if (choice == 1) {
                FlatShape* fs = new FlatShape();
                fs->inputFromConsole();
                keeper.addShape(fs);
            } else if (choice == 2) {
                VolumetricShape* vs = new VolumetricShape();
                vs->inputFromConsole();
                keeper.addShape(vs);
            } else if (choice == 3) {
                int idx;
                std::cout << "Enter index to remove: ";
                std::cin >> idx;
                keeper.removeShape(idx);
            } else if (choice == 4) {
                keeper.printAll();
            } else if (choice == 5) {
                keeper.save("data.txt");
            } else if (choice == 6) {
                keeper.load("data.txt");
            } else if (choice == 0) {
                break;
            } else {
                std::cout << "Invalid choice!\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
