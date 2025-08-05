#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
int getA();
vector<char> getB(int size);
void displayC();
void displayD();

void processE() {
    int f = getA();
    vector<char> g = getB(f);
    vector<char> h = getB(f);
    for (int i = 0; i < f; i++) {
        if (g[i] == '0' && h[i] == '1') {
            displayC();
            return;
        }
        if (g[i] == '0' && h[i] == '0') continue;
        else break;
    }
    displayD();
}

void startF() {
    int j = 1;
    j = getA();
    while (j-- > 0) processE();
}

int main() {
    startF();
    return 0;
}

// Helper functions
int getA() {
    int k;
    cin >> k;
    return k;
}

vector<char> getB(int size) {
    vector<char> l(size);
    for (int m = 0; m < size; ++m) {
        cin >> l[m];
    }
    return l;
}

void displayC() {
    cout << "NO" << endl;
}

void displayD() {
    cout << "YES" << endl;
}