#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{

    if (n == 0)
        return 0;

    int mincnt = n;
    for (int i = 1; i <= int(pow(n, 0.5)); i++)
    {
        int cnt = 1 + minCount(n - i * i);
        mincnt = min(mincnt, cnt);
    }

    return mincnt;
}

int minCount_2(int n)
{
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int mincnt = i;
        for (int j = 1; j <= int(pow(i, 0.5)); j++)
        {
            mincnt = min(mincnt, 1 + dp[i - j * j]);
        }
        dp[i] = mincnt;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}