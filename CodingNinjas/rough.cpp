#include <iostream>
using namespace std;

int sum(int n) {
	if (n <= 1)
		return n;
	
	return n + sum(n-1);
}


int main() {
    int *array = new int[5]();
    // int array2[5] = {0};

    // if (array == array)
    //     cout << "true" << endl;
    // else 
    //     cout << "false" << endl;

    cout << sum(4) << endl;

}
