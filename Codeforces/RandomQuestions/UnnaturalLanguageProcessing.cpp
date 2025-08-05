#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    while (i < n)
    {
        if (s[i] == 'b' || s[i] == 'c' || s[i] == 'd')
        {
            int count = 1;
            if (s[i - 1] == 'b' || s[i - 1] == 'c' || s[i - 1] == 'd')
            {
                s.insert(i, ".");
                n++;
            }
            if (s[i - 1] == 'a' || s[i - 1] == 'e')
            {
                count++;
                if ((s[i - 2] == 'b' || s[i - 2] == 'c' || s[i - 2] == 'd') && (i - 2 >= 0))
                {
                    count++;
                    s.insert(i - 3, ".");
                    count = 0;
                }
            }
        }
        i++;
    }
    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        testCase();
    }
}