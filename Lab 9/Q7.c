#include <stdio.h>


int main() {
    int MAX_NAMES=3;
    int  MAX_LEN=5;

    char name[MAX_LEN];
    FILE *file;
    int i;
    int count = 0;

    
    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    
    printf("Enter %d student names:\n", MAX_NAMES);
    for (i = 0; i < MAX_NAMES; i++) {
        scanf("%s", name);
        fprintf(file, "%s\n", name);
    }

    
    fclose(file);

    
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nNames read from students.txt:\n");
    

    while (fscanf(file, "%s", name) == 1) {
        count++;
        printf("%d. %s\n", count, name);
    }

    fclose(file);

    
    printf("Total students in file: %d\n", count);

    return 0;
}