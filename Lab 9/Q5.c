#include <stdio.h>
#include <string.h>



int main() {
    int NUM_CITIES=5;
    int MAX_LENGTH=50;
    char cities[NUM_CITIES][MAX_LENGTH];
    int i;
    int longest_idx = 0;
    int max_len = 0;


    printf("Enter 5 city names:\n");
    for (i = 0; i < NUM_CITIES; i++) {
        printf("City %d: ", i + 1);
        fgets(cities[i], sizeof(cities[i]), stdin);
        
        cities[i][strcspn(cities[i], "\n")] = '\0';
    }


    for (i = 0; i < NUM_CITIES; i++) {
        int current_len = strlen(cities[i]);
        if (current_len > max_len) {
            max_len = current_len;
            longest_idx = i;
        }
    }

    printf("\n--- City List ---\n");
    for (i = 0; i < NUM_CITIES; i++) {
        printf("%d. %s\n", i + 1, cities[i]);
    }

    printf("\nLongest city name: %s\n", cities[longest_idx]);
    printf("Length: %zu\n", max_len);

    return 0;
}