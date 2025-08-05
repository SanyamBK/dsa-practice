#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int paintings;
    int boredom;
} Gallery;


void processTestCase(int n, int k, Gallery* galleries) {
    int totalPaintingsLeft = 0;
    int totalBoredom = 0;

    for (int day = 0; day < k; day++) {
        int maxPaintings = 0;
        int minBoredom = INT_MAX;
        int chosenGallery = -1;

        for (int i = 0; i < n; i++) {
            if (galleries[i].paintings == 0) continue;

            int paintingsToday = ceil(galleries[i].paintings / 2.0);

            if (paintingsToday > maxPaintings || (paintingsToday == maxPaintings && galleries[i].boredom < minBoredom)) {
                maxPaintings = paintingsToday;
                minBoredom = galleries[i].boredom;
                chosenGallery = i;
            }
        }

        if (chosenGallery == -1) break;

        galleries[chosenGallery].paintings -= maxPaintings;
        totalBoredom += maxPaintings * galleries[chosenGallery].boredom;
    }

    for (int i = 0; i < n; i++) {
        totalPaintingsLeft += galleries[i].paintings;
    }

    printf("%d %d\n", totalPaintingsLeft, totalBoredom);
}

void testCase() {
    int n, k;
    scanf("%d %d", &n, &k);

    Gallery* galleries = (Gallery*)malloc(n * sizeof(Gallery));
    for (int i = 0; i < n; i++) {
        scanf("%d", &galleries[i].paintings);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &galleries[i].boredom);
    }

    processTestCase(n, k, galleries);

    free(galleries);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        testCase();
    }

    return 0;
}
