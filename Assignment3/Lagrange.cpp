#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float x[100], y[100], xp, yp = 0, pro;
    int i, j, n;

    /* Input Section */
    cout << "Enter number of data: ";
    cin >> n;
    cout << "Enter data:" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }
    cout << "Enter interpolation point: ";
    cin >> xp;

    /* Implementing Lagrange Interpolation */
    for (i = 1; i <= n; i++) // n times loop
    {
        pro = 1;
        for (j = 1; j <= n; j++) // nested n times loop
        {
            if (i != j)
            {
                pro = pro * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + pro * y[i];
    }
    cout << endl
         << "Interpolated value at " << xp << " is " << yp;

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