#include <bits/stdc++.h>
using namespace std;

long long fibo_3(long long n)
{ // dp
    long long *ans = new long long[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for (long long i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];
}

long long fibo(long long n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

long long fibo_helper(long long n, long long *ans)
{ // memoization
    if (n <= 1)
    {
        return n;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    long long a = fibo_helper(n - 1, ans);
    long long b = fibo_helper(n - 2, ans);
    ans[n] = a + b;

    return ans[n];
}

long long fibo_2(long long n)
{
    long long *ans = new long long[n + 1];
    memset(ans, -1, sizeof(long long) * (n + 1));

    return fibo_helper(n, ans);
}

int main()
{
    int n;
    while (n != -1)
    {
        cin >> n;
        cout << fibo_2(n) << endl;
    }
}
