#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

double table[10][10];

int main() {
    double x;
    int n;
    cout << "Enter no.of terms:" << endl;
    cin >> n;
    cout << "Enter values of x for which find y:" << endl;
    cin >> x;
    cout << "Enter values of X:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> table[i][0];
    }
    cout << "Enter values of f(x):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> table[i][1];
    }

    for (int j = 2; j < n + 1; j++) {
        for (int i = 0; i < n - j + 1; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]);
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << "The difference table is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            cout << setw(7) << table[i][j];
        }
        cout << endl;
    }

    // newton forward formula
    double h = table[1][0] - table[0][0];
    double u = (x - table[0][0]) / h;
    double ans = table[0][1];
    for (int i = 1; i < n; i++) {
        double temp = table[0][i + 1];
        for (int j = 0; j < i; j++) {
            temp = temp * (u - j);
        }
        temp = temp / factorial(i);
        ans += temp;
    }

    cout << "The value of f(" << x << ") is: " << ans << endl;
    return 0;
}
