#include <iostream>
#include <algorithm>
#include <clocale>
using namespace std;

const int ROWS = 4; // Количество строк
const int COLS = 5; // Количество столбцов

// Функция для проверки, упорядочена ли строка по возрастанию
bool isAscending(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Функция для проверки, упорядочена ли строка по убыванию
bool isDescending(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Функция для сортировки строки по возрастанию
void sortAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                // Меняем элементы местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[ROWS][COLS] = {
        {1, 2, 6, 4, 5},    // Упорядочена по возрастанию
        {9, 7, 5, 3, 1},    // Упорядочена по убыванию
        {4, 2, 8, 6, 10},   // Не упорядочена
        {10, 8, 6, 4, 2}    // Упорядочена по убыванию
    };

    // Вывод исходного массива
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Проверка и сортировка строк
    for (int i = 0; i < ROWS; ++i)
    {
        if (!isDescending(arr[i], COLS))
        {
            cout << "Строка " << i + 1 << " изменена." << endl;
            sortAscending(arr[i], COLS);
        }
    }

    // Вывод измененного массива
    cout << "\nМассив после сортировки:" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
