#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(x) cout << x << endl

void testCase()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x1, y1;
    cin >> x1 >> y1;

    int x2, y2;
    cin >> x2 >> y2;

    if ((x1 < y1 && x2 > y2) || (x1 > y1 && x2 < y2)) {
        print("No");
    } else {
        print("Yes");
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        testCase();
    }
    return 0;
}