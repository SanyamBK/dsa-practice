#include <stdio.h>
#include <stdlib.h>

int compare(const void *s1, const void *s2) {
    char **p1 = (char **) s1;
    char **p2 = (char **) s2;
    char *str1 = *p1;
    char *str2 = *p2;

    while (*str1 || *str2) {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }

    return 0;
}
