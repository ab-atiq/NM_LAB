#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x -4* x - 10;
}

void secant_method(double x0, double x1, double e) {
    double x2;
    while (true) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
        if (abs(f(x2)) < e)
            break;
    }
    cout << "The value of root is : " << x2 << endl;
}

int main() {
    double x0, x1, e;
    cout << "Enter the value of x0, x1 and e: ";
    cin >> x0 >> x1 >> e;
    secant_method(x0, x1, e);
    return 0;
}