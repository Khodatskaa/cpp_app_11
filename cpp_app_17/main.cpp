#include <iostream>

using namespace std;

// Function to perform cyclic shifts on rows of the matrix
void shiftRows(int** matrix, int rows, int cols, int numShifts, string direction) {
    int** shiftedMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        shiftedMatrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (direction == "left") {
                int newCol = (j - numShifts + cols) % cols;
                shiftedMatrix[i][newCol] = matrix[i][j];
            }
            else if (direction == "right") {
                int newCol = (j + numShifts) % cols;
                shiftedMatrix[i][newCol] = matrix[i][j];
            }
            else {
                shiftedMatrix[i][j] = matrix[i][j];
            }
        }
    }

    // Copy the shifted matrix back to the original matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = shiftedMatrix[i][j];
        }
    }

    // Deallocate memory for the shifted matrix
    for (int i = 0; i < rows; i++) {
        delete[] shiftedMatrix[i];
    }
    delete[] shiftedMatrix;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Enter matrix elements row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int numShifts;
    string direction;

    cout << "Enter the number of shifts: ";
    cin >> numShifts;
    cout << "Enter the direction (left/right): ";
    cin >> direction;

    shiftRows(matrix, rows, cols, numShifts, direction);

    cout << "Matrix after row shifting:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory for the matrix
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
