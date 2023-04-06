#include <bits/stdc++.h>

using namespace std;

double table[20][20];

double forward_value(int n, int index) {
    double ans = 0;
    for (int i = 1; i < n - index; i++) {
        double temp = table[0 + index][i + 1] / i;
        if (i % 2 == 0) {
            temp *= -1;
        }
        ans += temp;
    }
    return ans;
}

double backward_value(int n, int index) {
    double ans = 0;
    int col = 2;
    for (int i = index - 1; i >= 0; i--) {
        ans += table[i][col] / (col - 1);
        col++;
    }
    return ans;
}

int main() {
    double x;
    int n, x_index = -1;
    cout << "Enter no.of terms:" << endl;
    cin >> n;
    cout << "Enter values of x for which find y:" << endl;
    cin >> x;
    cout << "Enter values of X:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> table[i][0];
        if (table[i][0] == x) {
            x_index = i;
        }
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

    double h = table[1][0] - table[0][0];
    double ans;
    if (x_index < n / 2) {
        ans = forward_value(n, x_index);
    } else {
        ans = backward_value(n, x_index);
    }
    ans /= h;

    cout << "The First derivative of tabulated value on " << x << "of is: " << ans << endl;
    return 0;
}
