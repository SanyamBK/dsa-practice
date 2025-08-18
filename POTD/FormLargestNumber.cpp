#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    string str_a = to_string(a);
    string str_b = to_string(b);
    int ab = stoi(str_a + str_b);
    int ba = stoi(str_b + str_a);
    return ab > ba;
    
}


string findLargest(vector<int> &arr) {
    if (all_of(arr.begin(), arr.end(), [](int x){ return x == 0;})) {
            return "0";
        }
    
    sort(arr.begin(), arr.end(), cmp);
    
    string ans = "";
    for (auto it : arr) {
        ans += to_string(it);
    }
    return ans;
}

int main() {
    vector<int> arr = {0, 0, 0, 0, 0, 0};
    cout << findLargest(arr) << endl;
    return 0;
}