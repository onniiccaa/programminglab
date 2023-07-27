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
     // Insert a new element at the start of the doubly linked list
    void insertAtFirst(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!listHead) {
            listHead = listTail = newNode;
        } else {
            newNode->next = listHead;
            listHead->prev = newNode;
            listHead = newNode;
        }
    }

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
    // Insert a new element at a specific position in the doubly linked list
    void insertAtPosition(T val, int position) {
        if (position <= 0) {
            std::cout << "Invalid position. Position can't be a negative value." << std::endl;
            return;
        }

        if (position == 1) {
            insertAtFirst(val);
            return;
        }

        Node<T>* newNode = new Node<T>(val);
        Node<T>* current = listHead;
        int count = 1;

        while (current && count < position) {
            current = current->next;
            count++;
        }

        if (!current && count < position) {
            std::cout << "Invalid position, as it exceeds the size of the list." << std::endl;
            delete newNode;
            return;
        }

        Node<T>* previous = current->prev;
        previous->next = newNode;
        newNode->prev = previous;
        newNode->next = current;
        current->prev = newNode;
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
        std::cout<< "2.Insert at first"<<std::endl;
        std::cout<<" 3 Insert at position "<<std::endl;
        std::cout << "4. Delete an element" << std::endl;
        std::cout << "5. Search for an element" << std::endl;
        std::cout << "6. Show the list" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter the value to insert at the end of list: ";
                std::cin >> value;
                myList.insertEnd(value);
                break;
            }
            case 2:{
                std::cout<<"Enter the value to insert at fisrt of list : ";
                std::cin>>value;
                myList.insertatfirst(value);
                break;
            }
            case 3:{
                std::cout<<"Enter the value to insert: ";
                std::cin>>value;
                std::cout<<"Enter position : ';
                std::cin>>Position;
                myList.insertAtPosition(value,Position);
                break;
            }
            case 4: {
                std::cout << "Enter the value to delete from list: ";
                std::cin >> value;
                myList.deleteElement(value);
                break;
            }
            case 5: {
                std::cout << "Enter the value to search for: ";
                std::cin >> value;
                std::cout << "Value " << (myList.search(value) ? "found" : "not found") << " in the list." << std::endl;
                break;
            }
            case 6: {
                myList.show();
                break;
            }
            case 7: {
                std::cout << "Over..." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

