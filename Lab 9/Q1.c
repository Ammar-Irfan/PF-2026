#include <stdio.h>
#include <string.h>

int main() {
    char name[100],name_cpy[100];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
        len--;
    }
    printf("Length of the name: %zu \n", len);
    strcpy(name_cpy, name);
    printf("Copied name: %s\n", name_cpy);
    printf("Size of the array (sizeof): %zu bytes \n", sizeof(name));
 
    return 0;
}