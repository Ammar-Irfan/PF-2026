#include <stdio.h>
#include <string.h>


int main() {
    
int MAX_NAMES=5;
int MAX_LEN=50;
    
    char names[MAX_NAMES][MAX_LEN];
    char temp[MAX_LEN];
    int i, j;

    printf("Enter %d student names (without spaces):\n", MAX_NAMES);
    for (i = 0; i < MAX_NAMES; i++) {
        scanf("%s", names[i]);
    }

    
    for (i = 0; i < MAX_NAMES - 1; i++) {
        for (j = 0; j < MAX_NAMES - i - 1; j++) {
            
            if (strcmp(names[j], names[j + 1]) > 0) {

                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted list of student names:\n");
    for (i = 0; i < MAX_NAMES; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}