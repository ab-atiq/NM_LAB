#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x - 4 * x - 10;
}

double derivativeFunctionValue(double x)
{
    return 2 * x - 4;
}

void newtonRaphsonMethod(double x1, double e)
{
    double x2;
    while (true)
    {
        x2 = x1 - (f(x1) / derivativeFunctionValue(x1)); // root/x2 = x1 - ( f(x1) / f'(x1) )
        if (abs(f(x2)) < e || f(x2) == 0.0 || abs(x2 - x1) < e)
        // if (abs(f(x2)) < e)
            break;
        x1 = x2;
    }
    cout << "The value of root is : " << x2 << endl;
}

int main()
{
    double x1, e;
    cout << "Enter the value of x1 (initial guess) and e: ";
    cin >> x1 >> e;
    newtonRaphsonMethod(x1, e);
    return 0;
}