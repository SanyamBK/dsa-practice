#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    long long sum = 0;
    int var;
    for (int i = 0; i < n; i++)
    {
        cin >> var;
        sum += var;
    }
    long double ans = sqrt(sum);
    if (floor(ans) == ceil(ans))
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