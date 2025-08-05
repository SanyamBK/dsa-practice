#include <stdio.h>
#include <stdlib.h>

struct Heap {
    long long* arr;
    int size;
    int capacity;
};

typedef struct Heap heap;

void minHeapify(heap* h, int index);
void maxHeapify(heap* h, int index);

heap* createMinHeap(int capacity, long long* nums)
{
    heap* h = (heap*)malloc(sizeof(heap));
    if (h == NULL) {
        printf("Memory error");
        return NULL;
    }
    h->size = 0;
    h->capacity = capacity;
    h->arr = (long long*)malloc(capacity * sizeof(long long));
    if (h->arr == NULL) {
        printf("Memory error");
        return NULL;
    }
    int i;
    for (i = 0; i < capacity; i++) {
        h->arr[i] = nums[i];
    }
    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0) {
        minHeapify(h, i);
        i--;
    }
    return h;
}

void insertMinHelper(heap* h, int index)
{
    int parent = (index - 1) / 2;
    if (h->arr[parent] > h->arr[index]) {
        long long temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;
        insertMinHelper(h, parent);
    }
}

void minHeapify(heap* h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = index;
    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;
    if (left != -1 && h->arr[left] < h->arr[index])
        min = left;
    if (right != -1 && h->arr[right] < h->arr[min])
        min = right;
    if (min != index) {
        long long temp = h->arr[min];
        h->arr[min] = h->arr[index];
        h->arr[index] = temp;
        minHeapify(h, min);
    }
}

long long extractMin(heap* h)
{
    long long deleteItem;
    if (h->size == 0) {
        printf("\nHeap is empty.");
        return -999;
    }
    deleteItem = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    minHeapify(h, 0);
    return deleteItem;
}

void insertMin(heap* h, long long data)
{
    if (h->size < h->capacity) {
        h->arr[h->size] = data;
        insertMinHelper(h, h->size);
        h->size++;
    }
}

void printHeap(heap* h)
{
    for (int i = 0; i < h->size; i++) {
        printf("%lld ", h->arr[i]);
    }
    printf("\n");
}

heap* createMaxHeap(int capacity, long long* nums)
{
    heap* h = (heap*)malloc(sizeof(heap));
    if (h == NULL) {
        printf("Memory error");
        return NULL;
    }
    h->size = 0;
    h->capacity = capacity;
    h->arr = (long long*)malloc(capacity * sizeof(long long));
    if (h->arr == NULL) {
        printf("Memory error");
        return NULL;
    }
    int i;
    for (i = 0; i < capacity; i++) {
        h->arr[i] = nums[i];
    }
    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0) {
        maxHeapify(h, i);
        i--;
    }
    return h;
}

void insertMaxHelper(heap* h, int index)
{
    int parent = (index - 1) / 2;
    if (h->arr[parent] < h->arr[index]) {
        long long temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;
        insertMaxHelper(h, parent);
    }
}

void maxHeapify(heap* h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int max = index;
    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;
    if (left != -1 && h->arr[left] > h->arr[index])
        max = left;
    if (right != -1 && h->arr[right] > h->arr[max])
        max = right;
    if (max != index) {
        long long temp = h->arr[max];
        h->arr[max] = h->arr[index];
        h->arr[index] = temp;
        maxHeapify(h, max);
    }
}

long long extractMax(heap* h)
{
    long long deleteItem;
    if (h->size == 0) {
        printf("\nHeap is empty.");
        return -999;
    }
    deleteItem = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    maxHeapify(h, 0);
    return deleteItem;
}

void insertMax(heap* h, long long data)
{
    if (h->size < h->capacity) {
        h->arr[h->size] = data;
        insertMaxHelper(h, h->size);
        h->size++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    long long *cards = malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cards[i]);
    }
    long long score = 0;
    for (int i = 0; i < n; i++) {
        score += cards[i];
    }
    heap *minheap = createMinHeap(n, cards);
    heap *maxheap = createMaxHeap(n, cards);

    while (n >= 2) {
        long long smallest = extractMin(minheap);
        long long largest = extractMax(maxheap);
        score = score - smallest - largest;
        long long diff = abs(largest - smallest);

        insertMin(minheap, diff);
        insertMax(maxheap, diff);

        score += diff;
        printf("%lld\n", score);

        n--;
    }

    return 0;
}
