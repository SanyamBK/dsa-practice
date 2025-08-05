#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxOfArray(int input[], int end) {
    int max = input[0];
    for (int i = 1; i <= end; i++) {
        max = fmax(max, input[i]);
    }
    return max;
    
}

 
int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    int *cards = (int*) malloc(n* sizeof(int));
    for (int i = 0; i < n; i++ )
        scanf("%d", &cards[i]);
    int ISHU = 0;
    int ROHU = 0;
    
    int currmax = maxOfArray(cards, k-1);
    ISHU += currmax;
    for (int i = 1; i < n - k + 1; i++) {
        if (currmax != cards[i-1])
            currmax = fmax(currmax, cards[i+k-1]);
        else currmax = maxOfArray(cards+i, k-1);

        if (i%2 != 0)
            ROHU += currmax;
        else 
            ISHU += currmax;
    }


    if (ISHU > ROHU) printf("ishu");
    else if (ROHU > ISHU) printf("rohu");
    else printf("draw");
    
    free(cards);

    return 0;
}