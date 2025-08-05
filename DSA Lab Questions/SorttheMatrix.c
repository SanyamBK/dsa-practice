#include <stdio.h>
#include <stdbool.h>

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

void quicksort(int input[], int size) {
    return quickSort(input, 0, size - 1);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int sum[n];
    int sorted_sum[n];
    for (int i = 0; i < n; i++) {
        sum[i] = 0;
        sorted_sum[i] = 0;
        for (int j = 0; j < m; j++) {
            sum[i] += matrix[j][i];
            sorted_sum[i] += matrix[j][i];
        }
    }

    quicksort(sorted_sum, n);

    int index[n];
    bool used[n];
    for (int i = 0; i < n; i++) {
        int temp = sorted_sum[i];
        used[i] = false;
        for (int j = 0; j < n; j++) {

            if (temp == sum[j] && !used[j]) {
                index[i] = j;
                used[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][index[j]]);
        }
        printf("\n");
    }

    return 0;
}

