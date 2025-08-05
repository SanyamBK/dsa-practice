#include <stdio.h>
#include <stdlib.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

int main() {
    int arr[] = {40 , 10 , 20 , 50 , 30};
    // int arr[] = {10 , 20 , 30};
    // int arr[] = {1, 2, 3, 4, 5};
    // int arr[] = {7, 7, 7, 7};
    // int arr[] = {40, 10, 20, 50, 30};
    // int arr[] = {5, 4, 3, 2, 1};
    // int arr[] = {10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // copy the array dynamically
    int *arr2 = (int *)malloc(arr_size * sizeof(int));
    for (int i = 0; i < arr_size; i++) {
        arr2[i] = i;
    }

    // Insertion sort
    for (int i = 0; i < arr_size; i++) {
        int current = arr[i];
        int j = i - 1;
        int ind = arr2[i];
        while (j >= 0 && arr[j] > current) {
            arr[j+1] = arr[j];
            arr2[j+1] = arr2[j];
            j--;
        }
        arr[j+1] = current;
        arr2[j+1] = ind;
    }

    int max = 0;
    for (int i = 0; i < arr_size; i++) {
        int k = abs(arr2[i] - i);
        if (k > max) {
            max = k;
        }
    }

    free(arr2);
    printf("%d\n", max);
    
}