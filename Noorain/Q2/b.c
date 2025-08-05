#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int *nextGreaterCircular(int *nums, int n)
{
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        result[i] = -1;
    }
    Stack *stack = createStack();
    for (int i = 0; i < 2 * n; ++i)
    {
        int num = nums[i % n];
        int j = top(stack);
        while (!isEmpty(stack) && nums[j] < num)
        {
            result[j] = num;
            pop(stack);
            j = top(stack);
        }
        if (i < n)
        {
            push(stack, i);
        }
    }
    free(stack);
    return result;
}

int main()
{

    int nums[] = {1, 2, 3, 4, 3};
    int n = sizeof(nums) / sizeof(int);

    int *result = nextGreaterCircular(nums, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}
