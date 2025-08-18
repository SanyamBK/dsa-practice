#include <bits/stdc++.h>
using namespace std;

int countVowels(string s) {
    string vowels = "aeiouAEIOU";
    bool isVowel[256] = {false}; 
    for (char v : vowels) {
        isVowel[v] = true; // Mark vowels in the lookup table
    }
    int count = 0;
    for (char c : s) {
        count += isVowel[c]; // Increment count if character from given string is a vowel
    }
    return count;
}

int main() {
    string input = "Hello World";
    // cout << "Enter a string: ";
    // getline(cin, input);
    int result = countVowels(input);
    cout << "Number of vowels in the string: " << result << endl;
    return 0;
}
