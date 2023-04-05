#include<bits/stdc++.h>

using namespace std;

int main() {
    float x;
    int i, j, n;
    cout << "Enter no.of terms:" << endl;
    cin >> n;
    float table[n][n + 1];
    cout << "Enter values of X:" << endl;
    for (i = 0; i < n; i++) {
        cin >> table[i][0];
    }
    cout << "Enter values of f(x):" << endl;
    for (i = 0; i < n; i++) {
        cin >> table[i][1];
    }
    cout << "Enter values of x for which find y:" << endl;
    cin >> x;

    for (j = 2; j < n + 1; j++) {
        for (i = 0; i < n - j + 1; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (table[j + i - 1][0] - table[i][0]);
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << "The difference table is: " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i + 1; j++) {
            cout << setw(7) << table[i][j];
        }
        cout << endl;
    }

    float fx = table[0][1];
    for (i = 1; i < n; i++) {
        float temp = table[0][i + 1];
        for (j = 0; j < i; j++) {
            temp = temp * (x - table[j][0]);
        }
        fx = fx + temp;
    }
    cout << "f(x) = " << fx << endl;
    return 0;
}