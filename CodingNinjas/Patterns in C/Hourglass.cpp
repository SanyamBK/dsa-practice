#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    // cin >> n;
    int j = 0;


    for (int i = 1; i < n; i++)
    {

        if (i == 1)
        {
            for (j = 1; j <= n; j++)
            {
                cout << j << " ";
            }
            
        }
        int count = 1;
        cout << endl;
        for (int k = 0; k < i; k++)
        {
            cout << " ";
        }

        while (count <= n - i)
        {
            if (j <= 9 && count <= n - i)
            {
                cout << j << " ";
                j++;
                count++;
            }
            else if (j > 9 && j % 2 == 0 && count <= n - i) {
                cout << 0 << " ";
                j++;
                count++;
            }
            else if (j > 9 && j % 2 != 0 && count <= n - i){
                cout << 9 << " ";
                j++;
                count++;
            }
        }
    }
    j -= 2;
    for (int i = 2; i <= n; i++)
    {
        int count = 1;
        cout << endl;
        for (int k = 0; k < n - i; k++)
        {
            cout << " ";
        }
        while (count <= i)
        {
            if (j <= 9 && count <= i)
            {
                cout << j << " ";
                j--;
                count++;
            }
            else if (j > 9 && j % 2 == 0 && count <= i) {
                cout << 0 << " ";
                j--;
                count++;
            }
            else if (j > 9 && j % 2 != 0 && count <= i){
                cout << 9 << " ";
                j--;
                count++;
            }
        }
       
    }
    return 0;
}