#include <stdio.h>
#include <string.h>

void bit(int * p) {
    char c[3];
    scanf("%s", &c);
        if (strcmp(c,"X++") == 0) {
            (*p)++;
        }
        if (strcmp(c,"++X") == 0) {
            ++(*p);
        }
        if (strcmp(c, "X--") == 0) {
            (*p)--;
        }
        if (strcmp(c,"--X") == 0) {
            --(*p);
        }
}

int main () {
    int n, x = 0;
    scanf("%d", &n);
    int * p = &x;
    while (n--) {
    bit(p);
    }
    printf("%d", x);
    return 0;
}