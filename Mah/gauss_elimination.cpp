#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Number of equations:" << endl;
    cin >> n;
    double matrix[n][n + 1], ans[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the coefficients of equation " << i + 1 << " and the constant term:" << endl;
        for (int j = 0; j < n + 1; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < n + 1; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        ans[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            ans[i] -= matrix[i][j] * ans[j];
        }
        ans[i] /= matrix[i][i];
    }

    cout << "The solution is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << ans[i] << endl;
    }
    return 0;
}