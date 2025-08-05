#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int *cards = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    qsort(cards, n, sizeof(int), compare);

    int score = 0;
    for (int i = 0; i < n; i++) {
        score += cards[i];
    }

    while (n >= 2) {
        int smallest = cards[0];
        int largest = cards[n - 1];
        score = score - smallest - largest;
        int diff = abs(largest - smallest);

        cards[0] = diff;
        qsort(cards, n, sizeof(int), compare);

        score += diff;
        printf("%d\n", score);

        n--;
    }


    free(cards);
    return 0;
}
