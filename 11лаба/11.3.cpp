#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите A, B, C" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    if (a>b)
    {
        if (a>c)
        {
            cout << "Максимальное число a = " << a << endl;
        }
        else
        {
            cout << "Максимальное число c = " << c << endl;
        }
    }
    else
    {
        if (b > c)
        {
            cout << "Максимальное число b = " << b << endl;
        }
        else
        {
            cout << "Максимальное число c = " << c << endl;
        }
    }
    return 0;
}
