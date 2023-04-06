#include <bits/stdc++.h>
using namespace std;
float f(float x)
{
    return 1 / (1 + pow(x, 2));
};

void TrapezoidalCalculate()
{
    float lower, upper, integration = 0.0, stepSize, k;
    int subInterval;

    cout << "-----------------------------------------------" << endl
         << "Trapezoidal Method" << endl
         << "-----------------------------------------------" << endl;

    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;

    /* Taking Trapezoidal Rule Calculation */
    stepSize = (upper - lower) / subInterval;
    integration = f(lower) + f(upper);

    for (int i = 1; i <= subInterval - 1; i++)
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
}
void OneByThirdRule()
{
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;
    cout << "-----------------------------------------------" << endl
         << "Simpson's 1/3 Rule" << endl
         << "-----------------------------------------------" << endl;
    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;

    /* Simpson's 1/3 Calculation */
    stepSize = (upper - lower) / subInterval;
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
}
void ThreeByEightRule()
{
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;
    cout << "-----------------------------------------------" << endl
         << "Simpson's 3/8 Rule" << endl
         << "-----------------------------------------------" << endl;
    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;

    /* Simpson's 3/8 Rule Calculation */
    stepSize = (upper - lower) / subInterval;
    integration = f(lower) + f(upper);

    for (i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;

        if (i % 3 == 0)
        {
            integration = integration + 2 * (f(k));
        }
        else
        {
            integration = integration + 3 * (f(k));
        }
    }

    integration = integration * stepSize * 3.0 / 8.0;

    cout << endl
         << "Required value of integration is: " << integration;
}

int main()
{
    int chOp;
    cout << "1. Trapezoidal Rule\n2. Simpson's 1/3 Rule\n3.Simpson's 3/8 Rule\nChoose option(1 or 2 or 3): ";
    cin >> chOp;
    switch (chOp)
    {
    case 1:
        TrapezoidalCalculate();
        break;
    case 2:
        OneByThirdRule();
        break;
    case 3:
        ThreeByEightRule();
        break;

    default:
        cout << "Please, choose option 1 or 2 or 3.";
        break;
    }
    return 0;
}
