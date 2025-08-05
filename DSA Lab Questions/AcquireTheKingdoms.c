#include <stdio.h>
#include <stdlib.h>

typedef struct City {
    int city;
    int soldier;
} City;

typedef struct Connection{
    int from;
    int to;
} Connection;

int compareCity(const void *a, const void *b) {
    City *cityA = (City *)a;
    City *cityB = (City *)b;
    return cityA->city - cityB->city;
}

int compareConnection(const void *a, const void *b) {
    Connection *connA = (Connection *)a;
    Connection *connB = (Connection *)b;
    return connA->from - connB->from;
}

int countConqueredKingdoms(int N, int K, int soldierDeployments[], Connection connections[]) {
    City cities[N];
    int conqueredKingdoms = 0;

    for (int i = 0; i < N; i++) {
        cities[i].city = i + 1;
        cities[i].soldier = soldierDeployments[i];
    }

    qsort(cities, N, sizeof(City), compareCity);
    qsort(connections, N - 1, sizeof(Connection), compareConnection);

    int maxConsecutiveSoldiers = 0;
    int consecutiveSoldiers = 0;

    for (int i = 0; i < N; i++) {
        if (cities[i].soldier == 1) {
            consecutiveSoldiers++;
        } else {
            maxConsecutiveSoldiers = (consecutiveSoldiers > maxConsecutiveSoldiers) ? consecutiveSoldiers : maxConsecutiveSoldiers;
            consecutiveSoldiers = 0;
        }
    }

    maxConsecutiveSoldiers = (consecutiveSoldiers > maxConsecutiveSoldiers) ? consecutiveSoldiers : maxConsecutiveSoldiers;

    if (maxConsecutiveSoldiers >= K) {
        conqueredKingdoms = 1;
    } else {
        int i = 0;
        while (i < N) {
            int j = i;
            while (j < N && cities[j].soldier == 1) {
                j++;
            }
            int numCities = j - i;

            conqueredKingdoms += numCities / K;
            i = j + 1;
        }
    }

    return conqueredKingdoms;
}

int main() {
    int N; 
    int K; 

    scanf("%d %d", &N, &K);

    int soldierDeployments[N];
    Connection connections[N - 1];

    for (int i = 0; i < N; i++) {
        scanf("%d", &soldierDeployments[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &connections[i].from, &connections[i].to);
    }

    int result = countConqueredKingdoms(N, K, soldierDeployments, connections);
    
    printf("%d\n", result);

    return 0;
}
