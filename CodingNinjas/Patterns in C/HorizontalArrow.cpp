#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i <= 10; i++)
    {
        if (i < 4)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << "   ";
            }
            for (int j = 0; j < i + 1; j++)
            {
                cout << " * ";
            }
            cout << endl;
        }

        if (i >= 4 && i <= 6)
        {

            {
                if (i == 5)
                {
                    for (int j = 0; j <= 15; j++)
                    {
                        cout << " * ";
                    }
                }
                else
                {
                    for (int j = 0; j <= 14; j++)
                    {
                        cout << " * ";
                    }
                }
                cout << endl;
            }
        }
        if (i > 6)
        {
            for (int j = 0; j < 10 && i > 5; j++)
            {
                cout << "   ";
            }
            for (int j = 10 - i + 1; j > 0 && i > 5; j--)
            {
                cout << " * ";
            }
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
