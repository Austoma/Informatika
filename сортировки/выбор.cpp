#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

void printArray(int mass[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}
// Функция для сортировки массива методом выбора
void selectionSort(int mass[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        // Находим индекс минимального элемента в оставшейся части массива
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (mass[j] < mass[minIndex])
            {
                minIndex = j;
            }
        }
        // Меняем местами текущий элемент с минимальным
        swap(mass[i], mass[minIndex]);
        printArray(mass,size);
    }
}
// Функция для вывода массива


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

    cout << "Исходный массив: ";
    printArray(mass, size);

    selectionSort(mass, size); // Сортировка массива методом выбора

    cout << "Отсортированный массив: "; // Вывод отсортированного массива
    printArray(mass, size);

    return 0;
}
