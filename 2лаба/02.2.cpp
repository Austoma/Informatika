//������� ����� ����� �� 1 �� 9, ���� ��� �� ������ ������ 20
#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int result;
    for(int i = 1; i < 10; i++)
    {
        result += i;
        cout << result << endl;
        if(result > 20) break;
    }
    return 0;
}
