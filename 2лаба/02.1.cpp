//������ �� ����� ��������� �������� ����� ����� �� 1 �� �������, ������� ������ ������������
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;  // ���������� ���������� �����
    cout << "������� ������: ";
    cin >> n;  // ������ �����
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << ": " << i * i << endl;
    }
    return 0;
}
