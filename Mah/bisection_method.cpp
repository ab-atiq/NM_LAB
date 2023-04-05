#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x * x + x - 2;
}

void bisection(double x1, double x2, double e) {
    if (f(x1) * f(x2) >= 0) {
        cout << "You have not assumed right a and b";
        return;
    }

    double x0;
    while (true) {
        x0 = (x1 + x2) / 2;
        if (abs(f(x0)) < e)
            break;
        else if (f(x0) * f(x1) < 0)
            x2 = x0;
        else
            x1 = x0;
    }
    cout << "The value of root is : " << x0 << endl;
}

int main() {
    double x1, x2, e;
    cout << "Enter the value of x1, x2 and e: ";
    cin >> x1 >> x2 >> e;
    bisection(x1, x2, e);
    return 0;
}