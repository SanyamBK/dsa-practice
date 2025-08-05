#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    long n, f, a, b;
    cin >> n >> f >> a >> b;

    vector<long> m(n);
    for (long i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    if (count == n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        testCase();
    }
    return 0;
}