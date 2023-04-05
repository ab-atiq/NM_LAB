#include <bits/stdc++.h>
using namespace std;

// default function = x^2 - 4*x - 10, r1 = 5.741657387, r2 = -1.741657387
double functionValue(double x)
{
    return x * x - 4 * x - 10;
    // return pow(x, 3) + x - 2;
}

void bisectionMethodOperation(double x1, double x2, double e)
{
    if (functionValue(x1) * functionValue(x2) >= 0)
    {
        cout << "You have not assumed right x1 and x2" << endl;
        return;
    }

    double x0;
    // double x0 = x1;
    // while(abs(x2-x1)>=e)
    while (true)
    {
        x0 = (x1 + x2) / 2;
        // cout << x0 << "       " << functionValue(x0) << "      " << abs(functionValue(x0)) << endl;
        // if (functionValue(x0) == 0.0 || abs(x2 - x1) < e || abs(functionValue(x0))<e)
        //     break;
        if (abs(functionValue(x0)) < e)
        {
            break;
        }
        else if (functionValue(x0) * functionValue(x1) < 0)
            x2 = x0;
        else
            x1 = x0;
    }
    cout << "The value of root is : " << fixed << setprecision(6) << x0 << endl;
}

int main()
{
    double x1, x2, e;
    cout << "Enter the value of x1, x2 (Initial guess or Interval) and e (error) : ";
    cin >> x1 >> x2 >> e;
    bisectionMethodOperation(x1, x2, e);
    return 0;
}