#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

// Функция для вывода массива
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    // 1. Сформировать одномерный массив целых чисел
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size]; // Выделяем память для массива
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100; // Генерация чисел от 1 до 100
        cout << arr[i] << " ";  // 2. Распечатать исходный массив
    }
    cout << endl;
    // 3. Удалить 5 последних элементов массива
    if (size >= 5)
    {
        size -= 5; // Уменьшаем размер массива на 5
    }
    else
    {
        cout << "Массив слишком мал для удаления 5 элементов." << endl;
        delete[] arr; // Освобождаем память
        return 1;
    }
    cout << "Массив после удаления 5 элементов: ";
    printArray(arr, size);

    // 4. Добавить в начало массива 3 элемента с значением M[I+1] + 2
    // Создаем новый массив с увеличенным размером
    int newSize = size + 3;
    int* newArr = new int[newSize];
    // Добавляем новые элементы в начало
    for (int i = 0; i < 3; ++i)
    {
        newArr[i] = arr[i + 1] + 2;
    }
    // Копируем оставшиеся элементы из старого массива
    for (int i = 0; i < size; ++i)
    {
        newArr[i + 3] = arr[i];
    }
    delete[] arr; // Освобождаем память старого массива
    cout << "Массив после удаления и добавления элементов: ";
    printArray(newArr, newSize); // 5. Распечатать полученный массив
    return 0;
}
