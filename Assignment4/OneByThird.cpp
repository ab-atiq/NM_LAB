#include <iostream>
#include <math.h>

/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

using namespace std;
int main()
{
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    /* Input */
    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;

    /* Calculation */

    /* Finding step size */
    stepSize = (upper - lower) / subInterval;

    /* Finding Integration Value */
    integration = f(lower) + f(upper);

    for (i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;

        if (i % 2 == 0)
        {
            integration = integration + 2 * (f(k));
        }
        else
        {
            integration = integration + 4 * (f(k));
        }
    }

    integration = integration * stepSize / 3;

    cout << endl
         << "Required value of integration is: " << integration;

    return 0;
}

/*  
input
Enter lower limit of integration: 0
Enter upper limit of integration: 6
Enter number of sub intervals: 12
output
Required value of integration is: 1.4037

input
Enter lower limit of integration: 0
Enter upper limit of integration: 1
Enter number of sub intervals: 6
output
Required value of integration is: 0.785398
*/