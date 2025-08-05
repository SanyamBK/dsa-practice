#include <iostream>
#include "BinarySearchTree.h"
#include <cstring>
using namespace std;

int compareStrings(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char*) str1 - *(const unsigned char*) str2;
}


int main() {
    int n, q;
    cin >> n;

    BST<char*> bsst;
    for (int i = 0; i < n; i++) {
        char str[20];
        cin >> str;
        bsst.insert(str);
    }

    bsst.print();
    
}

