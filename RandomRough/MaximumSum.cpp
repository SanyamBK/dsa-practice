#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int n, k;
    cin >> n >> k;
    int *array = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        sum += array[i];
    }
    sort(array, array + n);
    int s = 0;
    int e = n - 1;
    priority_queue<int> pq;
    while (k--) {
        int sum1 = array[e];
        int sum2 = array[s] + array[s+1];
        if (sum1 > sum2) {
            sum -= sum1;
            e--;
        } else {
            sum -= sum2;
            s += 2;
        }
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
}

// 6 2
// 15 22 12 10 13 11