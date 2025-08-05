#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;
    while (q--)
    {
        int indx, val;
        cin >> indx >> val;

        int ans = -1;
        int I = indx - 1;
        int bitwiseOR = 0;

        for (I = indx - 1; I < n; I++)
        {
            bitwiseOR |= a[I];
            if (bitwiseOR >= val)
            {
                ans = I + 1;
                break;
            }
        }

        cout << ans << " ";
    }
}
