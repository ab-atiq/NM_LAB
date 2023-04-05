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
    /* Implementing Bisection Method */
    cout << endl
         << "****************" << endl;
    cout << "Bisection Method" << endl;
    cout << "****************" << endl;
    do
    {
        /* Bisecting Interval */
        x = (x0 + x1) / 2;
        f = f(x);

        cout << "Iteration-" << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << endl;

        if (f0 * f < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
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

****************
Bisection Method
****************
Iteration-1:     x =   0.500000 and f(x) =   0.053222
Iteration-2:     x =   0.750000 and f(x) =  -0.856061
Iteration-3:     x =   0.625000 and f(x) =  -0.356691
Iteration-4:     x =   0.562500 and f(x) =  -0.141294
Iteration-5:     x =   0.531250 and f(x) =  -0.041512
Iteration-6:     x =   0.515625 and f(x) =   0.006475
Iteration-7:     x =   0.523438 and f(x) =  -0.017362
Iteration-8:     x =   0.519531 and f(x) =  -0.005404
Iteration-9:     x =   0.517578 and f(x) =   0.000545
Iteration-10:    x =   0.518555 and f(x) =  -0.002427
Iteration-11:    x =   0.518066 and f(x) =  -0.000940
Iteration-12:    x =   0.517822 and f(x) =  -0.000197
Iteration-13:    x =   0.517700 and f(x) =   0.000174
Iteration-14:    x =   0.517761 and f(x) =  -0.000012
Iteration-15:    x =   0.517731 and f(x) =   0.000081
Iteration-16:    x =   0.517746 and f(x) =   0.000035
Iteration-17:    x =   0.517754 and f(x) =   0.000011
Iteration-18:    x =   0.517757 and f(x) =  -0.000000

Root is: 0.517757

*/