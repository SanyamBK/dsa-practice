#include <stdio.h>

void uppercase (char input[]) {
    if (input[0] == '\0') return;
    if (input[0] > 90) {
        input[0] -= 32;
    }
    uppercase(input+1);
}

void lowercase (char input[]) {
    if (input[0] == '\0') return;
    if (input[0] < 97) {
        input[0] += 32;
    }
    lowercase(input+1);
}

int main () {
    char str[1000];
    scanf("%s", str);
    int upper = 0, lower = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97) lower++;
        else upper++;
    }
    if (lower >= upper) lowercase(str);
    else uppercase(str);
    printf("%s", str);
}