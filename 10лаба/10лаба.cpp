#include <iostream>
#include <clocale>
#include <stdlib.h>

using namespace std;
const int I = 10; // Максимальное количество строк
const int J = 10; // Максимальное количество столбцов

// Функция для вывода массива
void printArray(int arr[I][J], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int arr[I][J]; // Исходный массив
    int rows, cols;
    cout << "Введите количество строк и столбцов массива: ";
    cin >> rows >> cols;
    cout << "\nИсходный массив:" << endl;
    // Ввод элементов массива
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20;
            cout << arr[i][j] << "\t"; // вывод исхлдного массива
        }
        cout <<endl;
    }
    // Добавление строки
    int newRowIndex;
    cout << "\nВведите номер строки для добавления: ";
    cin >> newRowIndex;
    newRowIndex -=1;

    if (newRowIndex < 0 || newRowIndex > rows)
    {
        cout << "Некорректный номер строки!" << endl;
        return 1;
    }
    // Сдвигаем строки вниз, начиная с newRowIndex
    for (int i = rows; i > newRowIndex; --i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = arr[i - 1][j];
        }
    }
    // Ввод новой строки
    cout << "Введите элементы новой строки:" << endl;
    for (int j = 0; j < cols; ++j)
    {
        cin >> arr[newRowIndex][j];
    }
    rows++; // Увеличиваем количество строк
    // Вывод массива после добавления строки
    cout << "\nМассив после добавления строки:" << endl;
    printArray(arr, rows, cols);
    // Добавление столбца
    int newColIndex;
    cout << "\nВведите номер столбца для добавления: ";
    cin >> newColIndex;
    newColIndex-=1;

    if (newColIndex < 0 || newColIndex > cols)
    {
        cout << "Некорректный номер столбца!" << endl;
        return 1;
    }

    // Сдвигаем столбцы вправо, начиная с newColIndex
    for (int j = cols; j > newColIndex; --j)
    {
        for (int i = 0; i < rows; ++i)
        {
            arr[i][j] = arr[i][j - 1];
        }
    }

    // Ввод нового столбца
    cout << "Введите элементы нового столбца:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        cin >> arr[i][newColIndex];
    }
    cols++; // Увеличиваем количество столбцов

    // Вывод массива после добавления столбца
    cout << "\nМассив после добавления столбца:" << endl;
    printArray(arr, rows, cols);

    return 0;
}
