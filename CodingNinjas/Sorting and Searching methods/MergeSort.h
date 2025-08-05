void merge(int input[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    int temp[end - start + 1];
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
 
void mergeSort(int input[], int start, int end) {
    if (start >= end) return ;
    int mid = (start + end)/2;
    mergeSort(input, start, mid);
    mergeSort(input, mid+1, end);
    merge(input, start, mid, end);
 
}
 
void mergesort(int input[], int size) {
    mergeSort(input, 0, size-1);
}