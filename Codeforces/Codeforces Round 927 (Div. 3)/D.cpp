#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int n;
    cin >> n;
    char ch;
    cin >> ch;
    unordered_map<char, vector<string>> cards;
    vector<pair<string, string>> answer;

    for (int i = 0; i < 2 * n; i++)
    {
        string card;
        cin >> card;
        cards[card[1]].push_back(card);
    }

    while (true)
    {

        for (auto &pair : cards)
        {
            if (pair.first == ch)
            {
                continue;
            }
            char suit = pair.first;
            sort(pair.second.begin(), pair.second.end());

            if (pair.second.size() >= 2)
            {
                // Play the first two cards from the set
                int i = pair.second.size() - 1;
                int j = pair.second.size() / 2;
                while (j > 0)
                {

                    answer.push_back({pair.second[i - 1], pair.second[i]});
                    pair.second.pop_back();
                    pair.second.pop_back();
                    i -= 2;
                    j--;
                }
            }
            if (pair.second.size() == 1)
            {
                // Check if there are any trump cards left
                if (cards[ch].empty())
                {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }

                // Find a card from the set which is equal to ch and store that card along with the card from the set
                int i = cards[ch].size() - 1;
                answer.push_back({pair.second[0], cards[ch][i]});
                cards[ch].pop_back();
                pair.second.pop_back();
            }
        }

        if (cards[ch].empty())
        {
            break;
        }

        // Check if the set of cards equal to ch is not empty
        if (!cards[ch].empty())
        {
            // Store the first two cards from the set
            int i = cards[ch].size() - 1;
            int j = cards[ch].size() / 2;
            sort(cards[ch].begin(), cards[ch].end());
            while (j > 0)
            {
                answer.push_back({cards[ch][i - 1], cards[ch][i]});
                cards[ch].pop_back();
                cards[ch].pop_back();
                i -= 2;
                j--;
            }
            break;
        }
    }

    if (answer.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {

        for (const auto &pair : answer)
        {
            cout << pair.first << " " << pair.second << endl;
        }
    }
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
