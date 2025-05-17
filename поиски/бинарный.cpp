#include <iostream>
#include<clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int MyArray[]{ 1, 2, 4, 6, 7, 89, 123, 231, 1000, 1235 };
    int left = 0;               // Левая граница поиска
    int right = 9;              // Правая граница поиска (размер массива - 1)
    int WhatFind = 123;         // Искомый элемент
    bool found = false;         // Флаг нахождения элемента
    int index = -1;             // Индекс найденного элемента

    cout << "Начинаем бинарный поиск элемента " << WhatFind << " в массиве." << endl;

    while (left <= right && !found) {
        int mid = left + (right - left) / 2; // Средний элемент
        cout << "Текущие границы: left = " << left << ", right = " << right << ", mid = " << mid << " (значение: " << MyArray[mid] << ")" << endl;

        if (MyArray[mid] == WhatFind) {
            found = true;
            index = mid;
            cout << "Элемент " << WhatFind << " найден на индексе " << index << "." << endl;
        } else if (MyArray[mid] < WhatFind) {
            left = mid + 1;     // Ищем в правой половине
            cout << "Искомый элемент больше, ищем в правой половине." << endl;
        } else {
            right = mid - 1;    // Ищем в левой половине
            cout << "Искомый элемент меньше, ищем в левой половине." << endl;
        }
    }

    if (found) {
        cout << WhatFind << " найден на индексе " << index << endl;
    } else {
        cout << "Извините. Элемент не найден." << endl;
    }

    return 0;
}
