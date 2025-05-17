#include <iostream>
#include <clocale>
using namespace std;

const int n = 8; // ������ ��������� �����
int board[n][n]; // �����

// ������� ��� ������ �����
void printBoard()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == -1)
                cout << " Q "; // �����
            else
                cout << " . "; // ������ ������
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}

// ������� ��� ������ ����� � ������� (i, j)
void resetQ(int i, int j)
{
    for (int x = 0; x < n; ++x)
    {
        --board[x][j]; // ��������� �������� �� �������
        --board[i][x]; // ��������� �������� �� ������
        int k;
        k = j - i + x; // ��������� 1
        if (k >= 0 && k < n)
            --board[x][k];
        k = j + i - x; // ��������� 2
        if (k >= 0 && k < n)
            --board[x][k];
    }
    board[i][j] = 0; // ���������� �����
}

// ������� ��� ��������� ����� �� ������� (i, j)
void setQ(int i, int j)
{
    for (int x = 0; x < n; ++x)
    {
        ++board[x][j]; // ����������� �������� �� �������
        ++board[i][x]; // ����������� �������� �� ������
        int k;
        k = j - i + x; // ��������� 1
        if (k >= 0 && k < n)
            ++board[x][k];
        k = j + i - x; // ��������� 2
        if (k >= 0 && k < n)
            ++board[x][k];
    }
    board[i][j] = -1; // ������������� �����
}

// ����������� ������� ��� ���������� ������
bool tryQ(int i)
{
    bool result = false;
    for (int j = 0; j < n; ++j)
    {
        if (board[i][j] == 0)
        { // ���� ������ ��������
            setQ(i, j); // ������������� �����
            cout << "����� �������� �� (" << i << ", " << j << "):" << endl;
            printBoard(); // ������� ������� ��������� �����

            if (i == n - 1)
            { // ���� ��� ����� ���������
                result = true;
            }
            else
            {
                result = tryQ(i + 1); // ���������� ��������� ��������� �����
                if (!result)
                {
                    resetQ(i, j); // ���� ������� �� �������, ���������� �����
                    cout << "�����: ����� ���� � (" << i << ", " << j << "):" << endl;
                    printBoard(); // ������� ��������� ����� ����� ������
                }
            }
        }
        if (result) break; // ���� ������� �������, ������� �� �����
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");
    // ������������� �����
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            board[i][j] = 0;

    // ������ �������
    tryQ(0);

    // ����� ���������� �������
    cout << "��������� �������:" << endl;
    printBoard();

    return 0;
}
