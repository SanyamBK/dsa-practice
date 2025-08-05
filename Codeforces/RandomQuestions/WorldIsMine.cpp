#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> uniqueTastiness;
    vector<int> counts;

    for (int i = 0; i < n;)
    {
        int current = a[i];
        int count = 0;
        while (i < n && a[i] == current)
        {
            count++;
            i++;
        }
        uniqueTastiness.push_back(current);
        counts.push_back(count);
    }

    int m = uniqueTastiness.size();
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= m; ++i)
    {
        int sum = 0;
        for (int k = 0; k < i; ++k)
        {
            sum += counts[k];
            if (sum <= uniqueTastiness[i - 1] - (i - k - 1))
            {
                dp[i] = min(dp[i], dp[k] + sum);
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= m; ++i)
    {
        if (dp[i] <= n)
        {
            result = max(result, m - i);
        }
    }

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        testCase();
    }
    return 0;
}
