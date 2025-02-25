#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber {
public:
    double real;
    double imag;

    ComplexNumber(double x = 0, double y = 0) {
        real = x;
        imag = y;
    }

    ComplexNumber operator+(const ComplexNumber &c) {
        return ComplexNumber(real + c.real, imag + c.imag);
    }

    ComplexNumber operator-(const ComplexNumber &c) {
        return ComplexNumber(real - c.real, imag - c.imag);
    }

    ComplexNumber operator*(const ComplexNumber &c) {
        return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    ComplexNumber operator/(const ComplexNumber &c) {
        double denominator = c.real * c.real + c.imag * c.imag;
        return ComplexNumber((real * c.real + imag * c.imag) / denominator,
                             (imag * c.real - real * c.imag) / denominator);
    }

    bool operator==(const ComplexNumber &c) {
        return (real == c.real && imag == c.imag);
    }

    double abs() {
        return sqrt(real * real + imag * imag);
    }

    double angle() {
        return atan2(imag, real) * (180.0 / M_PI);
    }

    friend ostream &operator<<(ostream &os, const ComplexNumber &c) {
        if (c.real == 0 && c.imag == 0) {
            os << "0";
        } else if (c.real == 0) {
            os << c.imag << "i";
        } else if (c.imag == 0) {
            os << c.real;
        } else {
            os << c.real << (c.imag > 0 ? "+" : "") << c.imag << "i";
        }
        return os;
    }

    ComplexNumber operator+(double d) {
        return ComplexNumber(real + d, imag);
    }

    ComplexNumber operator-(double d) {
        return ComplexNumber(real - d, imag);
    }

    friend ComplexNumber operator+(double d, const ComplexNumber &c) {
        return ComplexNumber(d + c.real, c.imag);
    }

    friend ComplexNumber operator-(double d, const ComplexNumber &c) {
        return ComplexNumber(d - c.real, -c.imag);
    }

    friend ComplexNumber operator*(double d, const ComplexNumber &c) {
        return ComplexNumber(d * c.real, d * c.imag);
    }

    friend ComplexNumber operator/(double d, const ComplexNumber &c) {
        double denominator = c.real * c.real + c.imag * c.imag;
        return ComplexNumber((d * c.real) / denominator, (-d * c.imag) / denominator);
    }

    friend bool operator==(double d, const ComplexNumber &c) {
        return (c.real == d && c.imag == 0);
    }
};


int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}