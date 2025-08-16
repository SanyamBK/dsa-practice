#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isAdjacentSame(ll a, int b) {
    int last = a % 10;
    a /= 10;
    while (a > 0) {
        int curr = a % 10; 
        if (curr == last) return true;
        last = curr;
        a /= 10;
    }
    if (last == b) return true;
    return false;
}

int minSteps(int n) {
    if (isAdjacentSame(n, 0)) return 0;
    queue<pair<ll, int>> q;
    q.push({n, 0});
    set<pair<int, int>> visited;
    while (!q.empty()) {
        ll num = q.front().first;
        int steps = q.front().second;
        q.pop();
        ll temp = num;
        int lastDigitOfNum = num % 10;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            ll newNum = num * digit;
            if (visited.find({newNum, lastDigitOfNum}) != visited.end()) {
                continue;
            }
            if (isAdjacentSame(newNum, lastDigitOfNum)) {
                return steps + 1;
            }
            visited.insert({newNum, lastDigitOfNum});
            q.push({newNum, steps + 1});
            
        }
    }
    return -1;

}

int main() {
    int n = 232;
    cout << minSteps(n) << endl;
    return 0;
}