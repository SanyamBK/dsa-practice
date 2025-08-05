#include <bits/stdc++.h>
using namespace std;

#define ll long long




void testCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (auto &x : a)
    {
        cin >> x;
        s.insert(x);
    }

    int mex;
    
    for (int i = 0; i < n; i++)
    {

        if (a[0] != i)
        {
            mex = i;
            break;
        }
    }

    vector<int> b(a);
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] == i)
        {
            cout << -1 << endl;
            return;
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i)
        {
            if (a[i] == mex)
            {
                ans.push_back({i, 0});
                a[0] = mex;
            }
            else
            {
                ans.push_back({i, mex});
                a[i] = mex;
            }
        }
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