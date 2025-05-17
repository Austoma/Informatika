#include <iostream>
#include <clocale>
#include <stdlib.h>

using namespace std;
const int I = 10; // ������������ ���������� �����
const int J = 10; // ������������ ���������� ��������

// ������� ��� ������ �������
void printArray(int arr[I][J], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int arr[I][J]; // �������� ������
    int rows, cols;
    cout << "������� ���������� ����� � �������� �������: ";
    cin >> rows >> cols;
    cout << "\n�������� ������:" << endl;
    // ���� ��������� �������
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20;
            cout << arr[i][j] << "\t"; // ����� ��������� �������
        }
        cout <<endl;
    }
    // ���������� ������
    int newRowIndex;
    cout << "\n������� ����� ������ ��� ����������: ";
    cin >> newRowIndex;
    newRowIndex -=1;

    if (newRowIndex < 0 || newRowIndex > rows)
    {
        cout << "������������ ����� ������!" << endl;
        return 1;
    }
    // �������� ������ ����, ������� � newRowIndex
    for (int i = rows; i > newRowIndex; --i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = arr[i - 1][j];
        }
    }
    // ���� ����� ������
    cout << "������� �������� ����� ������:" << endl;
    for (int j = 0; j < cols; ++j)
    {
        cin >> arr[newRowIndex][j];
    }
    rows++; // ����������� ���������� �����
    // ����� ������� ����� ���������� ������
    cout << "\n������ ����� ���������� ������:" << endl;
    printArray(arr, rows, cols);
    // ���������� �������
    int newColIndex;
    cout << "\n������� ����� ������� ��� ����������: ";
    cin >> newColIndex;
    newColIndex-=1;

    if (newColIndex < 0 || newColIndex > cols)
    {
        cout << "������������ ����� �������!" << endl;
        return 1;
    }

    // �������� ������� ������, ������� � newColIndex
    for (int j = cols; j > newColIndex; --j)
    {
        for (int i = 0; i < rows; ++i)
        {
            arr[i][j] = arr[i][j - 1];
        }
    }

    // ���� ������ �������
    cout << "������� �������� ������ �������:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        cin >> arr[i][newColIndex];
    }
    cols++; // ����������� ���������� ��������

    // ����� ������� ����� ���������� �������
    cout << "\n������ ����� ���������� �������:" << endl;
    printArray(arr, rows, cols);

    return 0;
}
