//Задача на вывод квадратов нечётных целых чисел от 1 до предела, который вводит пользователь
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;  // предельное наибольшее число
    cout << "Введите предел: ";
    cin >> n;  // вводим число
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << ": " << i * i << endl;
    }
    return 0;
}
