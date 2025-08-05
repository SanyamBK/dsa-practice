#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 0)
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;
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