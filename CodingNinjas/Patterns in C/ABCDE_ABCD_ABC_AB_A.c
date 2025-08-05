#include <stdio.h>

int main() {
   
   int n = 5, i, j;
   char c = 'A';
   i = 0;
   while (i < n) {
      j = 0;
      while (j < n - i) {printf("%c", c + j); j += 1;} 
   printf("\n"); i += 1;}
   return 0;
}

Output:

ABCDE
ABCD
ABC
AB
A