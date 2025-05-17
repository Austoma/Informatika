#include <stdio.h>
#include <stdlib.h>

void print_array(int* a, int n, const char* message) {
    printf("%s: ", message);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int* a, int n) {
    int* c = (int*)malloc(n * sizeof(int));
    int h = 1;

    while (h < n) {
        printf("\n--- Pass with h = %d ---\n", h);
        int i = 0;
        while (i < n) {
            int left_start = i;
            int left_end = (i + h < n) ? i + h : n;
            int right_start = left_end;
            int right_end = (i + 2*h < n) ? i + 2*h : n;

            int k = left_start;
            int l = left_start;
            int r = right_start;

            printf("Merging subarrays: [%d..%d] and [%d..%d]\n",
                   left_start, left_end-1, right_start, right_end-1);

            while (l < left_end && r < right_end) {
                if (a[l] <= a[r]) {
                    c[k++] = a[l++];
                } else {
                    c[k++] = a[r++];
                }
            }
            while (l < left_end) {
                c[k++] = a[l++];
            }
            while (r < right_end) {
                c[k++] = a[r++];
            }

            // Copy merged part back to original array
            for (int m = left_start; m < right_end; m++) {
                a[m] = c[m];
            }

            print_array(a, n, "After merge ");

            i += 2 * h;
        }
        h *= 2;
    }
    free(c);
}

int main() {
    int a[8];
    for (int i = 0; i < 8; i++)
        a[i] = rand() % 20 - 10;

    print_array(a, 8, "Initial array");
    merge(a, 8);
    print_array(a, 8, "Sorted array ");

    return 0;
}
