#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, x;
    cout << "������� a" << endl;
    cin >> a;
    cout << "������� b" << endl;
    cin >> b;
    if (b==0)
    {
        if (a != 0)
        {
            x = 0;
            cout << "�����: " << x << endl;
        }
        else
        {
            cout << "����� x" << endl;
        }
    }
    else
    {
        if (a==0)
        {
            cout << "������" << endl;
        }
        else
        {
            x = b/a;
            cout << "�����: " << x << endl;
        }
    }
    return 0;
}
