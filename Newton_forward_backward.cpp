// C program to demonstrate both Forward and Backward Newton's Interpolation
#include <stdio.h>
void forward(float x[4], float y[4][4], int n);
void BackWard(float x[4], float y[4][4], int n);
int main()
{
    int i, j;
    int n = 4; // number of arguments
    float x[4] = {0, 1, 2, 3};
    float y[4][4] = {
        {5, 0, 0, 0},
        {6, 0, 0, 0},
        {3, 0, 0, 0},
        {8, 0, 0, 0},
    };

    forward(x, y, n);
    BackWard(x, y, n);

    return 0;
}
void forward(float x[4], float y[4][4], int n)
{
    int i, j;
    float a = 1.1; // interpolation point
    float h, u, sum, p;
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1]; // only difference table, not divided difference table
        }
    }
    printf("\n The forward difference table is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n - i; j++)
        {
            printf("%f\t", y[i][j]);
        }
    }

    // f(a+hu)=f0 + u*Δf0 + u(u-1) Δ^2f0/2! + u(u-1)(u-2)Δ^3f0/3! 

    p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[0]) / h; // a is interpolation point
    for (j = 1; j < n; j++) // minimum 2 element
    {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
    }
    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);
}
void BackWard(float x[4], float y[4][4], int n)
{
    int i, j;
    float a = 1.1; // interpolation point
    float h, u, sum, p;
    for (j = 1; j < n; j++)
    {
        for (i = j; i < n; i++)
        {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }
    printf("\nThe backward difference table is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j <= i; j++)
        {
            printf("%f\t", y[i][j]);
        }
    }

    p = 1.0;
    sum = y[n - 1][0];
    h = x[1] - x[0];
    u = (a - x[n - 1]) / h;
    for (j = 1; j < n; j++)
    {
        p = p * (u + j - 1) / j;
        sum = sum + p * y[n - 1][j];
    }

    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);
}
