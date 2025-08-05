#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertCase(char string[]) {
    int i = 0;
    while (string[i]) {
        string[i] = tolower(string[i]);
        i++;
    }
}

int main() {
    char str1[1000], str2[1000];
    scanf("%s\n%s", str1, str2);
    convertCase(str1);
    convertCase(str2);
    int ans = strcmp(str1, str2);
    printf("%d", ans);


    return 0;
}