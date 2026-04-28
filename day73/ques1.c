/*Given a string s consisting of lowercase English letters, 
find and return the first character that does not repeat in the string.
 If all characters repeat, return '$'.*/
 #include <stdio.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    // Step 1: Count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';  // if all characters repeat
}

int main() {
    char s[] = "aabbcde";

    char result = firstNonRepeating(s);

    if (result != '$') {
        printf("First non-repeating character: %c\n", result);
    } else {
        printf("All characters repeat\n");
    }

    return 0;
}