#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main () {
    char str[1000];
    int dc = 0;
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {

        if (str[i] == '_') continue; 

        else {
        bool found = false;
        for(int j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j]) found = true;
        }
        if (!found) dc++; else str[i] = '_';
        }

    }
    if (dc % 2 == 0) {
        printf("CHAT WITH HER!");
    } else {
        printf("IGNORE HIM!");
    }


}