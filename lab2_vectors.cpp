

#include <iostream>
using namespace std;

class Vector {
private:
    float x;
    float y;
    float w;
    float corner;
public:
    Vector() {
        x = 0;
        y = 0;
        w = 0;
        corner = 0;
    }

    Vector operator +(const Vector& other) {
        Vector temp;
        temp.x = (this->x + other.x);
        temp.y = (this->y + other.y);
        return temp;
    }
    Vector operator *(const Vector& other) {
        Vector temp;
        temp.x = (this->x * other.x);
        temp.y = (this->y * other.y);
        return temp;
    }
    Vector operator%(const Vector& other) {
        Vector temp;
        temp.corner = ((this->x * this->y) + (other.x + other.y)) / (sqrt(pow(this->x, 2) + pow(other.x, 2)) * (sqrt(pow(this->y, 2) + pow(other.y, 2))));
        return temp;
    }
    bool operator ==(const Vector& other) {
        
        return this->x == other.x && this->y == other.y;
    }
    bool operator !=(const Vector& other) {
        return this->x == other.x && this->y == other.y;
    }
    bool operator >(const Vector& other) {
        return this->x > other.x && this->y > other.y;
    }
    bool operator <(const Vector& other) {
        return this->x < other.x&& this->y < other.y;
    }
    ~Vector() {
        cout << "." << endl;
    }
    friend ostream& operator<<(ostream& out, const Vector& s);
    friend istream& operator>>(istream& in, Vector& s);
    friend Vector operator *(const Vector&, int a);
    friend float width(Vector& w);
    friend void input(Vector& s);
    friend void output(const Vector& s);
    friend void output1(const Vector& s1);
    friend void output2(const Vector& s);
};
ostream& operator<<(ostream& out, const Vector& s) {
    out << "(" << s.x << " , " << s.y << ")" << endl;
    return out;
}
istream& operator>>(istream& in, Vector& s) {
    in >> s.x >> s.y;
    return in;
}
Vector operator *(const Vector& m, int a) {
    Vector temp;
    temp.x = m.x * a;
    temp.y = m.y * a;
    return temp;
}

float width(Vector& w) {
    if (w.y > w.x) {
        w.w = w.y - w.x;
    }
    else {
        w.w = w.x - w.y;
    }
    return w.w;
}
void input(Vector& s) {
    cin >> s.x;
    cin >> s.y;
}
//Вывод вектора
/*void output(const Vector& s) {
    cout << "(" << s.x << " , " << s.y << ")" << endl;

}*/
//Вывод пороизведения
void output1(const Vector& s1) {
    float x;
    x = s1.x + s1.y;
    cout << x << endl;
}
//Вывод угла
void output2(const Vector& s) {
    cout << s.corner << endl;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    int x;
    Vector z;
    Vector z1;
    cout << "Введите координаты 1-го вектора: " << endl;
    input(z);
    cout << z;
    cout << "Введите координаты 2-го вектора: " << endl;
    input(z1);
    cout << "Первый вектор равен: " << endl;
    cout << z;
    cout << "Второй вектор равен: " << endl;
    cout << z1;
    Vector sum;
    cout << "Сумма векторов равна: " << endl;
    sum = z + z1;
    cout << sum;
    cout << "Ведите число на кт умножить вектор- ";
    cin >> x;
    cout << "Произведения векторов на число равно: " << endl;
    cout << z * x << endl;
    cout << z1 * x << endl;
    Vector mult;
    cout << "Произведение векторов равно: " << endl;
    mult = z * z1;
    output1(mult);
    cout << "Косинус угла между векторами: " << endl;
    Vector corner;
    corner = z % z1;
    output2(corner);
    cout << "Сравнение векторов: " << endl;
    bool result1 = width(z) == width(z1);
    bool result2 = width(z) != width(z1);
    bool result3 = width(z) > width(z1);
    bool result4 = width(z) < width(z1);
    cout << "Z=Z1: " << result1 << endl;
    cout << "Z!=Z1: " << result2 << endl;
    cout << "Z>Z1: " << result3 << endl;
    cout << "Z<Z1: " << result4 << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
