#include <iostream>
#include <algorithm>
#include <clocale>
using namespace std;

const int ROWS = 4; // ���������� �����
const int COLS = 5; // ���������� ��������

// ������� ��� ��������, ����������� �� ������ �� �����������
bool isAscending(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// ������� ��� ��������, ����������� �� ������ �� ��������
bool isDescending(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// ������� ��� ���������� ������ �� �����������
void sortAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                // ������ �������� �������
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[ROWS][COLS] = {
        {1, 2, 6, 4, 5},    // ����������� �� �����������
        {9, 7, 5, 3, 1},    // ����������� �� ��������
        {4, 2, 8, 6, 10},   // �� �����������
        {10, 8, 6, 4, 2}    // ����������� �� ��������
    };

    // ����� ��������� �������
    cout << "�������� ������:" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // �������� � ���������� �����
    for (int i = 0; i < ROWS; ++i)
    {
        if (!isDescending(arr[i], COLS))
        {
            cout << "������ " << i + 1 << " ��������." << endl;
            sortAscending(arr[i], COLS);
        }
    }

    // ����� ����������� �������
    cout << "\n������ ����� ����������:" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
