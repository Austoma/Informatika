#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

// Функция для вычисления факториала n
double factorial(int n) 
{
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    return n * factorial(n - 1);
}

// Рекурсивная функция для вычисления S
double S(int n, double x) 
{
    // Базовый случай
    if (n == 0) 
    {
        return 1; // S(0) = 1
    }
    
    // Вычисляем текущий элемент
    double el = (2 * n + 1) * pow(x, 2 * n) / factorial(n);
    
    // Рекурсивный вызов для суммы
    return el + S(n - 1, x);
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int n;
    double x;

    cout << "Введите значение n, x: " << endl;
    cin >> n >> x;

    double result = S(n, x);
    cout << "Результат S = " << result << endl;

    return 0;
}
