#include <bits/stdc++.h>
using namespace std;
#define S 20

void forward(float x[S], float y[S][S], int n, float xp)
{
    float a = xp; // interpolation point
    float h, u, sum, p;
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1]; // difference table
        }
    }
    cout << "\nThe forward difference table is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%f\t", y[i][j]);
        }
        cout << endl;
    }

    // f(a+hu)=f0 + u*Δf0 + u(u-1) Δ^2f0/2! + u(u-1)(u-2)Δ^3f0/3!

    p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[0]) / h;
    for (int j = 1; j < n; j++)
    {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
    }
    cout << "\nThe value of y at x= " << a << " is: " << sum;
}

void BackWard(float x[S], float y[S][S], int n, float xp)
{
    float a = xp; // interpolation point
    float h, u, sum, p;
    for (int j = 1; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    cout << "\nThe backward difference table is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%f\t", y[i][j]);
        }
        cout << endl;
    }

    p = 1.0;
    sum = y[n - 1][0];
    h = x[1] - x[0];
    u = (a - x[n - 1]) / h;
    for (int j = 1; j < n; j++)
    {
        p = p * (u + j - 1) / j;
        sum = sum + p * y[n - 1][j];
    }

    cout << "\nThe value of y at x= " << a << " is: " << sum;
}

int main()
{
    float x[S], y[S][S];
    int n, xp;
    cout << "Enter number of arguments: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }

    cout << "Enter interpolation point: ";
    cin >> xp;

    // here,Work Forwar if interpolation point is less than middle point of given x data. else work on backward
    if ((x[0] + x[n - 1]) / 2 > xp)
    {
        forward(x, y, n, xp);
    }
    else
    {
        BackWard(x, y, n, xp);
    }

    return 0;
}
