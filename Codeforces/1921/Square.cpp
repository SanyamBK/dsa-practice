#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    vector<pair<int, int>> points;
    for (int i = 0; i < 4; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    pair<int, int> p1 = points[0];
    int x1 = p1.first;
    int y1 = p1.second;

    pair<int, int> p2;
    pair<int, int> p3;

    bool found1 = false;
    bool found2 = false;
    int i = 0;
    while ((found1 == false || found2 == false) && i < 4)
    {

        if (points[i].first != x1 && points[i].second == y1)
        {
            p2 = points[i];
            found1 = true;
        }

        if (points[i].first == x1 && points[i].second != y1)
        {
            p3 = points[i];
            found2 = true;
        }

        i++;
    }

    int x2 = p2.first;
    int y2 = p2.second;

    long side = abs(x2 - x1) + abs(y2 - y1);
    long area = side * side;
    cout << area << endl;
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