#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    string s, f;
    cin >> s >> f;

    int count = 0;
    int catsS = 0;
    int catsF = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            catsS++;
        if (f[i] == '1')
            catsF++;
    }

    count = max(catsS, catsF);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && f[i] == '1')
        {
            count--;
        }
    }

    cout << count << endl;
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