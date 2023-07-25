#include <iostream>

// Node class for the doubly linked list
template <typename T>
class Node {
public:
    T value;
    Node* prev;
    Node* next;

    Node(T val) : value(val), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList class
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* listHead;
    Node<T>* listTail;

public:
    DoublyLinkedList() : listHead(nullptr), listTail(nullptr) {}

    // Insert a new element at the end of the doubly linked list
    void insertEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!listHead) {
            listHead = listTail = newNode;
        } else {
            listTail->next = newNode;
            newNode->prev = listTail;
            listTail = newNode;
        }
    }

    // Delete an element from the doubly linked list
    void deleteElement(T val) {
        Node<T>* current = listHead;
        while (current) {
            if (current->value == val) {
                if (current == listHead) {
                    listHead = listHead->next;
                    if (listHead)
                        listHead->prev = nullptr;
                } else if (current == listTail) {
                    listTail = listTail->prev;
                    if (listTail)
                        listTail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        std::cout << "Value not found in the list." << std::endl;
    }

    // Search for an element in the doubly linked list
    bool search(T val) const {
        Node<T>* current = listHead;
        while (current) {
            if (current->value == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // View the elements of the list
    void show() const {
        Node<T>* current = listHead;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> myList;

    int choice;
    int value;

    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Insert at the end" << std::endl;
        std::cout << "2. Delete an element" << std::endl;
        std::cout << "3. Search for an element" << std::endl;
        std::cout << "4. Show the list" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter the value to insert at the end of list: ";
                std::cin >> value;
                myList.insertEnd(value);
                break;
            }
            case 2: {
                std::cout << "Enter the value to delete from list: ";
                std::cin >> value;
                myList.deleteElement(value);
                break;
            }
            case 3: {
                std::cout << "Enter the value to search for: ";
                std::cin >> value;
                std::cout << "Value " << (myList.search(value) ? "found" : "not found") << " in the list." << std::endl;
                break;
            }
            case 4: {
                myList.show();
                break;
            }
            case 5: {
                std::cout << "Over..." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

