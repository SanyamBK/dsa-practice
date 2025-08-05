#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;

    int count = 0;
    string str = "";
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            str[i] += a[i];
        }
        else
        {
            str += toupper(c[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (str[i] != c[i])
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            char ch = tolower(str[i]);
            if (ch != a[i] && ch != b[i])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
}