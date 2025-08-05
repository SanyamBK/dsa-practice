#include <stdio.h>
#include <stdlib.h>

// Declare a heap structure
struct Heap {
	long long* arr;
	int size;
	int capacity;
};

// define the struct Heap name
typedef struct Heap heap;

void heapify(heap* h, int index);


// Defining insertHelper function
void insertHelper(heap* h, int index)
{

	// Store parent of element at index
	// in parent variable
	int parent = (index - 1) / 2;

	if (h->arr[parent] > h->arr[index]) {
		// Swapping when child is smaller
		// than parent element
		long long temp = h->arr[parent];
		h->arr[parent] = h->arr[index];
		h->arr[index] = temp;

		// Recursively calling insertHelper
		insertHelper(h, parent);
	}
}

void heapify(heap* h, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = index;

	// Checking whether our left or child element
	// is at right index or not to avoid index error
	if (left >= h->size || left < 0)
		left = -1;
	if (right >= h->size || right < 0)
		right = -1;

	// store left or right element in min if
	// any of these is smaller that its parent
	if (left != -1 && h->arr[left] < h->arr[index])
		min = left;
	if (right != -1 && h->arr[right] < h->arr[min])
		min = right;

	// Swapping the nodes
	if (min != index) {
		long long temp = h->arr[min];
		h->arr[min] = h->arr[index];
		h->arr[index] = temp;

		// recursively calling for their child elements
		// to maintain min heap
		heapify(h, min);
	}
}

int extractMin(heap* h)
{
	long long deleteItem;

	// Store the node in deleteItem that
	// is to be deleted.
	deleteItem = h->arr[0];

	// Replace the deleted node with the last node
	h->arr[0] = h->arr[h->size - 1];
	// Decrement the size of heap
	h->size--;

	// Call minheapify_top_down for 0th index
	// to maintain the heap property
	heapify(h, 0);
	return deleteItem;
}

// Define a insert function
void insert(heap* h, long long data)
{

	// Checking if heap is full or not
	if (h->size < h->capacity) {
		// Inserting data into an array
		h->arr[h->size] = data;
		// Calling insertHelper function
		insertHelper(h, h->size);
		// Incrementing size of array
		h->size++;
	}
}




int main()
{

	
    int n, q;
    scanf("%d %d", &n, &q);
    
    long long* hostility = (long long*)malloc(n * sizeof(long long));
    long long* humour = (long long*)malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &hostility[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lld", &humour[i]);
    }

 
	heap* hp = (heap*)malloc(sizeof(heap));

	// Checking if memory is allocated to h or not
	// set the values to size and capacity
	hp->size = 0;
	hp->capacity = n * n;

	// Allocating memory to array
	hp->arr = (long long*)malloc(hp->capacity * sizeof(long long));

	// Checking if memory is allocated to h or not
    int queries[q];
    int maxQ = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i]);
        if (maxQ < queries[i])
            maxQ = queries[i];
    }

    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long sum =  hostility[i] + humour[j];
            insert(hp, sum);
        }
    }

    free(hostility);
    free(humour);
    
    long long sums[maxQ];

    int idx = 0;
    while (hp->size > 0) {
        int min = extractMin(hp);
        sums[idx++] = min;
        if (idx >= maxQ)
            break;
    }

    for (int i = 0; i < q; i++) {
        int query = queries[i];
        printf("%lld\n", sums[query-1]);
    }

    free(hostility);
    free(humour);
    free(hp->arr);
    free(hp);


	return 0;
}
