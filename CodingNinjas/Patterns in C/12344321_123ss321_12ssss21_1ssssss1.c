#include <stdio.h>

int main() {
   
   int n = 4, i, j, k;
   //char c = 'A';
   i = 0;
   while (i < n) {
      j = 1; k = 1;
      while (j <= n) {if (j <= n - i) {printf("%d", j);} else {printf("*");}j += 1; }
      while (k <= n) {if (k <= i) {printf("*");} else {printf("%d", n-k+1);} k+=1;}
   printf("\n"); i += 1;}
   return 0;
}

12344321
123**321
12****21
1******1