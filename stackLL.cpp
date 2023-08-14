#include <iostream>
#include "singlylinkedlist.h"

// Stack implementation using SinglyLinkedList
class Stack {
private:
    SinglyLinkedList list;

public:
    void push(int value) {
        list.insertEnd(value);
    }

    void pop() {
        list.deleteElement();
    }

    int peek() {
        if (!isEmpty()) {
            Node* current = list.head;
            while (current->next) {
                current = current->next;
            }
            return current->data;
        }
        return -1; // Indicate empty stack with -1 value
    }

    bool isEmpty() {
        return list.head == nullptr;
    }

    void displayStack() {
        list.show();
    }
};

int main() {
    Stack stack;

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
                stack.displayStack();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}

