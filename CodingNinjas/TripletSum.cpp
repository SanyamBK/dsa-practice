#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num) {
    sort(arr, arr + n);
    int count = 0;
    for (int k = 0; k < n - 2; k++) {
        int tempCount = 0;

        int i = k+1;
        int j = n - 1;

        while (i < j) {
            if (arr[i] + arr[j] + arr[k] < num) {
                i++;
            } else if (arr[i] + arr[j] + arr[k] > num) {
                j--;
            } else {
                if (arr[i] == arr[j] && arr[j] == arr[k]) {
                    int total = (j - k) + 1;
                    tempCount = (total * (total - 1) * (total - 2) / 6);
                    count += tempCount;
                    k = j + 1;
                    
                } else if (arr[i] == arr[j]) {
                    int total = (j - i) + 1;
                    tempCount = (total * (total - 1) / 2);
                    count += tempCount;
                    i = j + 1;

                } else {
                    int tempi = i + 1;
                    int tempj = j - 1;

                    while (tempi <= tempj && arr[tempi] == arr[i]) {
                        tempi++;
                    }

                    while (tempj >= tempi && arr[tempj] == arr[j]) {
                        tempj--;
                    }

                    int totali = (tempi - i);
                    int totalj = (j - tempj);
                    tempCount = (totali * totalj);
                    count += tempCount;

                    i = tempi;
                    j = tempj;
                }
            }
        }
    }

    return count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}