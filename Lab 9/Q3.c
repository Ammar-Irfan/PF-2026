#include <stdio.h>
#include <string.h>

int main() {
    char correct_password[] = "passcheck"; 
	char user_password[50];

    printf("Enter password: ");
    fgets(user_password, sizeof(user_password), stdin);

    int len = strlen(user_password);
    if (len > 0 && user_password[len - 1] == '\n') {
        user_password[len - 1] = '\0';
    }

    if (strcmp(user_password, correct_password) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    if (strncmp(user_password, correct_password, 3) == 0) {
        printf("First 3 characters match.\n");
    } 
	else {
        printf("First 3 characters do not match.\n");
    }

    return 0;
}