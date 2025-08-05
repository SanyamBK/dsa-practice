#include <iostream>

class Polynomial {

    int capacity;
    int degree;
    
    public:

    int *degCoeff;

    Polynomial() {
        degCoeff = new int[5]();
        capacity = 5;
        degree = 0;
    }

    Polynomial(int degCoeff[], int capacity, int degree) {
        this -> degCoeff = new int[capacity]();
        this -> degree = degree;
        for (int i = 0; i <= degree; i++) {
            this -> degCoeff[i] = degCoeff[i];
        }
        this -> capacity = capacity;
    }

    Polynomial(Polynomial const &p) {
        this -> degCoeff = new int[p.capacity]();
        for (int i = 0; i <= p.degree; i++) {
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
        this -> degree = p.degree;
    }

    Polynomial operator = (Polynomial const &p) {
        this -> degCoeff = new int[p.capacity]();
        for (int i = 0; i <= p.degree; i++) {
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
        this -> degree = p.degree;
    }


    void setCoefficient(int degree, int coefficient) {
        if (degree > this -> degree)
            this -> degree = degree;
        if (this -> degree >= capacity) {
            int *newdegCoeff = new int[capacity*capacity]();
            for (int i = 0; i < capacity; i++) {
                newdegCoeff[i] = degCoeff[i];
            }
            capacity *= capacity;
            delete [] degCoeff;
            degCoeff = newdegCoeff;
        }
        degCoeff[degree] = coefficient;
    }

    Polynomial operator + (Polynomial const &p) const {
        int maxCapacity = this -> capacity > p.capacity ? this -> capacity : p.capacity;
        int maxDegree = this -> degree > p.degree ? this -> degree : p.degree;
        int *DegCoeffNew = new int[maxCapacity]();
        
        for (int i = 0; i <= this -> degree; i++) 
            DegCoeffNew[i] = this -> degCoeff[i];
        
        for (int i = 0; i <= p.degree; i++) 
            DegCoeffNew[i] += p.degCoeff[i];        

        Polynomial degCoeffNew(DegCoeffNew, maxCapacity, maxDegree);
        return degCoeffNew;
    }

    Polynomial operator - (Polynomial const &p) const {
        int maxCapacity = this -> capacity > p.capacity ? this -> capacity : p.capacity;
        int maxDegree = this -> degree > p.degree ? this -> degree : p.degree;
        int *DegCoeffNew = new int[maxCapacity]();
        for (int i = 0; i <= this -> degree; i++) {
            DegCoeffNew[i] = this -> degCoeff[i];
        }
        for (int i = 0; i <= p.degree; i++) {
            DegCoeffNew[i] -= p.degCoeff[i];
        }

        Polynomial degCoeffNew(DegCoeffNew, maxCapacity, maxDegree);
        return degCoeffNew;
    }

    Polynomial operator * (Polynomial const &p) const {
        int maxCapacity = this -> capacity + p.capacity;
        int maxDegree = this -> degree + p.degree;
        int *DegCoeffNew = new int[maxCapacity]();
        for (int i = 0; i <= this -> degree; i++) {
            for (int j = 0; j <= p.degree; j++) {
                DegCoeffNew[i+j] += this -> degCoeff[i] * p.degCoeff[j];
            }
        }
        Polynomial degCoeffNew(DegCoeffNew, maxCapacity, maxDegree);
        return degCoeffNew;
    }


    void print() {
        for (int i = 0; i <= this -> degree; i++) {
            if (degCoeff[i] != 0) 
                cout << degCoeff[i] << "x" << i << " "; 
        }
        cout << endl;
    }

};