#include <iostream>

#include "singlylinkedlist.h"

// Queue implementation using SinglyLinkedList
class Queue {
private:
    SinglyLinkedList list;

public:
    void enqueue(int value) {
        list.insertEnd(value);
    }

    void dequeue() {
        list.deleteAtFront();
    }

    int front() {
        if (!isEmpty()) {
            return list.front();
        }
        return -1; // Indicate empty queue with -1 value
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void displayQueue() {
        list.show();
    }
};

int main() {
    Queue queue;

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
                queue.displayQueue();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}

