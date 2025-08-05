void swap(int input[], int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

int partition(int input[], int s, int e) {
    int pivot = input[s];
    int i = s, j = e;
    while (i < j) {
        while (input[i] <= pivot && i < e) i++;
        while (input[j] > pivot) j--;
        if (i < j) swap(input, i, j);
    }
    swap(input, s, j);
    return j;
}

void quickSort(int input[], int si, int ei) {
    if (si >= ei) return;
    int pi = partition(input, si, ei);
    quickSort(input, si, pi-1);
    quickSort(input, pi+1, ei); 
}

int maxOfArray(int input[], int size) {
    quickSort(input, 0, size-1);
    return input[size-1];

}