#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
void showPointer(T* p) {
    size_t size = _msize(p) / sizeof * p;
    for (size_t i = 0; i < size; i++) {
        cout << *p << ' ';
    }
    cout << endl;
}

template <typename T>
void showArray(T** arr, size_t rows, size_t* cols) {
    cout << "Array dynamic: " << endl;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
T** deleteColumn(T** arr, size_t rows, size_t*& cols, size_t columnNumber) {
    if (columnNumber < 0 || columnNumber >= cols[0]) {
        cout << "Invalid column number. No column deleted." << endl;
        return arr;
    }

    T** newArr = new T * [rows];
    for (size_t i = 0; i < rows; i++) {
        newArr[i] = new T[cols[i] - 1];
        for (size_t j = 0, k = 0; j < cols[i]; j++) {
            if (j == columnNumber) {
                continue;  // Skip the column to be deleted
            }
            newArr[i][k] = arr[i][j];
            k++;
        }
        cols[i]--;
    }

    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return newArr;
}

int main() {
    srand(time(0));
    size_t items, rows;
    cout << "rows = ";
    cin >> rows;
    size_t* cols = new size_t[rows];
    int** arr = new int* [rows];

    for (size_t i = 0; i < rows; i++) {
        cout << "items[" << i << "] = ";
        cin >> items;
        cols[i] = items;
        arr[i] = new int[items];
        for (size_t j = 0; j < items; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    showArray(arr, rows, cols);
    cout << endl;

    size_t columnNumber;

    cout << "Enter the column number you want to delete (0-" << (cols[0] - 1) << "): ";
    cin >> columnNumber;

    arr = deleteColumn<int>(arr, rows, cols, columnNumber);

    showArray(arr, rows, cols);

    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] cols;

    return 0;
}
