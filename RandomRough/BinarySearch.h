#include <stdio.h>
#include <stdbool.h>

int binarySearch(int *input, int n, int val)
{
   int index = -1;
   bool found = false;
   int start = 0, end = n - 1;
   while (!found && start <= end) {
     int mid = (start + end) / 2;
     if (input[mid] == val) {
       index = mid; 
       found = true;
       break;}
       else {
       if (val > input[mid]) {
         start = mid + 1;
       }
        else {
         end = mid - 1;}
            }
       }
 
    return index;
}

int bs(int input[], int si, int ei, int ele) {
  if (si >= ei) return -1;
  int mid = (si+ei)/2;
  if (input[mid] == ele) return mid;
  else if (ele < input[mid]) return bs(input, si, mid-1, ele);
  else return bs(input, mid+1, ei, ele);
}


int binarySearch(int input[], int size, int element) {
  return bs(input, 0, size-1, element);
}

int main() {
    int input[100000] = {2, 3, 4, 5, 7, 8},length = 5,element = 5, ans;
    // scanf("%d", &length);
    // for(int i =0;i<length;i++)
    // { 
    //     scanf("%d", &input[i]);
    // }

    // scanf("%d", &element);
    ans = binarySearch(input, length, element);
    printf("%d", ans);
}