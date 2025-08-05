#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int count_subarray(int input[], int left, int right, int target) {
    if (right - left + 1 < target || target == 0) 
        return 0;

        int ptr1 = left - 1, ptr2 = left;
        int count = 0, distinct = 1;
        while (ptr2 < right) {
            if (distinct > target) {
                while (input[ptr1] == input[ptr1+1]) ptr1++;
                ptr1++;
                distinct--;
            }
            count += ptr2 - ptr1 + 1;
            if (input[ptr2] != input[ptr2-1]) 
                distinct++;        
            ptr2++;
        }

    return count;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    insertionSort(array, n);
    while (q--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int ans = count_subarray(array, l, r, k) - count_subarray(array, l - 1, n - r, k );
        printf("%d\n", ans);
    }
    return 0;
}
