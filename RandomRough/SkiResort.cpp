#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

void testCase() {
    int n, k, q;
    cin >> n >> k >> q;
    int *A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int i = 0, j = 0;
    unsigned long long count = 0;
    while (i < n) {
        if (A[i] <= q) {
            j = i;
            while (j < n && A[j] <= q) j++;
            int l = j - i;
            if (l >= k) {
                count += factorial(l - k + 2) / (factorial(l - k) * factorial(2));
            }
            i = j;
        } else {
            i++;
        }
    }
    cout << count << endl;
    delete[] A;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        testCase();
    }

    return 0;
}
