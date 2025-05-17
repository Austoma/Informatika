#include <iostream>
#include<clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int MyArray[]{ 1, 2, 4, 6, 7, 89, 123, 231, 1000, 1235 };
    int x = 0;
    int a = 0; // Левая граница
    int b = 9; // Правая граница
    int WhatFind = 123; // Искомый элемент
    bool found;

    cout << "Начинаем интерполяционный поиск элемента " << WhatFind << " в массиве." << endl;

    for (found = false; (MyArray[a] < WhatFind) && (MyArray[b] > WhatFind) && !found; )
    {
        // Вычисляем позицию x
        x = a + ((WhatFind - MyArray[a]) * (b - a)) / (MyArray[b] - MyArray[a]);
        cout << "Текущие границы: a = " << a << ", b = " << b << ", x = " << x << " (значение: " << MyArray[x] << ")" << endl;

        if (MyArray[x] < WhatFind) {
            a = x + 1; // Ищем в правой половине
            cout << "Искомый элемент больше, ищем в правой половине." << endl;
        }
        else if (MyArray[x] > WhatFind) {
            b = x - 1; // Ищем в левой половине
            cout << "Искомый элемент меньше, ищем в левой половине." << endl;
        }
        else {
            found = true; // Элемент найден
            cout << "Элемент " << WhatFind << " найден на индексе " << x << "." << endl;
        }
    }

    // Проверка на нахождение элемента
    if (!found) {
        if (MyArray[a] == WhatFind) {
            cout << WhatFind << " найден на индексе " << a << endl;
        }
        else if (MyArray[b] == WhatFind) {
            cout << WhatFind << " найден на индексе " << b << endl;
        }
        else {
            cout << "Извините. Элемент не найден." << endl;
        }
    }

    return 0;
}
