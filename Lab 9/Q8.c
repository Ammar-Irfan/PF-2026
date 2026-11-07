#include <stdio.h>


int isSubsequence(char *s, char *t) {
    int i = 0, j = 0;
    
    
    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    
    
    return s[i] == '\0';
}

int main() {
    
    char s1[] = "abc";
    char t1[] = "ahbgdc";
    
    char s2[] = "axc";
    char t2[] = "ahbgdc";


    if (isSubsequence(s1, t1)) {
        printf("s = \"%s\", t = \"%s\" -> true\n", s1, t1);
    } else {
        printf("s = \"%s\", t = \"%s\" -> false\n", s1, t1);
    }

    
    if (isSubsequence(s2, t2)) {
        printf("s = \"%s\", t = \"%s\" -> true\n", s2, t2);
    } else {
        printf("s = \"%s\", t = \"%s\" -> false\n", s2, t2);
    }

    return 0;
}