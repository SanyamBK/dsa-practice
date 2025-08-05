#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void merge(ll input[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    ll temp[end - start + 1];
    while (i <= mid && j <= end) {
        if (input[i] < input[j]) {
            temp[k - start] = input[i];
            i++;
        } else {
            temp[k - start] = input[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        while (j <= end) {
            temp[k - start] = input[j];
            k++; j++;
        }
    } else {
        while (i <= mid) {
            temp[k - start] = input[i];
            k++;
            i++;
        }
    }
    for (k = start; k <= end; k++) {
        input[k] = temp[k - start];
    }
}
 
void mergeSort(ll input[], int start, int end) {
    if (start >= end) 
        return ;
    int mid = (start + end)/2;
    mergeSort(input, start, mid);
    mergeSort(input, mid+1, end);
    merge(input, start, mid, end);
 
}
 
void mergesort(ll input[], int size) {
    mergeSort(input, 0, size-1);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    ll hostility[n], humour[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &hostility[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &humour[i]);
    }

    int queries[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i]);
    }


    ll sums[n * n];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sums[idx++] = hostility[i] + humour[j];
            mergesort(sums, idx);
        }
    }

    for (int i = 0; i < q; i++) {
        int query = queries[i];
        if (query > n * n) {
            printf("-1\n");
            continue;
        }

        printf("%lld\n", sums[query - 1]);
    }

    return 0;
}
