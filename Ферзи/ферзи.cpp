#include <iostream>
#include <clocale>
using namespace std;

const int n = 8; // Размер шахматной доски
int board[n][n]; // Доска

// Функция для вывода доски
void printBoard()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == -1)
                cout << " Q "; // Ферзь
            else
                cout << " . "; // Пустая клетка
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}

// Функция для сброса ферзя с позиции (i, j)
void resetQ(int i, int j)
{
    for (int x = 0; x < n; ++x)
    {
        --board[x][j]; // Уменьшаем значение по столбцу
        --board[i][x]; // Уменьшаем значение по строке
        int k;
        k = j - i + x; // Диагональ 1
        if (k >= 0 && k < n)
            --board[x][k];
        k = j + i - x; // Диагональ 2
        if (k >= 0 && k < n)
            --board[x][k];
    }
    board[i][j] = 0; // Сбрасываем ферзя
}

// Функция для установки ферзя на позицию (i, j)
void setQ(int i, int j)
{
    for (int x = 0; x < n; ++x)
    {
        ++board[x][j]; // Увеличиваем значение по столбцу
        ++board[i][x]; // Увеличиваем значение по строке
        int k;
        k = j - i + x; // Диагональ 1
        if (k >= 0 && k < n)
            ++board[x][k];
        k = j + i - x; // Диагональ 2
        if (k >= 0 && k < n)
            ++board[x][k];
    }
    board[i][j] = -1; // Устанавливаем ферзя
}

// Рекурсивная функция для размещения ферзей
bool tryQ(int i)
{
    bool result = false;
    for (int j = 0; j < n; ++j)
    {
        if (board[i][j] == 0)
        { // Если клетка свободна
            setQ(i, j); // Устанавливаем ферзя
            cout << "Ферзь размещен на (" << i << ", " << j << "):" << endl;
            printBoard(); // Выводим текущее состояние доски

            if (i == n - 1)
            { // Если все ферзи размещены
                result = true;
            }
            else
            {
                result = tryQ(i + 1); // Рекурсивно размещаем следующий ферзь
                if (!result)
                {
                    resetQ(i, j); // Если решение не найдено, сбрасываем ферзя
                    cout << "Откат: ферзь снят с (" << i << ", " << j << "):" << endl;
                    printBoard(); // Выводим состояние доски после отката
                }
            }
        }
        if (result) break; // Если решение найдено, выходим из цикла
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");
    // Инициализация доски
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            board[i][j] = 0;

    // Запуск решения
    tryQ(0);

    // Вывод финального решения
    cout << "Финальное решение:" << endl;
    printBoard();

    return 0;
}
