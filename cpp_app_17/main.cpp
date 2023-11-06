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
T** addNewLine(T** arr, int& col, size_t*& arrayRowsSize, size_t newLineSize, int position)
{
    if (position < 0 || position > col) 
    {
        cout << "Invalid position. The line won't be added." << endl;
        return arr;
    }

    size_t* newRowsSize = new size_t[col + 1];
    for (int i = 0; i < col; i++) 
    {
        newRowsSize[i + (i >= position)] = arrayRowsSize[i];
    }
    newRowsSize[position] = newLineSize;
    col++;

    T** newArr = new T * [col];
    for (int i = 0; i < col; i++) 
    {
        if (i < position)
        {
            newArr[i] = arr[i];
        }
        else if (i == position)
        {
            newArr[i] = new T[newLineSize];
            for (size_t j = 0; j < newLineSize; j++) 
            {
                newArr[i][j] = rand() % 10;
            }
        }
        else {
            newArr[i] = arr[i - 1];
        }
    }

    delete[] arr;
    delete[] arrayRowsSize;
    arrayRowsSize = newRowsSize;
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

    size_t newLineSize = 10;
    int position;

    cout << "Enter the position for the new line (0-" << rows << "): ";
    cin >> position;

    arr = addNewLine<int>(arr, rows, arrayRowsSize, newLineSize, position);

    showArray(arr, rows, arrayRowsSize);

    return 0;
}
