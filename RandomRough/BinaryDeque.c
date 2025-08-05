#include <stdio.h>
#include <stdbool.h>

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
    int n, s, arr[200000];
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bool flag = false; int sum;
    int i = 0, count1 = 0;
    while (i < n) {
        sum = 0;
    for (int k = i; k < n; k++) {
        sum += arr[k]; 
    }
    if (sum == s) {
        flag = true;
        break;
        }
    else {
        i ++; count1 ++;
    }
    }

    int j = n - 1, count2 = 0;
    while (j >= 0) {
        sum = 0;
    for (int k = j; k >= 0; k--) {
        sum += arr[k]; 
    }
    if (sum == s) {
        flag = true;
        break;
        }
    else {
        j --; count2 ++;
    }
    }

    if (flag && count1 < count2) {printf("%d\n", count1);}
    if (flag && count2 < count1) {printf("%d\n", count2);}
    else {int c = -1; printf("%d\n", c);}
  }

    return 0;
    
}

