#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������� A, B, C" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    if (a>b)
    {
        if (a>c)
        {
            cout << "������������ ����� a = " << a << endl;
        }
        else
        {
            cout << "������������ ����� c = " << c << endl;
        }
    }
    else
    {
        if (b > c)
        {
            cout << "������������ ����� b = " << b << endl;
        }
        else
        {
            cout << "������������ ����� c = " << c << endl;
        }
    }
    return 0;
}
