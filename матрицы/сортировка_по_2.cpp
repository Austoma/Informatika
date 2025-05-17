#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;
const int M = 100; // Максимальный размер массива
// Функция для сортировки двумерного массива по второй строке
void sort(int mat[M][M], int str, int cols)
{
    // Пузырьковая сортировка для перестановки столбцов
    for (int i = 0; i < cols - 1; ++i)
    {
        for (int j = 0; j < cols - i - 1; ++j)
        {
            // Сравниваем элементы во второй строке
            if (mat[1][j] > mat[1][j + 1])
            {
                // Меняем местами столбцы
                for (int k = 0; k < str; ++k)
                {
                    swap(mat[k][j], mat[k][j + 1]);
                }
            }
        }
    }
}
// Функция для вывода двумерного массива
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
    int mat[M][M];
    int str, cols;

    // Ввод размеров массива
    cout << "Введите количество строк и столбцов массива: ";
    cin >> str >> cols;

    // Ввод элементов массива
    for (int i = 0; i < str; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            mat[i][j] = rand() % 100;
        }
    }
    cout << "Исходный массив:" << endl;
    printMatrix(mat, str, cols);
    // Сортировка по второй строке
    sort(mat, str, cols);
    // Вывод отсортированного массива
    cout << "Отсортированный массив по второй строке:" << endl;
    printMatrix(mat, str, cols);

    return 0;
}
