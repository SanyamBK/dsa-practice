#include <stdio.h>
#include <math.h>

#define sign(n) (n % 2 == 0 ? 1 : -1)

long long function(long long n) {
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        sum += i * sign(i);
    }
    return sum;
}

int main () {
    long long n ; 
    scanf("%lld", &n);
    printf("%lld", function(n));
}