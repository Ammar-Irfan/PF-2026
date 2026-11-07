#include <stdio.h>
#include <string.h>

int main() {
    char first_name[50];
    char last_name[50];
    char full_name[100]; 

    printf("Enter first name: ");
    fgets(first_name, sizeof(first_name), stdin);
    
    int  len1 = strlen(first_name);
    if (len1 > 0 && first_name[len1 - 1] == '\n') {
        first_name[len1 - 1] = '\0';
    }
	printf("Enter last name: ");
    fgets(last_name, sizeof(last_name), stdin);
    
    int len2 = strlen(last_name);
    if (len2 > 0 && last_name[len2 - 1] == '\n') {
        last_name[len2 - 1] = '\0';
    }
    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    printf("Full name: %s\n", full_name);

    return 0;
}