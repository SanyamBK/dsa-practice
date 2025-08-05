#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int subsetSumToK(int input[], int n, int output[][100], int k) {
    if(n==0) {
        if(k==0) {
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }

    int smallOutput1 = subsetSumToK(input+1,n-1,output,k);
    int smallOutput2 = subsetSumToK(input+1,n-1,output+smallOutput1,k-input[0]);
    
    int smallOutputSize = smallOutput1+smallOutput2;
    for(int i = smallOutput1; i < smallOutputSize;i++)
    {
        for(int j = output[i][0]; j > 0; j--)
        {
            output[i][j+1] = output[i][j];
        }
        output[i][1] = input[0];
        output[i][0]++;
    }
    return smallOutputSize;
    
}


int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int output[100][100];
    int length = subsetSumToK(arr, n, output, k);
    int min = INT_MAX;
    for (int i = 0;i < length; i++) {
        if (output[i][0] < min)
            min = output[i][0];
    }

    if (min == 2147483647)
        min = -1;
    printf("%d", min);
    
}

