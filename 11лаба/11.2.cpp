#include <iostream>
#include <clocale>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите A, B, C" << endl;
    double a, b, c;
    cin >> a >> b >> c;
    double d = b*b-4*a*c;
    if (a==0)
    {
        if (b!=0)
        {
            cout << "Единственный x = " << -c/b << endl;
        }
        else
        {
            cout << "Нет решений" << endl;
        }
    }
    else
    {
        if (d > 0)
        {
            cout << "2 решения:" << (-b+sqrt(b))/(2*a) << " " << (-b-sqrt(b))/(2*a) << endl;
        }
        else
        {
            if (d==0)
            {
                cout << "Единственный x = " << -b/(2*a) << endl;
            }
            else
            {
                cout << "Нет решений" << endl;
            }
        }
    }
    return 0;
}
