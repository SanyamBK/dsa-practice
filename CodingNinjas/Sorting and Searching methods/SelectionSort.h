
void selection_sort(int input[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = input[i], minInd = i;
        for (int j = i + 1; j < n; j++) {
            if (input[j] < min) {
                min = input[j];
                minInd = j;
            }
        }
        int temp = input[i];
        input[i] = input[minInd];
        input[minInd] = temp; 
    }
}
