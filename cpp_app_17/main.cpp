#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showPointer(T* p) {
    size_t size = _msize(p) / sizeof * p;
    for (size_t i = 0; i < size; i++) {
        cout << *p << ' ';
    }
    cout << endl;
}

template<typename T>
void showArray(T** arr, size_t col, size_t* array_rows_size) {
    cout << "Array dynamic: " << endl;
    for (size_t i = 0; i < col; i++) {
        for (size_t j = 0; j < array_rows_size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
T** add_new_top_line(T** arr, int& col, size_t*& array_rows_size, size_t new_line_size) {
    size_t* new_array_rows_size = new size_t[col + 1];
    for (size_t i = 0; i < col; i++) {
        new_array_rows_size[i + 1] = array_rows_size[i];
    }
    new_array_rows_size[0] = new_line_size;
    col++;
    T** new_arr = new T * [col];
    new_arr[0] = new T[new_line_size];
    for (size_t i = 1; i < col; i++) {
        new_arr[i] = arr[i - 1];
    }
    for (size_t i = 0; i < new_line_size; i++) {
        new_arr[0][i] = rand() % 10;
    }
    delete[] arr;
    delete[] array_rows_size;
    array_rows_size = new_array_rows_size;
    arr = new_arr;
    return arr;
}

int main() {
    srand(time(0));
    int items, rows;
    cout << "rows item = ";
    cin >> rows;
    size_t* array_rows_size = new size_t[rows];
    int** arr_d = new int* [rows];
    for (size_t i = 0; i < rows; i++) {
        cout << "items[" << i << "] = ";
        cin >> items;
        array_rows_size[i] = items;
        arr_d[i] = new int[items];
        for (size_t j = 0; j < items; j++) {
            arr_d[i][j] = rand() % 10;
        }
    }
    showArray(arr_d, rows, array_rows_size);
    cout << endl << endl;
    size_t new_size = 10;
    arr_d = add_new_top_line<int>(arr_d, rows, array_rows_size, new_size);
    showArray(arr_d, rows, array_rows_size);
    return 0;
}
