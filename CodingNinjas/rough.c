#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

void lexicographic_sort(char **arr, int n) {
    qsort(arr, n, sizeof(char *), compare);
}

bool isSubstring(char *s, char *l) {
    if (s[0] == '\0')
        return true;

    if (strlen(s) > strlen(l)) 
        return false;
    
    if (s[0] != l[0])
        return false;

    if (isSubstring(s+1, l+1))
        return true;

}

int main() {
    char *arr[] = {"ab", "aabb", "aa", "banana", "zebra"};
    int n = sizeof(arr) / sizeof(char*);

    lexicographic_sort(arr, n);

    printf("%d", isSubstring("aa", "aa"));

    return 0;
}
