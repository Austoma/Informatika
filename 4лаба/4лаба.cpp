#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

// ������� ��� ������ �������
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    // 1. ������������ ���������� ������ ����� �����
    int size;
    cout << "������� ������ �������: ";
    cin >> size;

    int* arr = new int[size]; // �������� ������ ��� �������
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100; // ��������� ����� �� 1 �� 100
        cout << arr[i] << " ";  // 2. ����������� �������� ������
    }
    cout << endl;
    // 3. ������� 5 ��������� ��������� �������
    if (size >= 5)
    {
        size -= 5; // ��������� ������ ������� �� 5
    }
    else
    {
        cout << "������ ������� ��� ��� �������� 5 ���������." << endl;
        delete[] arr; // ����������� ������
        return 1;
    }
    cout << "������ ����� �������� 5 ���������: ";
    printArray(arr, size);

    // 4. �������� � ������ ������� 3 �������� � ��������� M[I+1] + 2
    // ������� ����� ������ � ����������� ��������
    int newSize = size + 3;
    int* newArr = new int[newSize];
    // ��������� ����� �������� � ������
    for (int i = 0; i < 3; ++i)
    {
        newArr[i] = arr[i + 1] + 2;
    }
    // �������� ���������� �������� �� ������� �������
    for (int i = 0; i < size; ++i)
    {
        newArr[i + 3] = arr[i];
    }
    delete[] arr; // ����������� ������ ������� �������
    cout << "������ ����� �������� � ���������� ���������: ";
    printArray(newArr, newSize); // 5. ����������� ���������� ������
    return 0;
}
