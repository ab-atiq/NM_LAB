#include <bits/stdc++.h>
using namespace std;

// default function = x^2 - 4*x - 10, r1 = 5.741657387, r2 = -1.741657387

// Function Value
double functionValue(double x)
{
    return x * x - 4 * x - 10;
}

// Derivative of function
double derivativeFunctionValue(double x)
{
    return 2 * x - 4;
}

// Problem solve Using Bisection Method
void bisectionMethodOperation(double x1, double x2, double e)
{
    if (functionValue(x1) * functionValue(x2) >= 0)
    {
        cout << "You have not assumed right x1 and x2" << endl;
        return;
    }

    double x0;
    while (true)
    {
        x0 = (x1 + x2) / 2;
        // cout << x0 << "       " << functionValue(x0) << "      " << abs(functionValue(x0)) << endl;
        if (abs(functionValue(x0)) < e)
        {
            break;
        }
        else if (functionValue(x0) * functionValue(x1) < 0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
        }
    }
    cout << "The value of root is : " << x0 << endl;
}

// Problem solve Using Fasle Position Method
void falsePositionMethod(double x1, double x2, double e)
{
    if (functionValue(x1) * functionValue(x2) >= 0)
    {
        cout << "You have not assumed right x1 and x2";
        return;
    }

    double x0;
    while (true)
    {
        x0 = x1 - ((functionValue(x1) * (x2 - x1)) / (functionValue(x2) - functionValue(x1)));
        if (abs(functionValue(x0)) < e)
        {
            break;
        }
        if (functionValue(x0) * functionValue(x1) < 0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
        }
    }
    cout << "The value of root is : " << x0 << endl;
}

// Problem solve Using Newton Raphson Method
void newtonRaphsonMethod(double x1, double e)
{
    double x2;
    while (true)
    {
        x2 = x1 - (functionValue(x1) / derivativeFunctionValue(x1));
        x1 = x2;
        if (abs(functionValue(x2)) < e)
        {
            break;
        }
    }
    cout << "The value of root is : " << x2 << endl;
}

// Problem solve Using Secant Method
void secantMethod(double x0, double x1, double e)
{
    double x2;
    while (true)
    {
        x2 = x1 - (functionValue(x1) * (x1 - x0)) / (functionValue(x1) - functionValue(x0));
        x0 = x1;
        x1 = x2;
        if (abs(functionValue(x2)) < e)
        {
            break;
        }
    }
    cout << "The value of root is : " << x2 << endl;
}

int main()
{
    cout << "1. Bisection Method\n2. False Position Method\n3. Newton Raphson Method\n4. Secant Method" << endl;
    int chooseOption;
    cout << "Choose Option 1/2/3/4 : ";
    cin >> chooseOption;
    double x0, x1, x2, e;
    switch (chooseOption)
    {
    case 1:
        cout << "Enter the value of x1, x2 (Initial guess or Interval) and e (error) : ";
        cin >> x1 >> x2 >> e;
        bisectionMethodOperation(x1, x2, e);
        break;
    case 2:
        cout << "Enter the value of x1, x2 (Initial guess or Interval) and e (error) : ";
        cin >> x1 >> x2 >> e;
        falsePositionMethod(x1, x2, e);
        break;
    case 3:
        cout << "Enter the value of x1 (Initial guess) and e (error) : ";
        cin >> x1 >> e;
        newtonRaphsonMethod(x1, e);
        break;
    case 4:
        cout << "Enter the value of x0, x1 (Initial guess or Interval) and e (error): ";
        cin >> x0 >> x1 >> e;
        secantMethod(x0, x1, e);
        break;

    default:
        cout << "You choose wrong option. Please, Enter value integer 1-4.";
        break;
    }
    return 0;
}