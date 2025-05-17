#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, x;
    cout << "Введите a" << endl;
    cin >> a;
    cout << "Введите b" << endl;
    cin >> b;
    if (b==0)
    {
        if (a != 0)
        {
            x = 0;
            cout << "Ответ: " << x << endl;
        }
        else
        {
            cout << "Любой x" << endl;
        }
    }
    else
    {
        if (a==0)
        {
            cout << "Ошибка" << endl;
        }
        else
        {
            x = b/a;
            cout << "Ответ: " << x << endl;
        }
    }
    return 0;
}
