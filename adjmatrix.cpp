#include <iostream>
#include "array.cpp" // Include the header for the DynamicArray class

using namespace std;

template<typename T>
class AdjacencyMatrix {
private:
    DynamicArray<T> matrix; 
    int size;

public:
    AdjacencyMatrix(int size) : size(size) {
        
        for (int i = 0; i < size * size; i++) {
            matrix.insert(i, T());
        }
    }

    void setEdge(int row, int col, const T& weight) {
        int index = row * size + col;
        if (row >= 0 && row < size && col >= 0 && col < size) {
            matrix.insert(index, weight);
        }
    }

    int getEdge(int row, int col) const {
        int index = row * size + col;
        if (row >= 0 && row < size && col >= 0 && col < size) {
            return matrix.getElement(index);
        }
        return T(); 
    }

    int getSize() const {
        return size;
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << getEdge(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;

    AdjacencyMatrix<int> adjMatrix(size);

    int row, col;
    double weight;
    while (true) {
        cout << "Enter the row, column, and weight (-1 to exit): ";
        cin >> row >> col >> weight;

        if (row == -1 || col == -1 || weight == -1) {
            break;
        }

        adjMatrix.setEdge(row, col, weight);
    }

    cout << "Adjacency Matrix:" << endl;
    adjMatrix.display();

    return 0;
}


