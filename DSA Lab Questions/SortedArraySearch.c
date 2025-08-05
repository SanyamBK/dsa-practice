#include <stdio.h>
#include <stdlib.h>


int binarySearch(int *input, int n, int val)
{
   int index = -1;
   int start = 0, end = n - 1;
   while (start <= end) {
     int mid = (start + end) / 2;
     if (input[mid] == val) {
        if (input[mid-1] >= 0) {
            while (input[mid-1] == input[mid]) {
            mid --; 
            if (mid == 0)
                break;
            }
        }
        return mid;
    }
       else {
       if (val > input[mid]) {
         start = mid + 1;
       }
        else {
         end = mid - 1;}
            }
       }
 
    return start;
}


int main () {
    int n, q;
    scanf("%d %d", &n, &q);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int queries[q];
    for (int i = 0; i < n; i++) {
        scanf("%d", &queries[i]);
    }
    for (int i = 0; i < q; i++) {
        int search = queries[i];
        printf("%d", binarySearch(array, n, search));
    }
}
