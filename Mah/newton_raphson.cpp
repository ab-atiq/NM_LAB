#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x * x + x - 2;
}

double df(double x) {
    return 3 * x * x + 1;
}

void newton_raphson(double x1, double e) {
    double x2;
    while (true) {
        x2 = x1 - (f(x1) / df(x1));
        x1 = x2;
        if (abs(f(x2)) < e)
            break;
    }
    cout << "The value of root is : " << x2 << endl;
}

int main() {
    double x1, e;
    cout << "Enter the value of x1 and e: ";
    cin >> x1 >> e;
    newton_raphson(x1, e);
    return 0;
}