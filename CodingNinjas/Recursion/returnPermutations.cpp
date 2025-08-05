#include <iostream>
#include <string>
using namespace std;


int returnPermutations(string input, string output[]) {
    if (input.empty())
        return 1;
    string smalloutput[10000];
    int size = returnPermutations(input.substr(1), smalloutput);
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= smalloutput[i].size(); j++) {
            output[k++] = smalloutput[i].substr(0, j) + input[0] + smalloutput[i].substr(j);
        }
    }
    return k;
}