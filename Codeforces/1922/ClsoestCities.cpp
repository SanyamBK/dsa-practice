// For each query, print one integer — the minimum number of coins you have to spend.
#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            // Handle the first city
            mp[i] = i + 1;
        }
        else if (i == n - 1)
        {
            // Handle the last city
            mp[i] = i - 1;
        }
        else
        {
            // Compare distances to determine the closest city
            if (abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1]))
            {
                mp[i] = i + 1;
            }
            else
            {
                mp[i] = i - 1;
            }
        }
    }

    // print map
    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // Rest of your code goes here

    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int ans = 0;
        while (true)
        {
            int nextCity = x + 1;
            if (x == y)
            {
                break;
            }
            if (x < y && nextCity == mp[x])
            {
                x = nextCity;
                ans++;
                continue;
            }
            else if (x < y && nextCity != mp[x])
            {
                x = nextCity;
                ans += abs(a[x] - a[nextCity]);
                continue;
            }
        }
        cout << ans << endl;
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