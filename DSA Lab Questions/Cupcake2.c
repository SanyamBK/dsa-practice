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


int count_subarray(int input[], int n, int l, int r, int k) {
    int count = 0;         
        for (int i = l; i <= r - k + 1; i++) {
            for (int j = i + k - 1; j <= r && input[j] - input[i] + 1 <= k; j++) {
                if (input[j] - input[i] + 1 == k)
                    count++;
            }
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
    int distinct_Set[n];
    int c = 1;
        for (int i = 0; i < n; i++) {
            distinct_Set[i] = c;
            if (array[i] == array[i - 1])
                c--;
            c++;
        }

    while (q--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int ans = count_subarray(distinct_Set, n, l, r, k);
        printf("%d\n", ans);
    }
    return 0;
}