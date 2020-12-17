#include <iostream>
#include <ctime>
using namespace std;

int random(int min, int max) {
    return min + rand() % ((max + 1) - min);
}

class Vector {
    int poryadok;

public:
    double* digits;
    Vector() {
        this->poryadok = 0;
        this->digits = new double[0];
    }

    Vector(int por) {
        this->poryadok = por;
        this->digits = new double[por];
    }

    void print() {
        for (int i = 0; i < poryadok; i++) {
            cout << digits[i] << " ";
        }
        cout << endl;
    }

    void setPor(int s) {
        double* newArray = new double[s];
        for (int i = 0; i < s && i < poryadok; i++) {
            newArray[i] = digits[i];
        }
        poryadok = s;
        digits = newArray;
    }

    double& operator[] (int index) {
        return (digits[index]);
    }

    Vector& operator= (Vector* v) {
        this->digits = v->digits;
        this->poryadok = v->poryadok;
        return *this;
    }

    double operator* (double* v) {
        double summ = 0;
        for (int i = 0; i < poryadok; i++) {
            summ += this->digits[i] * v[i];
        }
        return summ;
    }
};

int main()
{
    srand(time(0));
    Vector x = Vector();
    x.setPor(3);
    Vector y = Vector(3);

    for (int i = 0; i < 3; i++) {
        x[i] = random(-10, 10);
        y[i] = random(-10, 10);
    }
    cout << "Vector X: ";
    x.print();

    cout << "Vector Y: ";
    y.print();

    double scalProizv = x * y.digits;
    cout << "X * Y = " << scalProizv << endl;
}