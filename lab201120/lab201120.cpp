#include <iostream>
#include <ctime>
using namespace std;

int random(int min, int max) {
    return min + rand() % ((max + 1) - min);
}

class Vector {
    double* array;
    int size;

public:
    Vector() {
        this->size = 0;
        this->array = new double[0];
    }

    Vector(int size) {
        this->size = size;
        this->array = new double[size];
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void setSize(int s) {
        double* newArray = new double[s];
        for (int i = 0; i < s && i < size; i++) {
            newArray[i] = array[i];
        }
        size = s;
        array = newArray;
    }

    double& operator [] (int index) {
        return (array[index]);
    }

    Vector& operator = (Vector* v) {
        this->array = v->array;
        this->size = v->size;
        return *this;
    }

    Vector operator + (Vector x) {
        Vector y = Vector(size);
        for (int i = 0; i < size; i++) {
            y.array[i] = this->array[i] + x[i];
        }
        return y;
    }
};

int main()
{
    srand(time(0));
    Vector x = Vector();
    x.setSize(3);
    Vector y = Vector(3);

    for (int i = 0; i < 3; i++) {
        x[i] = random(-10, 10);
        y[i] = random(-10, 10);
    }
    cout << "Vector X: ";
    x.print();

    cout << "Vector Y: ";
    y.print();

    Vector summ = x + y;
    cout << "Vector X + Y: ";
    summ.print();
}