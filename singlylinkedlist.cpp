#include <iostream>

// Node class for the singly linked list
template <typename T>
class Node {
public:
    T value;
    Node* nodePtr; 

    Node(T val) : value(val), nodePtr(nullptr) {}
};

// SinglyLinkedList class
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* listHead; 

public:
    SinglyLinkedList() : listHead(nullptr) {}

    // Insert a new element at the end of the singly linked list
    void insertEnd(T val) {
        Node<T>* newNode = new Node<T>(val);

        if (!listHead) {
            listHead = newNode;
        } else {
            Node<T>* temp = listHead;
            while (temp->nodePtr) {
                temp = temp->nodePtr;
            }
            temp->nodePtr = newNode; 
        }
    }

    // Insert a new element at the start of the singly inked list
    void insertStart(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->nodePtr = listHead; 
        listHead = newNode; 
    }

    // Insert a new element at a specific position in the singly linked list
    void insertAtPosition(T val, int position) {
    if (position <= 0) {
        std::cout << "Invalid position. Position can't be a negative value." << std::endl;
        return;
    }

    Node<T>* newNode = new Node<T>(val);
    
    if (position == 1) {
        newNode->nodePtr = listHead;
        listHead = newNode;
    } else {
        Node<T>* previous = listHead;
        int count = 1;
        while (previous && count < position - 1) {
            previous = previous->nodePtr;
            count++;
        }
        
        if (!previous) {
            std::cout << "Invalid position, as it exceeds the size of the list." << std::endl;
            delete newNode;
            return;
        }
        
        Node<T>* current = previous->nodePtr;
        newNode->nodePtr = current;
        previous->nodePtr = newNode;
    }
}


    // Delete the first occurrence of an element from the singly linked list
    void deleteElement(T val) {
        if (!listHead) { 
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (listHead->value == val) { 
            Node<T>* temp = listHead;
            listHead = listHead->nodePtr; 
            delete temp;
            return;
        }

        Node<T>* prev = listHead; 
        Node<T>* curr = listHead->nodePtr; 
        while (curr) {
            if (curr->value == val) {
                prev->nodePtr = curr->nodePtr; 
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->nodePtr; 
        }

        std::cout << "List doesn't contain value." << std::endl;
    }

    // View the elements of the singly linked list
    void show() const {
        Node<T>* temp = listHead; 
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->nodePtr; 
        }
        std::cout << std::endl;
    }
};

//int main() {
//    SinglyLinkedList<int> myList;
//
//    int choice;
//    do {
//        std::cout << "Select choice:" << std::endl;
//        std::cout << "1. Insert at the end" << std::endl;
//        std::cout << "2. Insert at the start" << std::endl;
//        std::cout << "3. Insert at a specific position" << std::endl;
//        std::cout << "4. Delete an element" << std::endl;
//        std::cout << "5. View the list" << std::endl;
//        std::cout << "6. Exit" << std::endl;
//        std::cout << "choice: ";
//        std::cin >> choice;
//
//        switch (choice) {
//            case 1: {
//                int val;
//                std::cout << "Enter the value to insert at the end of list: ";
//                std::cin >> val;
//                myList.insertEnd(val);
//                break;
//            }
//            case 2: {
//                int val;
//                std::cout << "Enter the value to insert at the start of list: ";
//                std::cin >> val;
//                myList.insertStart(val);
//                break;
//            }
//            case 3: {
//                int val, position;
//                std::cout << "Enter the value to insert in list: ";
//                std::cin >> val;
//                std::cout << "Enter the position where you want ot insert: ";
//                std::cin >> position;
//                myList.insertAtPosition(val, position);
//                break;
//            }
//            case 4: {
//                int val;
//                std::cout << "Enter the value to delete: ";
//                std::cin >> val;
//                myList.deleteElement(val);
//                break;
//            }
//            case 5: {
//                myList.show();
//                break;
//            }
//            case 6: {
//                std::cout << "Over..." << std::endl;
//                break;
//            }
//            default:
//                std::cout << "Invalid choice. Please try again." << std::endl;
//        }
//    } while (choice != 6);
//
//    return 0;
//}
//
//
