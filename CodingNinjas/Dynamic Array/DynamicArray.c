#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray {
    int *array;
    int nextIndex;
    int capacity;
} DynamicArray;

void init(DynamicArray *d) {
    d->array = (int *) malloc(5 * sizeof(int));
    d->nextIndex = 0;
    d->capacity = 5;
}

void copy(DynamicArray *dest, const DynamicArray *src) {
    dest->array = (int *) malloc(src->capacity * sizeof(int));
    for (int i = 0; i < src->nextIndex; i++) {
        dest->array[i] = src->array[i];
    }
    dest->nextIndex = src->nextIndex;
    dest->capacity = src->capacity;
}

void append(DynamicArray *d, int element) {
    if (d->nextIndex == d->capacity) {
        int *newArray = (int *) malloc(2 * d->capacity * sizeof(int));
        for (int i = 0; i < d->capacity; i++) {
            newArray[i] = d->array[i];
        }
        d->capacity *= 2;
        free(d->array);
        d->array = newArray;
    }
    d->array[d->nextIndex] = element;
    d->nextIndex++;
}

void get(const DynamicArray *d, int i) {
    if (i > d->capacity) {
        printf("Out of Limit!!!\n");
        return;
    }
    else if (i > d->nextIndex) {
        printf("Out of Index!!\n");
        return;
    }
    printf("%d\n", d->array[i]);
}

void insert(DynamicArray *d, int index, int element) {
    if (index == d->nextIndex) 
        append(d, element);
    else if (index < d->nextIndex) {
        if (d->nextIndex < d->capacity) {
            for (int i = d->nextIndex + 1; i > index; i--) {
                d->array[i] = d->array[i-1];
            }
            d->nextIndex ++;
        }
        else {
            append(d, d->array[d->nextIndex]);
            for (int i = d->nextIndex - 2; i > index; i--) {
                d->array[i] = d->array[i-1];
            }
        }
        d->array[index] = element;
    }
    else 
        d->array[index] = element;
}

int search(const DynamicArray *d, int element) {
    for (int i = 0; i < d->nextIndex; i++) {
        if (d->array[i] == element)
            return i;
    }
    return -1;
}

void deleteFstOccur(DynamicArray *d, int element) {
    int index = search(d, element);
    for(int i = index; i < d->nextIndex - 1; i++) {
        d->array[i] = d->array[i+1];
    }
    d->nextIndex--;
}

void deleteAllOccur(DynamicArray *d, int element) {
    int i = 0; 
    while (i < d->nextIndex) {
        if (d->array[i] == element); {
            for(int j = i; i < d->nextIndex - 1; j++) {
                d->array[j] = d->array[j+1];
            }
            d->nextIndex--;
        }
    }
}

int pop(DynamicArray *d, int index) {
    int element = d->array[index];
    for(int i = index; i < d->nextIndex - 1; i++) {
        d->array[i] = d->array[i+1];
    }
    d->nextIndex--;
    return element;
} 

void printArray(const DynamicArray *d) {
    for (int i = 0; i < d->nextIndex; i++) {
        printf("%d ", d->array[i]);
    }
    printf("\n");
}

void capacity(const DynamicArray *d) {
    printf("%d", d->capacity);
} 

void printIndex(const DynamicArray *d) {
    printf("%d", d->nextIndex);
} 
