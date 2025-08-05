#include <iostream>
using namespace std;

#include <stack>
#include <queue>

void reverseStack(stack<int> &input, stack<int> &extra) {
    while (!input.empty()) {
        int val = input.top();
        extra.push(val);
        input.pop();
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}