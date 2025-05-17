#include <iostream>
#include <algorithm>
using namespace std;
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int P(int a[], int start, int end)
{
    int p = a[end];
    int I = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= p)
        {
            swap(a[i], a[I]);
            I++;
            cout << "After swap: ";
            printArray(a, end + 1);
        }
    }
    swap(a[I], a[end]);
    cout << "After placing pivot: ";
    printArray(a, end + 1);
    return I;
}
void q(int a[], int start, int end)
{
    if (start < end)
    {
        int p = P(a, start, end);
        q(a, start, p - 1);
        q(a, p + 1, end);
    }
}
int main()
{
    int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    q(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
