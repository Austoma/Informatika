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

void bottomUpMergeSort(int* a, int n) {
    int width, i;
    int pass = 1;

    for (width = 1; width < n; width *= 2) {
        printf("\n--- Pass %d (width = %d) ---\n", pass++, width);
        printArray(a, n, "Before merging");

        for (i = 0; i < n; i += 2 * width) {
            int left = i;
            int mid = (i + width) < n ? (i + width) : n;
            int right = (i + 2 * width) < n ? (i + 2 * width) : n;

            if (mid < right) {  // Если есть что сливать
                printf("Merging [%d-%d] and [%d-%d]\n", left, mid-1, mid, right-1);
                merge(a, left, mid, right);
                printArray(a, n, "After merge ");
            }
        }
    }
}

int main() {
    int a[8];
    for (int i = 0; i < 8; i++)
        a[i] = rand() % 20 - 10;

    printArray(a, 8, "Initial array");
    printf("-----------------\n");

    bottomUpMergeSort(a, 8);

    printArray(a, 8, "\nFinal sorted array");

    getchar();
    return 0;
}
