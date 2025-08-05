#include <stdio.h>
#include <stdlib.h>

void swap(long *a, long*b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(long *pq, int n, int i) {
    int max = i;
    if (2 * i + 1 < n && pq[2 * i + 1] > pq[max]) {
        max = 2 * i + 1;
    }
    if (2 * i + 2 < n && pq[2 * i + 2] > pq[max]) {
        max = 2 * i + 2;
    }

    if (max != i) {
        swap(&pq[i], &pq[max]);
        heapify(pq, n, max);
    }
}

void heapSort(long pq[], int size) {
    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(pq, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        swap(&pq[0], &pq[i]);
        heapify(pq, i, 0);
    }
}

int main () {
    int n;
    scanf("%d", &n);

    long *array = (long*) malloc(n*sizeof(long));

    for (int i = 0; i < n; i++) {
        scanf("%ld", &array[i]);
    }

    heapSort(array, n);

    for (int i = 0; i < n; i++) {
        printf("%ld ", array[i]);
    }

    return 0;
}