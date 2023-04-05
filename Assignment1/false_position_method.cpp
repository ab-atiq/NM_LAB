#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x - 4 * x - 10;
}

void falsePositionMethod(double x1, double x2, double e)
{
    if (f(x1) * f(x2) >= 0)
    {
        cout << "You have not assumed right x1 and x2";
        return;
    }

    double x0;
    // double x0=x1;
    // while(abs(x2-x1)>=e)
    while (true)
    {
        // x0 = x1 - ((f(x1) * (x2 - x1)) / (f(x2) - f(x1))); // sutro - 1
        x0 = (f(x2) * x1 - f(x1) * x2) / (f(x2) - f(x1)); // sutro - 2
        // if (abs(x2 - x1) < e || abs(f(x0)) < e || f(x0) == 0.0)
        if (abs(f(x0)) < e)
            break;
        if (f(x0) * f(x1) < 0)
            x2 = x0;
        else
            x1 = x0;
    }
    cout << "The value of root is : " << x0 << endl;
}

int main()
{
    double x1, x2, e;
    cout << "Enter the value of x1, x2 and e: ";
    cin >> x1 >> x2 >> e;
    falsePositionMethod(x1, x2, e);
    return 0;
}