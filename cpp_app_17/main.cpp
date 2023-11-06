#include <iostream>

using namespace std;

void shiftRows(int** matrix, int M, int N, int numShifts, string direction) 
{
    int** shiftedMatrix = new int* [M];
    for (int i = 0; i < M; i++) 
    {
        shiftedMatrix[i] = new int[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (direction == "left") 
            {
                int newCol = (j - numShifts + N + N) % N;
                shiftedMatrix[i][newCol] = matrix[i][j];
            }
            else if (direction == "right") 
            {
                int newCol = (j + numShifts) % N;
                shiftedMatrix[i][newCol] = matrix[i][j];
            }
            else {
                shiftedMatrix[i][j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            matrix[i][j] = shiftedMatrix[i][j];
        }
    }

    for (int i = 0; i < M; i++) 
    {
        delete[] shiftedMatrix[i];
    }
    delete[] shiftedMatrix;
}

void shiftColumns(int** matrix, int M, int N, int numShifts, string direction) 
{
    int** shiftedMatrix = new int* [M];
    for (int i = 0; i < M; i++) 
    {
        shiftedMatrix[i] = new int[N];
    }

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (direction == "up")
            {
                int newRow = (i - numShifts + M + M) % M;
                shiftedMatrix[newRow][j] = matrix[i][j];
            }
            else if (direction == "down") 
            {
                int newRow = (i + numShifts) % M;
                shiftedMatrix[newRow][j] = matrix[i][j];
            }
            else {
                shiftedMatrix[i][j] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            matrix[i][j] = shiftedMatrix[i][j];
        }
    }
    for (int i = 0; i < M; i++) 
    {
        delete[] shiftedMatrix[i];
    }
    delete[] shiftedMatrix;
}

void printMatrix(int** matrix, int M, int N) 
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int M, N;
    cout << "Enter the number of rows: ";
    cin >> M;
    cout << "Enter the number of columns: ";
    cin >> N;

    int** matrix = new int* [M];
    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = i * N + j + 1;
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, M, N);

    int numShifts;
    string direction;

    cout << "Enter the number of shifts: ";
    cin >> numShifts;
    cout << "Enter the direction (left/right/up/down): ";
    cin >> direction;

    if (direction == "left" || direction == "right") 
    {
        shiftRows(matrix, M, N, numShifts, direction);
    }
    else if (direction == "up" || direction == "down") 
    {
        shiftColumns(matrix, M, N, numShifts, direction);
    }

    cout << "Shifted Matrix:" << endl;
    printMatrix(matrix, M, N);

    for (int i = 0; i < M; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
