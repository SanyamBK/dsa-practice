#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forloop (i, a, b) for (int i = a; i < b; i++)

void testCase()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = 0; // [1
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += i;
    }

    sort(a.begin(), a.end(), greater<int>());
    
    for (int i = n; i >= 0; i--)
    {
        a[i] = min(a[i], a[i-1]-1);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    cout << endl;
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