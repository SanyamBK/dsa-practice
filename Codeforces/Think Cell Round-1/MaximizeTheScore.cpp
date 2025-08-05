#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int i = 0;
    long long ans = 0;
    while (i < 2 * n - 1)
    {
        ans += min(a[i], a[i+1]);
        i += 2;
    }

    cout << ans << endl;
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