#include <iostream>
#include <clocale>
#include <string>
using namespace std;

// Функция для вывода массива
void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// Функция сортировки подсчетом
void CountingSort(int* a, int* c, int n, int k)
{
    // Обнуляем массив c
    for (int i = 0; i < k; i++)
    {
        c[i] = 0;
    }
    cout << "Массив c после обнуления:\n";
    printArray(c, k);

    // Подсчитываем частоту каждого элемента
    for (int i = 0; i < n; i++)
    {
        c[a[i]] = c[a[i]] + 1;
    }
    cout << "Массив c после подсчета частот:\n";
    printArray(c, k);

    // Восстанавливаем отсортированный массив
    int i = 0;
    for (int j = 0; j < k; j++)
    {
        while (c[j] != 0)
        {
            a[i] = j;
            c[j]--;
            i++;
            cout << "Массив a после изменения:\n";
            printArray(a, n);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;
    int* a = new int[n];
    int k;
    cout << "Диапазон до к, введите к:\n";
    cin >> k;
    int* c = new int[k];

    // Ввод элементов массива
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Вывод исходного массива
    cout << "Исходный массив:\n";
    printArray(a, n);

    // Сортировка массива
    CountingSort(a, c, n, k);

    // Вывод отсортированного массива
    cout << "Отсортированный массив:\n";
    printArray(a, n);

    // Освобождение памяти
    delete[] a;
    delete[] c;

    system("pause");
    return 0;
}
