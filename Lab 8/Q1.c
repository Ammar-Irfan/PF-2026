#include <stdio.h>

void bubbleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void printArray(const int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", *(arr + i));
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n, i;
    int scores[20];
    while (1) {
        printf("Enter number of scores: ");
        if (scanf("%d", &n) != 1) return 0;
        if (n >= 1 && n <= 20) {
            break;
        }
        printf("Invalid size\n");
    }
    printf("Enter scores: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }
    printf("Before sorting: ");
    printArray(scores, n);
    bubbleSort(scores, n);
    printf("After sorting: ");
    printArray(scores, n);
    return 0;
}