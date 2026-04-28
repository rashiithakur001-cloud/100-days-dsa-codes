/*Given a string s consisting of lowercase letters, 
find the first repeated character in the string. 
A character is considered repeated if it appears more than once, and among all such characters, 
the one whose second occurrence has the smallest index should be returned.*/
#include <stdio.h>

char firstRepeatedChar(char *s) {
    int seen[26] = {0};  // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index] == 1) {
            return s[i];  // first repeated character
        }

        seen[index] = 1;
    }

    return '\0';  // no repeated character
}

int main() {
    char s[] = "abccba";

    char result = firstRepeatedChar(s);

    if (result != '\0') {
        printf("First repeated character: %c\n", result);
    } else {
        printf("No repeated character found\n");
    }

    return 0;
}