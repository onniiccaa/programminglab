#include <iostream>

#include "array.h"

template <typename T>
class Queue {
private:
    DynamicArray<T> arr;

public:
    void enqueue(const T& value) {
        arr.insert(0, value);
    }

    void dequeue() {
        if (!isEmpty()) {
            arr.remove(arr.getSize() - 1);
        } else {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        }
    }

    T front() {
        if (!isEmpty()) {
            return arr.getElement(arr.getSize() - 1);
        } else {
            std::cout << "Queue is empty." << std::endl;
            return T(); // Return a default value if queue is empty
        }
    }

    bool isEmpty() {
        return arr.getSize() == 0;
    }

    void display() {
        arr.show();
    }
};

int main() {
    Queue<int> queue;

    while (true) {
        std::cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Display Queue\n5. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                int value;
                std::cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                if (!queue.isEmpty()) {
                    queue.dequeue();
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 3:
                if (!queue.isEmpty()) {
                    std::cout << "Front value: " << queue.front() << std::endl;
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 4:
                std::cout << "Queue contents: ";
                queue.display();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}

