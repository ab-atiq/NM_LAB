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
    stepSize = (upper - lower) / subInterval; // h calculate

    /* Finding Integration Value */
    integration = f(lower) + f(upper);

    for (i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize; // x1=x0+h, x2=x1+h, x3=x2+h, ...... xn = x(n-1)+h
        integration = integration + 2 * (f(k)); // Y(1,n-1) = f(k)
    }

    integration = integration * stepSize / 2;

    cout << endl
         << "Required value of integration is: " << integration;

    return 0;
}

/*
input
Enter lower limit of integration: 0
Enter upper limit of integration: 6
Enter number of sub intervals: 6
output
Required value of integration is: 1.4108

input
Enter lower limit of integration: 0
Enter upper limit of integration: 1
Enter number of sub intervals: 6
output
Required value of integration is: 0.784241
*/