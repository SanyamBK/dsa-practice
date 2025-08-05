#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(const vector<int>& arr, int start, int end) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = start; i <= end; ++i) {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0) {
            currentSum = 0;  
        }
    }

    return maxSum;
}

int maxSubArraySumRecursive(const vector<int>& arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }

    int mid = start + (end - start) / 2;

    int leftMax = maxSubArraySumRecursive(arr, start, mid);
    int rightMax = maxSubArraySumRecursive(arr, mid + 1, end);

    int crossingMax = maxSubArraySum(arr, start, mid) + maxSubArraySum(arr, mid + 1, end);

    return max({leftMax, rightMax, crossingMax});
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max_element1 = maxSubArraySum(arr, 0, arr.size() - 1);

    cout << max_element1 << endl;


    return 0;
}

// Time Complexity: O(NlogN)