#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long staircase_helper(int n, long long *ans)
{
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;

    if (ans[n] != -1)
        return ans[n];

    long long x = staircase_helper(n - 1, ans) % mod;
    long long y = staircase_helper(n - 2, ans) % mod;
    long long z = staircase_helper(n - 3, ans) % mod;

    long long output = (x + y + z) % mod;

    ans[n] = output;

    return output;
}

long long staircase(int n)
{
    long long *ans = new long long[n + 1]();
    memset(ans, -1, sizeof(long long) * (n + 1));

    long long output = staircase_helper(n, ans);
    delete[] ans;
    return output;
}

int staircase_2(int n)
{
    long long *ans = new long long[n + 1]();
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        ans[i] = (ans[i - 1] + ans[i - 2] + ans[i - 3]) % mod;
    }

    return ans[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << staircase_2(n) << endl;
    }
    return 0;
}