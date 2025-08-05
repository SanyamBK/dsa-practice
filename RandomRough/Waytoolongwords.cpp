#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string shortenedword(string &input) {
    string output;
    int len = input.length();
    if (len > 10) {
       output = input[0] + to_string(len-2) + input[len-1];
    return output;
    } else {
        output = input;
    return output;
    }
}

int main () {
    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        input = shortenedword(input);
        cout << input << endl;
    }
    return 0;
}
