#include <iostream>

const int MAX_SIZE = 100;

template <typename T>
class DynamicArray {
private:
    T data[MAX_SIZE];
    int size;

public:
    DynamicArray() : size(0) {}

    void insert(int loc, const T& value) {
        if (size >= MAX_SIZE) {
            std::cout << "Array is full. Cannot insert." << std::endl;
            return;
        }

        if (loc < 0 || loc > size) {
            std::cout << "Invalid location. Cannot insert." << std::endl;
            return;
        }

        for (int i = size - 1; i >= loc; i--) {
            data[i + 1] = data[i];
        }

        data[loc] = value;
        size++;
    }

    void remove(int loc) {
        if (loc < 0 || loc >= size) {
            std::cout << "Invalid location. Cannot delete." << std::endl;
            return;
        }

        for (int i = loc; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    int search(const T& value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return i;
            }
        }

        return -1;
    }

    void show() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray<int> dynamicArray;

    int choice;
    int loc, value;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert element" << std::endl;
        std::cout << "2. Delete element" << std::endl;
        std::cout << "3. Search element" << std::endl;
        std::cout << "4. Show array" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the location to insert: ";
            std::cin >> loc;
            std::cout << "Enter the value to insert: ";
            std::cin >> value;
            dynamicArray.insert(loc, value);
            break;
        case 2:
            std::cout << "Enter the location to delete: ";
            std::cin >> loc;
            dynamicArray.remove(loc);
            break;
        case 3:
            std::cout << "Enter the value to search: ";
            std::cin >> value;
            loc = dynamicArray.search(value);
            if (loc != -1) {
                std::cout << value << " found at location " << loc << std::endl;
            } else {
                std::cout << value << " not found in the array." << std::endl;
            }
            break;
        case 4:
            std::cout << "Array elements: ";
            dynamicArray.show();
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }

    } while (choice != 5);

    return 0;
}

