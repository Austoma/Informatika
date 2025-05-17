#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;
// Функция для сортировки массива методом пузырька

// Функция для вывода массива
void printArray(int mass[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int mass[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            // Если текущий элемент больше следующего, меняем их местами
            if (mass[j] > mass[j + 1])
            {
                swap(mass[j], mass[j + 1]);
            }
        }
        printArray(mass,size);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    // Ввод размера массива
    cout << "Введите размер массива: ";
    cin >> size;

    int mass[size];

    // Ввод элементов массива
    for (int i = 0; i < size; ++i)
    {
        mass[i] = rand() % 100;
    }
    // Вывод исходного массива
    cout << "Исходный массив: ";
    printArray(mass, size);

    // Сортировка массива методом пузырька
    bubbleSort(mass, size);

    // Вывод отсортированного массива
    cout << "Отсортированный массив: ";
    printArray(mass, size);

    return 0;
}
