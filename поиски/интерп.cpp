#include <iostream>
#include<clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int MyArray[]{ 1, 2, 4, 6, 7, 89, 123, 231, 1000, 1235 };
    int x = 0;
    int a = 0; // ����� �������
    int b = 9; // ������ �������
    int WhatFind = 123; // ������� �������
    bool found;

    cout << "�������� ���������������� ����� �������� " << WhatFind << " � �������." << endl;

    for (found = false; (MyArray[a] < WhatFind) && (MyArray[b] > WhatFind) && !found; )
    {
        // ��������� ������� x
        x = a + ((WhatFind - MyArray[a]) * (b - a)) / (MyArray[b] - MyArray[a]);
        cout << "������� �������: a = " << a << ", b = " << b << ", x = " << x << " (��������: " << MyArray[x] << ")" << endl;

        if (MyArray[x] < WhatFind) {
            a = x + 1; // ���� � ������ ��������
            cout << "������� ������� ������, ���� � ������ ��������." << endl;
        }
        else if (MyArray[x] > WhatFind) {
            b = x - 1; // ���� � ����� ��������
            cout << "������� ������� ������, ���� � ����� ��������." << endl;
        }
        else {
            found = true; // ������� ������
            cout << "������� " << WhatFind << " ������ �� ������� " << x << "." << endl;
        }
    }

    // �������� �� ���������� ��������
    if (!found) {
        if (MyArray[a] == WhatFind) {
            cout << WhatFind << " ������ �� ������� " << a << endl;
        }
        else if (MyArray[b] == WhatFind) {
            cout << WhatFind << " ������ �� ������� " << b << endl;
        }
        else {
            cout << "��������. ������� �� ������." << endl;
        }
    }

    return 0;
}
