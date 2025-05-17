#include <iostream>
using namespace std;

// Перегруженная функция для умножения десятичных дробей
double multiply(double a, double b) {
    return a * b;
}

// Перегруженная функция для умножения обыкновенных дробей
void multiply(int n1, int d1, int n2, int d2, int& resultN, int& resultD)
{
    resultN = n1 * n2;  // Умножение числителей
    resultD = d1 * d2;  // Умножение знаменателей
}

int main() {
    // Пример вызова функции для десятичных дробей
    auto a = 0.5;
    auto b = 0.25;
    auto dResult = multiply(a, b);
    cout << a << " * " << b << " = " << dResult << '\n';

    // Пример вызова функции для обыкновенных дробей
    int n1 = 1, d1 = 2;  // 1/2
    int n2 = 3, d2 = 4;  // 3/4
    int resultN, resultD;
    multiply(n1, d1, n2, d2, resultN, resultD);
    cout << n1 << "/" << d1 << " * " << n2 << "/" << d2 << " = " << resultN << "/" << resultD;

    return 0;
}
