#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data;
    int size;
} Heap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapUp(Heap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->data[parent] > heap->data[index]) {
            swap(&heap->data[parent], &heap->data[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapDown(Heap *heap, int index) {
    while (1) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int smallest = index;

        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }

        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(&heap->data[smallest], &heap->data[index]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insert(Heap *heap, int value) {
    heap->data[heap->size] = value;
    heapUp(heap, heap->size);
    heap->size++;
}

int delete(Heap *heap) {
    int result = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapDown(heap, 0);
    return result;
}

int canAccommodate(int N, int tu, int ti[], int k) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)calloc(k, sizeof(int));
    heap->size = 0;

    for (int i = 0; i < k; i++) {
        insert(heap, ti[i]);
    }

    for (int i = k; i < N; i++) {
        int t = delete(heap);
        if (t > tu)
            return 0;
        insert(heap, t + ti[i]);
    }

    while (heap->size > 0) {
        int t = delete(heap);
        if (t > tu)
            return 0;
    }

    free(heap->data);
    free(heap);

    return 1;
}


int findInfimumK(int n, int tu, int *ti) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canAccommodate(n, tu, ti, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}



int main() {
    int n, tu;
    scanf("%d %d", &n, &tu);

    int *ti = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &ti[i]);
    }

    int ans = findInfimumK(n, tu, ti);

    printf("%d\n", ans);

    free(ti);

    return 0;
}
