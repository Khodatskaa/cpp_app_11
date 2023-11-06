#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showPointer(T* p)
{
    size_t size = _msize(p) / sizeof * p;
    for (size_t i = 0; i < size; i++) 
    {
        cout << *p << ' ';
    }
    cout << endl;
}

template<typename T>
void showArray(T** arr, size_t col, size_t* array_rows_size)
{
    cout << "Array dynamic: " << endl;
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < array_rows_size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
T** deleteLine(T** arr, int& col, size_t*& arrayRowsSize, int position) 
{
    if (position < 0 || position >= col) 
    {
        cout << "Invalid position. No line deleted." << endl;
        return arr;
    }

    size_t* newRowsSize = new size_t[col - 1];
    T** newArr = new T * [col - 1];

    for (int i = 0, j = 0; i < col; i++)
    {
        if (i == position)
        {
            delete[] arr[i];
            continue;
        }

        newRowsSize[j] = arrayRowsSize[i];
        newArr[j] = arr[i];
        j++;
    }

    delete[] arr;
    delete[] arrayRowsSize;
    arrayRowsSize = newRowsSize;
    col--;

    return newArr;
}

int main() 
{
    srand(time(0));
    int items, rows;
    cout << "rows item = ";
    cin >> rows;
    size_t* arrayRowsSize = new size_t[rows];
    int** arr = new int* [rows];

    for (size_t i = 0; i < rows; i++) 
    {
        cout << "items[" << i << "] = ";
        cin >> items;
        arrayRowsSize[i] = items;
        arr[i] = new int[items];
        for (size_t j = 0; j < items; j++) 
        {
            arr[i][j] = rand() % 10;
        }
    }

    showArray(arr, rows, arrayRowsSize);
    cout << endl;

    int position;

    cout << "Enter the position of the line you want to delete (0-" << (rows - 1) << "): ";
    cin >> position;

    arr = deleteLine<int>(arr, rows, arrayRowsSize, position);

    showArray(arr, rows, arrayRowsSize);

    return 0;
}
