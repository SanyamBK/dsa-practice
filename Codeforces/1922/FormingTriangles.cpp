#include <bits/stdc++.h>
using namespace std;

unordered_map<int, long long> memo;

long long factorial(int n)
{
    if (n < 0)
    {
        // cerr << "Factorial is not defined for negative numbers" << endl;
        return -1; // or any other value to indicate an error
    }
    else if (n == 0 || n == 1)
    {
        return 1;
    }
    else if (memo.find(n) != memo.end())
    {
        return memo[n];
    }
    else
    {
        long long result = n * factorial(n - 1);
        memo[n] = result;
        return result;
    }
}

void testCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }
    if (n < 3)
    {
        cout << 0 << endl;
        return;
    }
}
