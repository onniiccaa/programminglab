#include <iostream>

#include "array.h"

template <typename T>
class Stack {
private:
    DynamicArray<T> arr;

public:
    void push(const T& value) {
        arr.insert(arr.getSize(), value);
    }

    void pop() {
        if (!isEmpty()) {
            arr.remove(arr.getSize() - 1);
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    T peek() {
        if (!isEmpty()) {
            return arr.getElement(arr.getSize() - 1);
        } else {
            std::cout << "Stack is empty." << std::endl;
            return T(); // Return a default value if stack is empty
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
    Stack<int> stack;

    while (true) {
        std::cout << "1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                int value;
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                if (!stack.isEmpty()) {
                    stack.pop();
                } else {
                    std::cout << "Stack is empty." << std::endl;
                }
                break;
            case 3:
                if (!stack.isEmpty()) {
                    std::cout << "Peek value: " << stack.peek() << std::endl;
                } else {
                    std::cout << "Stack is empty." << std::endl;
                }
                break;
            case 4:
                std::cout << "Stack contents: ";
                stack.display();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}

