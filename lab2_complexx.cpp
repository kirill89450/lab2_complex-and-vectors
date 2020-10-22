
#include <math.h>
#include <iostream>
using namespace std;

class Complex {
    friend ostream& operator<<(ostream& out, const Complex& s);
    friend double mod(Complex& mod);
private:
    double x;
    double y;
    double m;
public:
    Complex() {
        x = 0;
        y = 0;
        m = 0;
    }
    Complex(int a, int b) {
        x = a;
        y = b;
    }

    Complex operator +(const Complex& other) {
        Complex temp;
        temp.x = this->x + other.x;
        temp.y = this->y + other.y;
        return temp;
    }
    Complex operator *(const Complex& other) {
        Complex temp;
        temp.x = (this->x * other.x) - (this->y * other.y);
        temp.y = (this->x * other.y) + (this->y * other.x);
        return temp;
    }
    bool operator ==(const Complex& other) {
        return this->x == other.x && this->y == other.y;
    }
    bool operator !=(const Complex& other) {
        return this->x == other.x && this->y == other.y;
    }
    bool operator >(const Complex& other) {
        return this->x > other.x && this->y > other.y;
    }
    bool operator <(const Complex& other) {
        return this->x < other.x&& this->y < other.y;
    }
};
ostream& operator<<(ostream& out, const Complex& s) {
    out << s.x << "+" << s.y << "i";
    return out;
}
double mod(Complex& mod) {
    mod.m = sqrt(pow(mod.x, 2) + pow(mod.y, 2));
    return mod.m;
}


int main()
{
    Complex z(3, 5);
    cout << z;
    cout << endl;
    Complex z1(3, 5);
    cout << z1;
    cout << endl;
    Complex sum;
    sum = z + z1;
    cout << sum;
    cout << endl;
    Complex mult;
    mult = z * z1;
    cout << mult;
    cout << endl;
    mod(z);
    mod(z1);
    bool result1 = mod(z) == mod(z1);
    cout << "z==z1 " << result1;
    cout << endl;
    bool result2 = mod(z) != mod(z1);
    cout << "z!=z1 " << result2;
    cout << endl;
    bool result3 = mod(z) > mod(z1);
    cout << "z>z1 " << result3;
    cout << endl;
    bool result4 = mod(z) < mod(z1);
    cout << "z<z1 " << result4;
    cout << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

