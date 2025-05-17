#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

const int M = 100; // ������������ ������ �������

void transposeMatrix(int mat[M][M], int transposed[M][M], int str, int cols) //������� ����������������� �������, ����������� ������ � ������� �������� �������
{
    for (int i = 0; i < str; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            transposed[j][i] = mat[i][j];
        }
    }
}
void printMatrix(int mat[M][M], int str, int cols)
{
    for (int i = 0; i < str; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int mat[M][M], transposed[M][M];
    int str, cols;

    // ���� �������� �������
    cout << "������� ���������� ����� � �������� �������: ";
    cin >> str >> cols;

    // ���� ��������� �������
    for (int i = 0; i < str; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            mat[i][j] = rand() % 100;
        }
    }

    // ���������������� �������
    transposeMatrix(mat, transposed, str, cols);

    // ����� �������� �������
    cout << "�������� �������:" << endl;
    printMatrix(mat, str, cols);

    // ����� ����������������� �������
    cout << "����������������� �������:" << endl;
    printMatrix(transposed, cols, str);

    return 0;
}
