#include <stdio.h>
#include <stdlib.h>

void printArray(int* a, int n, const char* message) {
    printf("%s: ", message);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int* a, int left, int mid, int right) {
    int i = left, j = mid, k = 0;
    int* temp = (int*)malloc((right - left) * sizeof(int));

    while (i < mid && j < right) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i < mid) {
        temp[k++] = a[i++];
    }

    while (j < right) {
        temp[k++] = a[j++];
    }

    for (i = left, k = 0; i < right; i++, k++) {
        a[i] = temp[k];
    }

    free(temp);
}

void naturalMergeSort(int* a, int n) {
    if (n <= 1) return;

    int left, mid, right;
    int sorted = 0;
    int pass = 1;

    while (!sorted) {
        sorted = 1;
        left = 0;

        printArray(a, n, "Before pass");

        while (left < n) {
            mid = left + 1;
            while (mid < n && a[mid - 1] <= a[mid]) {
                mid++;
            }

            if (mid < n) {
                right = mid + 1;
                while (right < n && a[right - 1] <= a[right]) {
                    right++;
                }

                printf("Merging segments [%d-%d] and [%d-%d]\n", left, mid-1, mid, right-1);
                merge(a, left, mid, right);
                printArray(a, n, "After merge");
                sorted = 0;

                left = right;
            } else {
                left = mid;
            }
        }

        printf("After pass %d: ", pass++);
        printArray(a, n, "");
        printf("-----------------\n");
    }
}

int main() {
    int a[8];
    for (int i = 0; i < 8; i++)
        a[i] = rand() % 20 - 10;

    printArray(a, 8, "Initial array");
    printf("-----------------\n");

    naturalMergeSort(a, 8);

    printArray(a, 8, "Final sorted array");

    getchar();
    return 0;
}
