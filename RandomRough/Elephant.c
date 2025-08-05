#include <stdio.h>

int steps(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return steps(n - 1) + steps(n - 2) + steps(n - 3) + steps(n - 4) + steps(n - 5);
}

int main() {
    int n, output;
    scanf("%d", &n);
    output = steps(n);
    printf("%d", output);
}