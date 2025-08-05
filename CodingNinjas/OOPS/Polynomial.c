#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial {
    int capacity;
    int degree;
    int* degCoeff;
} Polynomial;

void init(Polynomial* poly) {
    poly->degCoeff = calloc(5, sizeof(int));
    poly->capacity = 5;
    poly->degree = 0;
}

void initCoeff(Polynomial* poly, int* degCoeff, int capacity, int degree) {
    poly->degCoeff = calloc(capacity, sizeof(int));
    poly->degree = degree;
    for (int i = 0; i <= degree; i++) {
        poly->degCoeff[i] = degCoeff[i];
    }
    poly->capacity = capacity;
}

void initCopy(Polynomial* poly, Polynomial* other) {
    poly->degCoeff = calloc(other->capacity, sizeof(int));
    for (int i = 0; i <= other->degree; i++) {
        poly->degCoeff[i] = other->degCoeff[i];
    }
    poly->capacity = other->capacity;
    poly->degree = other->degree;
}

void destroy(Polynomial* poly) {
    free(poly->degCoeff);
    poly->degCoeff = NULL;
    poly->capacity = 0;
    poly->degree = 0;
}

void setCoefficient(Polynomial* poly, int degree, int coefficient) {
    poly->degree = degree;
    if (degree == poly->capacity) {
        int* newDegCoeff = calloc(poly->capacity * 2, sizeof(int));
        for (int i = 0; i < poly->capacity; i++) {
            newDegCoeff[i] = poly->degCoeff[i];
        }
        poly->capacity *= 2;
        free(poly->degCoeff);
        poly->degCoeff = newDegCoeff;
    }
    poly->degCoeff[degree] = coefficient;
}

Polynomial add(Polynomial* poly, Polynomial* other) {
    int maxCapacity = poly->capacity > other->capacity ? poly->capacity : other->capacity;
    int maxDegree = poly->degree > other->degree ? poly->degree : other->degree;
    int* degCoeffNew = calloc(maxCapacity, sizeof(int));
    for (int i = 0; i <= poly->degree; i++) {
        degCoeffNew[i] = poly->degCoeff[i];
    }
    for (int i = 0; i <= other->degree; i++) {
        degCoeffNew[i] += other->degCoeff[i];
    }
    Polynomial result;
    initCoeff(&result, degCoeffNew, maxCapacity, maxDegree);
    return result;
}

Polynomial subtract(Polynomial* poly, Polynomial* other) {
    int maxCapacity = poly->capacity > other->capacity ? poly->capacity : other->capacity;
    int maxDegree = poly->degree > other->degree ? poly->degree : other->degree;
    int* degCoeffNew = calloc(maxCapacity, sizeof(int));
    for (int i = 0; i <= poly->degree; i++) {
        degCoeffNew[i] = poly->degCoeff[i];
    }
    for (int i = 0; i <= other->degree; i++) {
        degCoeffNew[i] -= other->degCoeff[i];
    }
    Polynomial result;
    initCoeff(&result, degCoeffNew, maxCapacity, maxDegree);
    return result;
}

void print(Polynomial* poly) {
    for (int i = 0; i <= poly->degree; i++) {
        if (poly->degCoeff[i] != 0) {
            printf("%dx%d ", poly->degCoeff[i]);
        }
    }
}
