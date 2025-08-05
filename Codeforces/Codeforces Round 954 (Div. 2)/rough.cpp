#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define forloop(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << endl;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        forloop(i, 0, n)
        {
            cin >> a[i];
        }

        int max = *max_element(all(a));

        int secondMax = 0;

        if (max == a[n - 1])
        {
            forloop(i, 0, n - 1)
            {
                if (a[i] > secondMax)
                {
                    secondMax = a[i];
                }
            }
            int ans = secondMax + max;
            print(ans);
        }
        else
        {
            int ans = max + a[n - 1];
            print(ans);
        }
    }
}