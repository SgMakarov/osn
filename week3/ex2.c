#include <stdio.h>

void bubble_sort(int *arr, int n);

int main() {
    int a[6];
    for (int i = 0; i < 6; ++i) {
        a[i] = 6 - i;
    }
    bubble_sort(a, 6);
    for (int j = 0; j < 6; ++j) {
        printf("%d ", a[j]);
    }

}


void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (arr[j] < arr[j - 1]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}