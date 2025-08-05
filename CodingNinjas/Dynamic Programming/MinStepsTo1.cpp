#include <bits/stdc++.h>
using namespace std;

int minSteps(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int x = minSteps(n - 1);
    int y = INT_MAX, z = INT_MAX;

    if (n % 2 == 0)
    {
        y = minSteps(n / 2);
    }

    if (n % 3 == 0)
    {
        z = minSteps(n / 3);
    }

    int ans = min(x, min(y, z)) + 1;

    return ans;
}

int minSteps_helper(int n, int *ans)
{

    if (n <= 1)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int x = minSteps_helper(n - 1, ans);
    int y = INT_MAX, z = INT_MAX;

    if (n % 2 == 0)
    {
        y = minSteps_helper(n / 2, ans);
    }

    if (n % 3 == 0)
    {
        z = minSteps_helper(n / 3, ans);
    }

    int output = min(x, min(y, z)) + 1;

    ans[n] = output;

    return output;
}

int minSteps_2(int n)
{
    int *ans = new int[n + 1];
    memset(ans, -1, sizeof(int) * (n + 1));

    return minSteps_helper(n, ans);
    delete[] ans;
}

int minSteps_3(int n)
{

    int *ans = new int[n + 1]();

    for (int i = 2; i <= n; i++)
    {
        ans[i] = 1 + ans[i - 1];

        if (i % 2 == 0)
        {
            ans[i] = min(ans[i], 1 + ans[i / 2]);
        }

        if (i % 3 == 0)
        {
            ans[i] = min(ans[i], 1 + ans[i / 3]);
        }
    }

    return ans[n];
    delete[] ans;
}

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == -1)
        {
            break;
        }
        cout << "Min steps to 1 from " << n << ": " << minSteps_3(n) << endl;
    }
}
