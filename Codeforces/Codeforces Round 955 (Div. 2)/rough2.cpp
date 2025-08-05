#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        long long ans = x;
        int temp = y - (x % y);

        while (k > 0)
        {
            if (temp <= k)
            {
                k -= temp;
            }
            else
            {
                ans += k;
                break;
            }

            ans += temp;
            while (ans % y == 0)
            {
                ans /= y;
            }

            temp = y - (ans % y);
            if (ans < y)
            {
                int temp2 = y - 1;
                k -= (k / temp2) * temp2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
