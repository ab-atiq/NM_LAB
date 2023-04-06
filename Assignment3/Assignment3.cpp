#include <bits/stdc++.h>
using namespace std;
#define SIZE 20

float proterm(int i, float value, float x[])
{
    float pro = 1;
    for (int j = 0; j < i; j++)
    {
        pro = pro * (value - x[j]);
    }
    return pro;
}

float applyFormula(float value, float x[], float y[][SIZE], int n)
{
    float sum = y[0][0];
    // f(value) = a0 + a1(x-x0) + a2(x-x0)(x-x1) + a3(x-x0)(x-x1)(x-x2)
    for (int i = 1; i < n; i++)
    {
        sum = sum + (proterm(i, value, x) * y[0][i]);
    }
    return sum;
}

void dividedDiffTable(float x[], float y[][SIZE], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}

void printDiffTable(float y[][SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << setprecision(4) << y[i][j] << "\t ";
        }
        cout << "\n";
    }
}

int main()
{
    float x[SIZE], y[SIZE], xp, yp = 0, pro;
    int n, chooseOption;
    cout << setprecision(3) << fixed;
    cout << "1. Lagrange Interpolation\n2. Newton Interpolation\nChoose option (1 or 2): ";
    cin >> chooseOption;
    /* Input Section */
    cout << "Enter number of data: ";
    cin >> n;
    switch (chooseOption)
    {
    case 1:
        cout << "Enter data:" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "x[" << i << "] = ";
            cin >> x[i];
            cout << "y[" << i << "] = ";
            cin >> y[i];
        }
        cout << "Enter interpolation point: ";
        cin >> xp;

        /* Implementing Lagrange Interpolation */
        for (int i = 1; i <= n; i++)
        {
            pro = 1;
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    pro = pro * (xp - x[j]) / (x[i] - x[j]);
                }
            }
            yp = yp + pro * y[i];
        }
        cout << endl
             << "Interpolated value at " << xp << " is: " << yp;

        break;
    case 2:
        float value, yy[SIZE][SIZE];
        // Enter value
        for (int i = 0; i < n; i++)
        {
            cout << "x[" << i << "] = ";
            cin >> x[i];
            cout << "y[" << i << "] = ";
            cin >> yy[i][0];
        }

        // calculating divided difference table
        dividedDiffTable(x, yy, n);

        // displaying divided difference table
        cout << "\nDivided difference table: " << endl;
        printDiffTable(yy, n);

        // value to be interpolated
        cout << "\nEnter interpolation point: ";
        cin >> value;

        // printing the value
        cout << "\nValue at " << value << " is " << applyFormula(value, x, yy, n) << endl;
        break;
    default:
        cout << "Your choose is wrong. Please, input 1 or 2.";
        break;
    }

    return 0;
}

/*
Enter number of data: 4
Enter data:
x[1] = 5
y[1] = 12
x[2] = 6
y[2] = 13
x[3] = 9
y[3] = 14
x[4] = 11
y[4] = 16
Enter interpolation point: 10

Interpolated value at 10 is 14.6667
*/
