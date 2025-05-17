#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

const int M = 100; // Максимальный размер матрицы

void transposeMatrix(int mat[M][M], int transposed[M][M], int str, int cols) //создает транспонированную матрицу, переставляя строки и столбцы исходной матрицы
{
    for (int i = 0; i < str; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            transposed[j][i] = mat[i][j];
        }
    }
}
void printMatrix(int mat[M][M], int str, int cols)
{
    for (int i = 0; i < str; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int mat[M][M], transposed[M][M];
    int str, cols;

    // Ввод размеров матрицы
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> str >> cols;

    // Ввод элементов матрицы
    for (int i = 0; i < str; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            mat[i][j] = rand() % 100;
        }
    }

    // Транспонирование матрицы
    transposeMatrix(mat, transposed, str, cols);

    // Вывод исходной матрицы
    cout << "Исходная матрица:" << endl;
    printMatrix(mat, str, cols);

    // Вывод транспонированной матрицы
    cout << "Транспонированная матрица:" << endl;
    printMatrix(transposed, cols, str);

    return 0;
}
