#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // write your code here
        int n;
        cin >> n;
        vector<int> a(n);

        int lcm = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            int y = gcd(lcm, a[i]);
            y = a[i] / y;
            lcm *= y;

        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            sum += lcm / a[i];
            ans.push_back(lcm / a[i]);
        }
        if (sum >= lcm)
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}