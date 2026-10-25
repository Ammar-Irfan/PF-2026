#include <stdio.h>

int add(int a, int b, int *result) {
    *result = a + b;
    return 1;
}

int subtract(int a, int b, int *result) {
    *result = a - b;
    return 1;
}

int multiply(int a, int b, int *result) {
    *result = a * b;
    return 1;
}

int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;
    }
    *result = a / b;
    return 1;
}

int main() {
    int (*ops[])(int, int, int*) = {add, subtract, multiply, divide};
    int choice, a, b, result, success;

    while (1) {
        printf("Choice (1-5): ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 5) {
            printf("Goodbye.\n");
            break;
        }
        if (choice < 1 || choice > 5) {
            printf("Invalid choice\n");
            continue;
        }
        printf("Enter a and b: ");
        scanf("%d %d", &a, &b);

        success = ops[choice - 1](a, b, &result);
        if (!success) {
            printf("Error: division by zero\n");
        } else {
            if (choice == 1) printf("Add result: %d\n", result);
            else if (choice == 2) printf("Subtract result: %d\n", result);
            else if (choice == 3) printf("Multiply result: %d\n", result);
            else if (choice == 4) printf("Divide result: %d\n", result);
        }
    }
    return 0;
}