#include <iostream>
#include<clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int MyArray[]{ 1, 2, 4, 6, 7, 89, 123, 231, 1000, 1235 };
    int left = 0;               // ����� ������� ������
    int right = 9;              // ������ ������� ������ (������ ������� - 1)
    int WhatFind = 123;         // ������� �������
    bool found = false;         // ���� ���������� ��������
    int index = -1;             // ������ ���������� ��������

    cout << "�������� �������� ����� �������� " << WhatFind << " � �������." << endl;

    while (left <= right && !found) {
        int mid = left + (right - left) / 2; // ������� �������
        cout << "������� �������: left = " << left << ", right = " << right << ", mid = " << mid << " (��������: " << MyArray[mid] << ")" << endl;

        if (MyArray[mid] == WhatFind) {
            found = true;
            index = mid;
            cout << "������� " << WhatFind << " ������ �� ������� " << index << "." << endl;
        } else if (MyArray[mid] < WhatFind) {
            left = mid + 1;     // ���� � ������ ��������
            cout << "������� ������� ������, ���� � ������ ��������." << endl;
        } else {
            right = mid - 1;    // ���� � ����� ��������
            cout << "������� ������� ������, ���� � ����� ��������." << endl;
        }
    }

    if (found) {
        cout << WhatFind << " ������ �� ������� " << index << endl;
    } else {
        cout << "��������. ������� �� ������." << endl;
    }

    return 0;
}
