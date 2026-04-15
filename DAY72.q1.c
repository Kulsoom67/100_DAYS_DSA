QUES1: Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
  #include <stdio.h>

char firstRepeatedChar(const char *s) {
    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (seen[index]) {
            return s[i];
        }
        seen[index] = 1;
    }

    return '\0';
}

int main() {
    char s[1000];
    scanf("%s", s);

    char result = firstRepeatedChar(s);

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("No repeated character\n");
    }

    return 0;
}
