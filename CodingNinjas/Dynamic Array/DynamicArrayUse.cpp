#include <iostream>
using namespace std;
#include "DynamicArrayClass.cpp"

int main () {
    DynamicArray d1;
    d1.append(10);
    d1.append(12);
    d1.append(15);
    d1.append(40);
    d1.append(50);
    d1.append(60);
    
    DynamicArray d2(d1);
    d2.insert(3, 24);

    d1.append(20);
    d1.insert(8, 8);
    d1.insert(7, 8);

    d1.append(30);
    d1.insert(9, 80);
    d1.insert(10, 70);

    d1.insert(7, 90);
    d1.append(100);
    d1.pop(12);
    d1.deleteElement(12);
    cout << d1.Search(1) << endl;

    d1.printIndex();

    d1.Capacity();
    d1.printArray();

    return 0;
}