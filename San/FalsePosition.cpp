#include <iostream>
#include <iomanip>
#include <math.h>

/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/

#define f(x) cos(x) - x *exp(x)

using namespace std;

int main()
{
    /* Declaring required variables */
    float x0, x1, x, f0, f1, f, e;
    int step = 1;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout << setprecision(6) << fixed;

/* Inputs */
up:
    cout << "Enter first guess: ";
    cin >> x0;
    cout << "Enter second guess: ";
    cin >> x1;
    cout << "Enter tolerable error: ";
    cin >> e;

    /* Calculating Functional Value */
    f0 = f(x0);
    f1 = f(x1);

    /* Checking whether given guesses brackets the root or not. */
    if (f0 * f1 > 0.0)
    {
        cout << "Incorrect Initial Guesses." << endl;
        goto up;
    }
    /* Implementing False Position Method */
    cout << endl
         << "*********************" << endl;
    cout << "False Position Method" << endl;
    cout << "*********************" << endl;
    do
    {
        /* Applying False Position Method */
        /* x is next approximated root using False Position method */
        x = x0 - (x0 - x1) * f0 / (f0 - f1);
        f = f(x);

        cout << "Iteration-" << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;

        if (f0 * f < 0)
        {
            x1 = x;
            f1 = f;
        }
        else
        {
            x0 = x;
            f0 = f;
        }
        step = step + 1;
    } while (fabs(f) > e);

    cout << endl
         << "Root is: " << x << endl;

    return 0;
}

/*  
Enter first guess: 0
Enter second guess: 1
Enter tolerable error: 0.00001

*********************
False Position Method
*********************
Iteration-1:     x =   0.314665 and f(x) =   0.519871
Iteration-2:     x =   0.446728 and f(x) =   0.203545
Iteration-3:     x =   0.494015 and f(x) =   0.070802
Iteration-4:     x =   0.509946 and f(x) =   0.023608
Iteration-5:     x =   0.515201 and f(x) =   0.007760
Iteration-6:     x =   0.516922 and f(x) =   0.002539
Iteration-7:     x =   0.517485 and f(x) =   0.000829
Iteration-8:     x =   0.517668 and f(x) =   0.000271
Iteration-9:     x =   0.517728 and f(x) =   0.000088
Iteration-10:    x =   0.517748 and f(x) =   0.000029
Iteration-11:    x =   0.517754 and f(x) =   0.000009

Root is: 0.517754
*/