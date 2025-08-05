#include <stdio.h>
#include <stdbool.h>
 
int main () {
    int n;
    scanf("%d", &n);
    int surecount = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            int p;
            scanf("%d", &p);
            sum += p;
        }
        if (sum >= 2) {
            surecount += 1;
        }
    }
    printf("%d", surecount);
}