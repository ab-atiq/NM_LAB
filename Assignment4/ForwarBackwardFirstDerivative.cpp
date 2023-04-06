#include <bits/stdc++.h>
using namespace std;
#define S 20
double Y[S][S];

double ForwardValue(int n, int idx)
{
    double sum = 0;
    for (int i = 1; i < n - idx; i++)
    {
        double temp = Y[0 + idx][i + 1] / i;
        if (i % 2 == 0)
        {
            temp *= -1;
        }
        sum += temp;
    }
    return sum;
}

double BackwardValue(int n, int idx)
{
    double sum = 0;
    int col = 2;
    for (int i = idx - 1; i >= 0; i--)
    {
        sum += Y[i][col] / (col - 1);
        col++;
    }
    return sum;
}

int main()
{
    double x;
    int n, x_idx = -1;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Enter values of x for where want to find y: ";
    cin >> x;

    cout << "Enter values of x and F(x):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> Y[i][0];
        cout << "F(x[" << i << "]) = ";
        cin >> Y[i][1];
        if (Y[i][0] == x)
        {
            x_idx = i;
        }
    }

    for (int j = 2; j < n + 1; j++)
    {
        for (int i = 0; i < n - j + 1; i++)
        {
            Y[i][j] = (Y[i + 1][j - 1] - Y[i][j - 1]);
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << "The difference table is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << setw(10) << Y[i][j];
        }
        cout << endl;
    }

    double h = Y[1][0] - Y[0][0];
    double result;
    if (x_idx < n / 2)
    {
        result = ForwardValue(n, x_idx);
    }
    else
    {
        result = BackwardValue(n, x_idx);
    }
    result /= h;

    cout << "The First derivative of tabulated value on " << x << " of is: " << result << endl;
    return 0;
}
Integration (Trapezoid, Simpson’s One-Third Rule, Simpson’s Three-Eight Rule) 