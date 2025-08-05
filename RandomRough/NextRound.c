#include <stdio.h>

int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int qualify = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= arr[k-1] && arr[i] > 0) {
            qualify ++;
        }
    }
    printf("%d", qualify);
    return 0;
}