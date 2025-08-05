#include <stdio.h>

int main () {
    int x, y;
    scanf("%d %d", &x, &y);
    int k = y; 
    int count = 0;
    while (k != 0) {
        if (k >= x * 10) {k -= x * 10; count++;}
        else if (k >= x) {k -= x; count++;}
        else {k -= 1; count++;}
    }
    printf("%d", count);
}