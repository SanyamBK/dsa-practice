#include <iostream>
#include <cstring>
using namespace std;

void swap(char* xp, char* yp) {
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortString(char input[]) {
    for (int i = 0; i < strlen(input)-1; i+=2) {
        for (int j = 0; j < strlen(input) - i - 1; j+=2) {
            if (input[j] > input[j+2]) {
                swap(&input[j], &input[j+2]);
            }
        }
    }
}

int main() {
    char str[1000];
    cin >> str;
    sortString(str);
    cout << str << endl;
    return 0;
}
