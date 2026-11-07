#include <stdio.h>
#include <string.h>

int main() {
    char sentence[256];
    char *p = NULL;
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    
    sentence[strcspn(sentence, "\n")] = '\0';
    
    
    p = strchr(sentence, 'a');
    if (p != NULL) {
        
        printf("First 'a' found at index %ld\n", p - sentence);
    } else {
        printf("Letter 'a' not found in the sentence.\n");
    }
    
    if (strstr(sentence, "good") != NULL) {
        printf("Word 'good' found.\n");
    } else {
        printf("Word 'good' not found.\n");
    }
    
    return 0;
}