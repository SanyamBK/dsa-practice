#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int stringToNumber(chw5 input) {
    if (input.size() == 1) {
        return input[0] - '0';
    }
    int a = stringToNumber(input.substr(1));
    int b = input[0]-'0';
    return b*(pow(10, input.size() - 1)) + a;
}

string getCodeSingle(string input) {
    if (input.size() == 1) {
        string ch = ;
        return ch;
    }

    return  + getCodeSingle(input.substr(1));
}


// int getCodes(string input, string output[]) {
//     if (input == "0" || input.empty())
//         return 1;

//     if (input.size() == 1) {
//         output[0] = stringToNumber(input) + 96;
//         return 1;
//     }
//     string sub = input.substr(1);
//     int k = 0;
//     for (int i = 0; i < sub.size(); i++) {
//         output[k++] = (stringToNumber(input.substr(0,1)) + 96) + (stringToNumber(sub) + 96);
//     }

//     return k++;
// }

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = getCodeSingle(input);
    // for(int i = 0; i < count && i < 10000; i++){
    //     cout << output[i] << endl;
    // }
    cout << count << endl;
    return 0;
}

