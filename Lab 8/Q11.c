#include <stdio.h>

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int isEven(int x) {
    if (x % 2 == 0) return 1;
    return 0;
}

int isPositive(int x) {
    if (x > 0) return 1;
    return 0;
}

void applyToArray(int *arr, int n, int (*fn)(int)) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = fn(arr[i]);
    }
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (pred(arr[i])) {
            count++;
        }
    }
    return count;
}

void printGeneric(void *data, char type, int n) {
    int i;
    if (type == 'i') {
        int *arr = (int *)data;
        for (i = 0; i < n; i++) {
            printf("%d", arr[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    } else if (type == 'f') {
        float *arr = (float *)data;
        for (i = 0; i < n; i++) {
            printf("%.2f", arr[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    } else if (type == 'c') {
        char *arr = (char *)data;
        for (i = 0; i < n; i++) {
            printf("%c", arr[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    } else {
        printf("Invalid type '%c' for printGeneric\n", type);
    }
}

int main() {
    int n, i;
    int arr[] = {3, -2, 8, -5, 6};
    float farr[] = {1.50, 2.25};

    while (1) {
        printf("Enter n (1-50): ");
        if (scanf("%d", &n) != 1) return 0;
        if (n >= 1 && n <= 50) break;
    }

    printf("Original: ");
    for (i = 0; i < 5; i++) {
        printf("%d", arr[i]);
        if (i < 4) printf(" ");
    }
    printf("\n");

    applyToArray(arr, 5, negate);
    printf("After negate: ");
    for (i = 0; i < 5; i++) {
        printf("%d", arr[i]);
        if (i < 4) printf(" ");
    }
    printf("\n");

    int posCount = countIf(arr, 5, isPositive);
    printf("Positive values after negate: %d\n", posCount);

    int evenCount = countIf(arr, 5, isEven);
    printf("Even values after negate: %d\n", evenCount);

    printf("Float print (type f): ");
    printGeneric(farr, 'f', 2);

    printGeneric(arr, 'x', 5);

    return 0;
}