#include <bits/stdc++.h>
using namespace std;

int selection_sort(int input[], int n) {
    int maxK = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = input[i], minInd = i;
        for (int j = i + 1; j < n; j++) {
            if (input[j] < min) {
                min = input[j];
                minInd = j;
            }
        }
        int k = abs(i - minInd);
        int temp = input[i];
        input[i] = input[minInd];
        input[minInd] = temp; 
        if (k > maxK)
            maxK = k;
    }
    return maxK;
}

void testCase() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = selection_sort(a, n);
    cout << k << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }

    return 0;
}
