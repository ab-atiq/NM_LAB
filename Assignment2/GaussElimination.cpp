#include <bits/stdc++.h>
using namespace std;
#define SIZE 20

// show matrix
void displayMatrix(float a[][SIZE], int n)
{
    cout << "Show matrix: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int n;

    cout << setprecision(3) << fixed;

    cout << "Enter number of unknowns: ";
    cin >> n;

    cout << "Enter Coefficients of Augmented Matrix: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            // cout << "a[" << i << "]" << j << "]= ";
            cin >> a[i][j];
        }
    }

    /* Upper triangle matrix create */
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i][i] == 0.0)
        {
            cout << "Mathematical Error!";
            exit(0);
        }
        for (int j = i + 1; j <= n; j++)
        {
            ratio = a[j][i] / a[i][i];

            for (int k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
        // displayMatrix(a, n);
    }

    displayMatrix(a, n);

    /* Substitution Method */
    x[n] = a[n][n + 1] / a[n][n];

    for (int i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    cout << endl
         << "Solution: " << endl;
    char c='z';
    for (int i = 1; i <= n; i++)
    {
        // cout << "x[" << i << "] = " << x[i] << endl;
        cout << char(c-n+i)<< " = " << x[i] << endl;
    }

    return 0;
}

/*
Input:
1 −1 1 1
−3 2 −3 -6
2 −5 4 5
ouput:
x[1]=x=-2, x[2]=y=3 and x[3]=z=6

Input:
1 1 1 1
1 1 −3 -6
2 −5 4 5
output:
math error for 1,1 no element 0

Input:
0 −1 1 1
−3 2 −3 -6
2 −5 4 5
Output:
math error for 0,0 no element 0

Input:
1 −1 1 1 −3 
2 −3 -6 2 −5
4 5 5 8 9
4 -5 7 -3 -4
Solution:
w = 2.554
x = 3.203
y = -0.525
z = -1.826
*/