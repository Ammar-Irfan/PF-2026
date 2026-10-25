#include <stdio.h>

int deposit(float *balance, float amount) {
    if (amount <= 0) {
        return 0;
    }
    *balance += amount;
    return 1;
}

int withdraw(float *balance, float amount) {
    if (amount <= 0 || amount > *balance) {
        return 0;
    }
    *balance -= amount;
    return 1;
}

int main() {
    float balance = 1000.0;
    int choice;
    float amount;

    while (1) {
        printf("Choose option (1-4): ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (deposit(&balance, amount)) {
                printf("Amount deposited successfully.\n");
            } else {
                printf("Insufficient funds or invalid amount.\n");
            }
        } else if (choice == 2) {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (withdraw(&balance, amount)) {
                printf("Amount withdrawn successfully.\n");
            } else {
                printf("Insufficient funds or invalid amount.\n");
            }
        } else if (choice == 3) {
            printf("Current balance: %.2f\n", balance);
        } else if (choice == 4) {
            printf("Goodbye.\n");
            break;
        } else {
            printf("Invalid option\n");
        }
    }
    return 0;
}