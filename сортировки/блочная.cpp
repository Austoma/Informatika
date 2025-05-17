#include <iostream>
#include <cstdlib>
using namespace std;

struct bucket
{
    int count;
    int* value;
};

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y = *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void bucketSort(int array[], int n)
{
    struct bucket buckets[3];
    int i, j, k;

    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
        if (buckets[i].value == nullptr) {
            cerr << "Ошибка выделения памяти\n";
            return;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    cout << "\nAfter distributing into buckets:\n";
    for (i = 0; i < 3; i++)
    {
        cout << "Bucket " << i << ": ";
        printArray(buckets[i].value, buckets[i].count);
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        cout << "\nAfter sorting bucket " << i << ":\n";
        printArray(buckets[i].value, buckets[i].count);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        cout << "After merging bucket " << i << " into array:\n";
        printArray(array, n);
        free(buckets[i].value);
    }
}

int main()
{
    int array[100] = { 5, -34, 10, 1, -42, 123, 2, 395, 5, 4, 1234, 7 };
    int i = 12, j, k, n;
    n = i;

    cout << "Before Sorting\n";
    for (j = 0; j < i; j++)
    {
        cout << array[j] << " ";
    }

    bucketSort(array, n);

    cout << "\nAfter Sorting\n";
    for (k = 0; k < i; k++)
    {
        cout << array[k] << " ";
    }

    return 0;
}
