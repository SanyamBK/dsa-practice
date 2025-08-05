#include <bits/stdc++.h>
using namespace std;

#define forloop(i, k, n) for (int i = int(k); i < int(n); i++)

void testcase() {
    int N, K;
    cin >> N >> K;
    vector<long> S1(N), S2(N);
    
    forloop(i, 0, N) {
        cin >> S1[i];
    }

    forloop(i, 0, N) {
        cin >> S2[i];
    }

    
    // forloop(i, 0, N) {
    //     if (K == 0) 
    //         break;
    //     if (i < N - 1) {
    //         long diff = abs(S1[i] - S1[i+1]);
    //         if (abs(S2[i] - S1[i+1]) < diff) {
    //             swap(S2[i], S1[i]);
    //             K--;
    //         } else if (abs(S2[i+1] - S1[i]) < diff) {
    //             swap(S2[i+1], S1[i+1]);
    //             K--;
    //         }
    //     }
    // }

    priority_queue<pair<int, int>> pq;

    forloop(i, 0, N) {
        if (i < N - 1) {
            int diff = abs(S1[i] - S1[i+1]);
            pq.push(make_pair(diff, i));
        }
    }
    
    while (K > 0 && !pq.empty()) {
        pair<int, int> p = pq.top();
        int diff = p.first;
        int index = p.second;

        if (abs(S2[index] - S1[index+1]) < diff) {
            swap(S1[index], S2[index]);
            K--;
            pq.pop();
            int newDiff = abs(S1[index] - S1[index+1]);
            pq.push(make_pair(newDiff, index));
        } else if (abs(S2[index+1] - S1[index]) < diff) {
            swap(S2[index+1], S1[index+1]);
            K--;
            pq.pop();
            int newDiff = abs(S1[index] - S1[index+1]);
            pq.push(make_pair(newDiff, index));
        } else {
            break; // No more swaps possible
        }
    }

    int max = -1;
    forloop(i, 0, N) {
        if (i > 0 && abs(S1[i] - S1[i-1]) > max) {
            max = abs(S1[i] - S1[i-1]);
        }
    }


    cout << max << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}