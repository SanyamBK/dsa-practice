#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    float sum = 0;
    int var;
    for (int i = 0; i < n; i++)
    {
        cin >> var;
        sum += var;
    }
    float ans = sqrt(sum);
    if (ans == (int)ans)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
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