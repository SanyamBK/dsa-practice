#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

typedef struct MinHNode {
  char item;
  unsigned freq;
  struct MinHNode *left, *right;
} MinHNode;

typedef struct MinHeap {
  unsigned size;
  unsigned capacity;
  MinHNode **array;
} MinHeap;

// Create nodes
MinHNode *newNode(char item, unsigned freq) {
  MinHNode *temp = (MinHNode *)malloc(sizeof(MinHNode));

  temp->left = temp->right = NULL;
  temp->item = item;
  temp->freq = freq;

  return temp;
}

// Create min heap
MinHeap *createMinH(unsigned capacity) {
  MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));

  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (MinHNode **)malloc(minHeap->capacity * sizeof(MinHNode *));

  return minHeap;
}

// Function to swap
void swapMinHNode(MinHNode **a, MinHNode **b) {
  MinHNode *t = *a;
  *a = *b;
  *b = t;
}

// Heapify
void minHeapify(MinHeap *minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

// Check if size is 1
int checkSizeOne(MinHeap *minHeap) {
  return (minHeap->size == 1);
}

// Extract min
MinHNode *extractMin(MinHeap *minHeap) {
  MinHNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}

// Insertion function
void insertMinHeap(MinHeap *minHeap, MinHNode *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap *minHeap) {
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

int isLeaf(MinHNode *root) {
  return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(char item[], int freq[], int size) {
  MinHeap *minHeap = createMinH(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

void printCodes(MinHNode *root, int arr[], int top) {
  if (isLeaf(root)) {
    for (int i = 0; i < top; i++) {
      printf("%d", arr[i]);
    }
    printf(" - %c\n", root->item);
  }

  if (root->left) {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }

  if (root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }
}


MinHNode *buildHuffmanTree(char item[], int freq[], int size) {
  MinHNode *left, *right, *top;
  MinHeap *minHeap = createAndBuildMinHeap(item, freq, size);

  while (!checkSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }

  return extractMin(minHeap);
}


void HuffmanCodes(char item[], int freq[], int size) {
  MinHNode *root = buildHuffmanTree(item, freq, size);
  int arr[MAX_TREE_HT], top = 0;
  printCodes(root, arr, top);
}

int main() {
  char item[20];
  scanf("%s", item);
  int size;
  scanf("%d", &size);
  int *freq = (int*) malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    scanf("%d", &freq[i]);
  }

  HuffmanCodes(item, freq, size);

  return 0;
}
