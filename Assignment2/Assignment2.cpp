#include <bits/stdc++.h>
using namespace std;
#define SIZE 20

void displayMatrix(float a[][SIZE], int n)
{
    // cout << "Show matrix: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void UpperTriangle(float a[][SIZE], int n)
{
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
            float ratio = a[j][i] / a[i][i];

            for (int k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
        // displayMatrix(a, n);
    }
}

void CalculateSolution(float a[][SIZE], float x[], int n)
{
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
         << "Solution of the equation is: " << endl;
    char c = 'z';
    for (int i = 1; i <= n; i++)
    {
        // cout << "x[" << i << "] = " << x[i] << endl;
        cout << char(c - n + i) << " = " << x[i] << endl;
    }
}

void GaussJordanMethod(float a[][SIZE], float x[], int n)
{
    /* Applying Gauss Jordan Elimination */
    for (int i = 1; i <= n; i++)
    {
        if (a[i][i] == 0.0)
        {
            cout << "Mathematical Error!";
            exit(0);
        }
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                float ratio = a[j][i] / a[i][i];
                for (int k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    cout << "After gauss jordan operation: " << endl;
    displayMatrix(a, n);

    /* Obtaining Solution */
    for (int i = 1; i <= n; i++)
    {
        x[i] = a[i][n + 1] / a[i][i];
    }

    /* Displaying Solution */
    cout << endl
         << "Solution of the equation is: " << endl;
    char c = 'z';
    for (int i = 1; i <= n; i++)
    {
        // cout << "x[" << i << "] = " << x[i] << endl;
        cout << char(c - n + i) << " = " << x[i] << endl;
    }
}

int main()
{
    float a[SIZE][SIZE], x[SIZE];
    int n, chooseOption;
    cout << setprecision(3) << fixed;
    cout << "1. Gauss Elimination Method\n2. Gauss Jordan Method\nChoose option (1 or 2) : ";
    cin >> chooseOption;
    switch (chooseOption)
    {
    case 1:
        cout << "Enter number of unknowns: ";
        cin >> n;

        cout << "Enter Coefficients of Augmented Matrix: " << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                cout << "a[" << i << "]" << j << "]= ";
                cin >> a[i][j];
            }
        }

        cout << "Your given matrix is: " << endl;
        displayMatrix(a, n);

        // Create Upper Triangle
        UpperTriangle(a, n);

        cout << "Matrix after create upper triangle: " << endl;
        displayMatrix(a, n);

        // Calculate solution of these equation
        CalculateSolution(a, x, n);

        break;

    case 2:
        cout << "Enter number of unknowns: ";
        cin >> n;

        cout << "Enter Coefficients of Augmented Matrix: " << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                cout << "a[" << i << "]" << j << "]= ";
                cin >> a[i][j];
            }
        }

        cout << "Your given matrix is: " << endl;
        displayMatrix(a, n);

        // apply gauss jordan method
        GaussJordanMethod(a, x, n);

        break;

    default:
        cout << "Your input is wrong. Please, input (1 or 2)." << endl;
        break;
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
*/
