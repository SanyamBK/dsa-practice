#include <stdio.h>
#include <stdlib.h>

int hexToDec(void *address)
{
    unsigned long long ans = (unsigned long long)address;
    return ans % 1000000;
}

int main()
{
    int integerArray[10]; // Example integer array

    printf("%p\n", integerArray);

    printf("%d\n", hexToDec(integerArray));

    return 0;
}
