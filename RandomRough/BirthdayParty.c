#include <stdio.h>

void merge(int input[], int start, int mid, int end) {
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (input[i] < input[j]) {
            temp[k++] = input[i++];
        } else {
            temp[k++] = input[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = input[i++];
    }
    while (j <= end) {
        temp[k++] = input[j++];
    }
    for (int l = 0; l < k; l++) {
        input[start + l] = temp[l];
    }
}

void mergeSort(int input[], int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(input, start, mid);
    mergeSort(input, mid + 1, end);
    merge(input, start, mid, end);
}

void mergesort(int input[], int size) {
    mergeSort(input, 0, size - 1);
}

void swap(int input[], int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

int compareArrays(int input1[], int input2[], int n) {
    int swaps = 0;
    int i = 0;
    while (i < n) {
        if (input1[i] == input2[i]) {
            i++;
        } else {
            int searchVal = input2[i];
            for (int j = i; j < n; j++) {
                if (input1[j] == searchVal) {
                    swap(input1, i, j);
                    swaps++;
                    break;
                }
            }
        }
    }
    return swaps;
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    int sorted_array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        sorted_array[i] = array[i];
    }
    mergesort(sorted_array, n);
    int ans = compareArrays(array, sorted_array, n);
    printf("%d", ans);
    return 0;
}
