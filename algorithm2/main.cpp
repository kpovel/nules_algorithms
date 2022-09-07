#include <iostream>
#include <cmath>

using namespace std;

int fact(int n) {
    if (n < 2) return 1;
    return n * fact(n - 1);
}

double recursionCos(double x, int n = 0, double precision = 1e-4) {
    double a = pow(-1, n) * pow(x, 2 * n) / fact(2 * n);
    if (abs(a) < precision) return a;
    return a + recursionCos(x, n + 1, precision);
}

double cycleCos(double x, int n = 0, double precision = 1e-4) {
    double a = 0, b;
    while(true) {
        b = pow(-1, n) * pow(x, 2 * n) / fact(2 * n);
        a = a + b;
        if (abs(b) < precision) break;
        n++;
    }
    return a;
}

int main() {
    double x;
    cout << "Enter x ";
    cin >> x;
    double radians = x * M_PI / 180;

    double myRecursionCos = recursionCos(radians / 2) / recursionCos(radians + M_PI / 2);
    double myCycleCos = cycleCos(radians / 2) / cycleCos(radians + M_PI / 2);
    double libraryCos = cos(radians / 2) / cos(radians + M_PI / 2);


    cout << "My recursion cos " << myRecursionCos << "\n";
    cout << "My cycle cos " << myCycleCos << "\n";
    cout << "Library cos " << libraryCos << "\n";

    return 0;
}