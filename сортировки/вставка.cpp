#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

// Функция для вывода массива
void printArray(int mass[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << mass[i] << " ";
    }
    cout << endl;
}
// Функция для сортировки массива методом вставки
void insertionSort(int mass[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = mass[i]; // Запоминаем текущий элемент
        int j = i - 1;

        // Сдвигаем элементы, которые больше key, вправо
        while (j >= 0 && mass[j] > key)
        {
            mass[j + 1] = mass[j];
            j--;
        }
        // Вставляем key в правильную позицию
        mass[j + 1] = key;
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

    // Сортировка массива методом вставки
    insertionSort(mass, size);

    // Вывод отсортированного массива
    cout << "Отсортированный массив: ";
    printArray(mass, size);
    return 0;
}
