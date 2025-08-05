#include <stdio.h>

int main() {
   int n = 5, i, j, k;
   i = 1;
   while (i <= n) {
   for (j = i - 1; j >= 0; j -= 1) {printf("%d", n-j);} 
   for (k = n - i; k >= 1; k -= 1) {printf("%d", n);}
   printf("\n"); 
   i += 1;
   }

   return 0;
}

					OR;

int main() {
   int n = 5, i, j, k;
   i = n;
   while (i >= 1) { k = i;
   for (j = 1; j <= n; j += 1) {if (k <= n) {printf("%d", k);} else {printf("%d", n);} k += 1;} 
   printf("\n"); 
   i -= 1;
   }
   return 0;
}

// Output;
// 55555
// 45555
// 34555
// 23455
// 12345