#include <iostream>
#include <string>
using namespace std;

void printkeypad(int num, string output) {
    string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (num == 0) {
        cout << output << endl;
        return;
    }
    string digit_chars = arr[num % 10];
    for (int i = 0; i < digit_chars.length(); i++) {
        printkeypad(num / 10, digit_chars[i] + output);
    }
}

void printKeypad(int num){
    printkeypad(num, "");
}


int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    cout << "Possible combinations:" << endl;
    printKeypad(num);
    return 0;
}
