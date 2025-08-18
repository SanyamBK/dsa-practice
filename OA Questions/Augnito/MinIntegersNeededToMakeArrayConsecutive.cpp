#include <bits/stdc++.h>
using namespace std;

int ArrayChallenge(int arr[], int size) {
    // Find minimum and maximum values
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Calculate total numbers needed in consecutive sequence
    int totalNeeded = max - min + 1;
    
    // Return how many numbers we need to add
    return totalNeeded - size;
}

int main() {
    int arr[] = {1, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = ArrayChallenge(arr, size);
    cout << "Minimum integers needed to make array consecutive: " << result << endl;
    return 0;
}
