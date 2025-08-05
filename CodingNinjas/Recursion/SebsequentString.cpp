#include <iostream>
#include <string>
using namespace std;

int subsequent_string(string input, string output[]) {
    if (input.empty()) {
        output[0] = "";
        return 1;
    }
    string sub = input.substr(1);
    int size = subsequent_string(sub, output);
    for (int i = 0; i < size; i++) {
        output[i+size] = input[0] + output[i];
    }
    return 2 * size;
}

void print_substring(string input, string output) {
    if (input.length() == 0) {
        cout << output << endl;
        return;
    }
    print_substring(input.substr(1), output);
    print_substring(input.substr(1), output + input[0]);
}

int main () {
    string input;
    cin >> input;
    string output = "";
    print_substring(input, output);

}