#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXK 500005

int N, K;
int nums[MAXN];
int heap[MAXN];
int heapSize;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int x) {
    int i = heapSize++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] >= x)
            break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}

int pop() {
    int ret = heap[0];
    int x = heap[--heapSize];
    int i = 0;
    while (i * 2 + 1 < heapSize) {
        int a = i * 2 + 1, b = i * 2 + 2;
        if (b < heapSize && heap[b] > heap[a])
            a = b;
        if (heap[a] <= x)
            break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
        push(nums[i]);
    }
    long long ans = 0;
    for (int i = 0; i < K; i++) {
        if (heapSize == 0)
            break;
        int top = pop();
        ans += top--;
        if (top > 0)
            push(top);
    }
    printf("%lld\n", ans);
    return 0;
}