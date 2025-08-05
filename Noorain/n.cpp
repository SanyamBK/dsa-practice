#include <bits/stdc++.h>

using namespace std;

void generateSubarrays(const vector<int>& arr, int start, int end, vector<vector<int>>& subarrays) {
    if (start > end)
        return;

   
    for (int i = start; i <= end; ++i) {
        vector<int> currentSubarray;
        for (int j = start; j <= i; ++j) {
            currentSubarray.push_back(arr[j]);
        }
        subarrays.push_back(currentSubarray);
    }

    generateSubarrays(arr, start + 1, end, subarrays);
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> subarrays;

    generateSubarrays(arr, 0, arr.size() - 1, subarrays);

    int maxSum = INT_MIN;

    for (const auto& subarray : subarrays) {
        int sum = 0;
        for (int i : subarray) {
            sum += i;
        }
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
}

// Time Complexity: O(2^n)
