#include <stdio.h>
#include <stdlib.h>

void cardGame(int input[], int n, int k, int *ishu_score, int *rohu_score) {
    int currmax = input[0];
    int i = 0;
    while (i <= n-k) {
        // update current maximum value if discarded card was the maximum value
        if (input[i] == currmax) {
            currmax = 0;
            for (int j = i+1; j <= i+k; j++) {
                if (input[j] > currmax) {
                    currmax = input[j];
                }
            }
        }
        // add current maximum value to ISHU or ROHU score
        if (i % 2 == 0) {
            *ishu_score += currmax;
        } else {
            *rohu_score += currmax;
        }
        // move to next k-sized hand
        i += 2;
        currmax = input[i];
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *cards = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }
    int ishu_score = 0;
    int rohu_score = 0;
    cardGame(cards, n, k, &ishu_score, &rohu_score);
    if (ishu_score > rohu_score) {
        printf("ishu");
    } else if (rohu_score > ishu_score) {
        printf("rohu");
    } else {
        printf("draw");
    }
    free(cards);
    return 0;
}
