#include <iostream>

// Node class for the circular linked list
template <typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T val) : value(val), next(nullptr) {}
};

// CircularLinkedList class
template <typename T>
class CircularLinkedList {
private:
    Node<T>* listHead;

public:
    CircularLinkedList() : listHead(nullptr) {}

    // Insert a new element at the end of the circular linked list
    void insertEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!listHead) {
            listHead = newNode;
            newNode->next = listHead; // Circular 
        } else {
            Node<T>* current = listHead;
            while (current->next != listHead) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = listHead; // Circular 
        }
    }

    // Insert a new element at the beginning of the circular linked list
    void insertAtFirst(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!listHead) {
            listHead = newNode;
            newNode->next = listHead; // Circular 
        } else {
            newNode->next = listHead;
            Node<T>* last = listHead;
            while (last->next != listHead) {
                last = last->next;
            }
            listHead = newNode;
            last->next = listHead; // Update the circular 
        }
    }

    // Insert a new element at a specified position in the circular linked list
    void insertAtPosition(T val, int position) {
        if (position < 1) {
            std::cout << "Invalid position. Position should be greater than 0." << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(val);
        if (!listHead) {
            if (position == 1) {
                listHead = newNode;
                newNode->next = listHead; // Circular 
            } else {
                std::cout << "Invalid position. List is empty." << std::endl;
            }
        } else {
            if (position == 1) {
                newNode->next = listHead;
                Node<T>* last = listHead;
                while (last->next != listHead) {
                    last = last->next;
                }
                listHead = newNode;
                last->next = listHead; // Update the circular 
            } else {
                int currentPosition = 1;
                Node<T>* current = listHead;
                while (current->next != listHead && currentPosition < position - 1) {
                    current = current->next;
                    currentPosition++;
                }

                if (currentPosition == position - 1) {
                    newNode->next = current->next;
                    current->next = newNode;
                } else {
                    std::cout << "Invalid position. List is not long enough." << std::endl;
                }
            }
        }
    }

    // Delete an element from the circular linked list
    void deleteElement(T val) {
        if (!listHead) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node<T>* current = listHead;
        Node<T>* prev = nullptr;

        // Find the node with the given value and its previous node
        do {
            if (current->value == val) {
                if (prev) {
                    prev->next = current->next;
                    if (current == listHead) {
                        listHead = current->next; // Update head if deleting the head node
                    }
                    delete current;
                    std::cout << "Element deleted successfully." << std::endl;
                    return;
                } else if (current->next == listHead) {
                    // Only one node in the list
                    listHead = nullptr;
                    delete current;
                    std::cout << "Element deleted successfully." << std::endl;
                    return;
                }
            }
            prev = current;
            current = current->next;
        } while (current != listHead);

        std::cout << "Value not found in the list." << std::endl;
    }

    // Search for an element in the circular linked list
    bool search(T val) const {
        if (!listHead) {
            return false;
        }

        Node<T>* current = listHead;
        do {
            if (current->value == val) {
                return true;
            }
            current = current->next;
        } while (current != listHead);

        return false;
    }

    // View the elements of the circular list
    void show() const {
        if (!listHead) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node<T>* current = listHead;
        do {
            std::cout << current->value << " ";
            current = current->next;
        } while (current != listHead);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList<int> myList;

    int choice;
    int value;
    int position;

    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Insert at the end" << std::endl;
        std::cout << "2. Insert at the beginning" << std::endl;
        std::cout << "3. Insert at a position" << std::endl;
        std::cout << "4. Delete an element" << std::endl;
        std::cout << "5. Search for an element" << std::endl;
        std::cout << "6. Show the list" << std::endl;
        std::cout << "7. Done" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter the value to insert at the end: ";
                std::cin >> value;
                myList.insertEnd(value);
                break;
            }
            case 2: {
                std::cout << "Enter the value to insert at the beginning: ";
                std::cin >> value;
                myList.insertAtFirst(value);
                break;
            }
            case 3: {
                std::cout << "Enter the value to insert: ";
                std::cin >> value;
                std::cout << "Enter the position (1-based index): ";
                std::cin >> position;
                myList.insertAtPosition(value, position);
                break;
            }
            case 4: {
                std::cout << "Enter the value to delete: ";
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
    } while (choice != 7);

    return 0;
}

