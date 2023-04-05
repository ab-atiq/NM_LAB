#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

using namespace std;

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
    int i, j, k, n;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout << setprecision(3) << fixed;

    /* Inputs */
    /* 1. Reading number of unknowns */
    cout << "Enter number of unknowns: ";
    cin >> n;

    /* 2. Reading Augmented Matrix */
    cout << "Enter Coefficients of Augmented Matrix: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            // cout << "a[" << i << "]" << j << "]= ";
            cin >> a[i][j];
        }
    }

    /* Applying Gauss Elimination: upper triangle matrix create */
    for (i = 1; i <= n - 1; i++) // iteration on row = all column down element of diagonal matrix make 0
    {
        if (a[i][i] == 0.0)
        {
            cout << "Mathematical Error!";
            exit(0);
        }
        for (j = i + 1; j <= n; j++) // work on row after previous row
        {
            ratio = a[j][i] / a[i][i];

            for (k = 1; k <= n + 1; k++) // work on column
            {
                // one element of matrix will change depent on 4 element. 1. which element will change, 2. which element will 0, 3. which row will element impact on make 0 vukti. 4. following 3 no rule row element which is column of 1st rule element.
                a[j][k] = a[j][k] - ratio * a[i][k]; // (initial idx 1 not 0) a[j=2][k=1] -= ((a[j=2][k=1]/a[j=1][i=1])*a[i=1][i=1])
            }
        }
        // displayMatrix(a, n);
    }

    displayMatrix(a, n);

    /* Obtaining Solution by Back Substitution Method */
    x[n] = a[n][n + 1] / a[n][n]; // z calculate

    for (i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1]; // y-x-w-v-u calculate
        for (j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j]; // substitite all cofficient execept that element cofficient
        }
        x[i] = x[i] / a[i][i]; // divide that element cofficient
    }

    /* Displaying Solution */
    cout << endl
         << "Solution: " << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return (0);
}