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
void showArray(T** arr, size_t rows, size_t* cols)
{
    cout << "Array dynamic: " << endl;
    for (size_t i = 0; i < rows; i++) 
    {
        for (size_t j = 0; j < cols[i]; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
T** addNewColumn(T** arr, size_t rows, size_t* cols, size_t newColSize, size_t position) 
{
    if (position < 0 || position > cols[0]) 
    {
        cout << "Invalid position" << endl;
        return arr;
    }

    T** newArr = new T * [rows];
    for (size_t i = 0; i < rows; i++) 
    {
        newArr[i] = new T[cols[i] + 1];
        for (size_t j = 0; j < cols[i] + 1; j++)
        {
            if (j < position) 
            {
                newArr[i][j] = arr[i][j];
            }
            else if (j == position)
            {
                newArr[i][j] = rand() % 10; 
            }
            else {
                newArr[i][j] = arr[i][j - 1];
            }
        }
        cols[i]++;
    }

    for (size_t i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return newArr;
}

int main()
{
    srand(time(0));
    size_t items, rows;
    cout << "rows = ";
    cin >> rows;
    size_t* cols = new size_t[rows];
    int** arr = new int* [rows];

    for (size_t i = 0; i < rows; i++)
    {
        cout << "items[" << i << "] = ";
        cin >> items;
        cols[i] = items;
        arr[i] = new int[items];
        for (size_t j = 0; j < items; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    showArray(arr, rows, cols);
    cout << endl;

    size_t position;

    cout << "Enter the position where you want to add a new column (0-" << cols[0] << "): ";
    cin >> position;

    arr = addNewColumn<int>(arr, rows, cols, 1, position);

    showArray(arr, rows, cols);

    for (size_t i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] cols;

    return 0;
}
