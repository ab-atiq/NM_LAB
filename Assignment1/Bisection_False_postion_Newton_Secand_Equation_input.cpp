#include <bits/stdc++.h>
using namespace std;

int max_degree;
double cofficient[10];

double functionValue(double x)
{
    double equationValue = 0;
    for (int i = max_degree; i >= 0; i--)
    {
        equationValue += cofficient[i] * pow(x, i);

        // if (i == 5)
        // {
        //     equationValue += cofficient[i] * pow(x, 5);
        // }
        // else if (i == 4)
        // {
        //     equationValue += cofficient[i] * pow(x, 4);
        // }
        // else if (i == 3)
        // {
        //     equationValue += cofficient[i] * pow(x, 3);
        // }
        // else if (i == 2)
        // {
        //     equationValue += cofficient[i] * pow(x, 2);
        // }
        // else if (i == 1)
        // {
        //     equationValue += cofficient[i] * pow(x, 1);
        // }
        // else if (i == 0)
        // {
        //     equationValue += cofficient[i];
        // }
    }

    return equationValue;
}

// Derivative of function
double derivativeFunctionValue(double x)
{
    double derivativeEquationValue = 0;
    for (int i = max_degree; i >= 0; i--)
    {
        if (i > 0)
            derivativeEquationValue += (i * cofficient[i]) * pow(x, (i - 1));
        // if (i == 5)
        // {
        //     derivativeEquationValue += (5 * cofficient[i]) * pow(x, 4);
        // }
        // else if (i == 4)
        // {
        //     derivativeEquationValue += (4 * cofficient[i]) * pow(x, 3);
        // }
        // else if (i == 3)
        // {
        //     derivativeEquationValue += (3 * cofficient[i]) * pow(x, 2);
        // }
        // else if (i == 2)
        // {
        //     derivativeEquationValue += (2 * cofficient[i]) * x;
        // }
        // else if (i == 1)
        // {
        //     derivativeEquationValue += cofficient[i] * 1;
        // }
    }
    return derivativeEquationValue;
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
            x2 = x0;
        else
            x1 = x0;
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
            break;
        if (functionValue(x0) * functionValue(x1) < 0)
            x2 = x0;
        else
            x1 = x0;
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
            break;
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
            break;
    }
    cout << "The value of root is : " << x2 << endl;
}

int main()
{
    cout << "Enter maximum degree of equation: ";
    cin >> max_degree;
    for (int i = max_degree; i >= 0; i--)
    {
        cout << "Enter the value of coeffient x ^ " + to_string(i) + ": ";
        cin >> cofficient[i];
    }
    cout << endl;

    // equation create and show
    string equationString = "";
    for (int i = max_degree; i >= 0; i--)
    {
        // cout << cofficient[i];
        if (i > 0)
        {
            if (i == max_degree)
                equationString += to_string(cofficient[i]) + "*x^" + to_string(i);
            else if (cofficient[i] > 0 && i != max_degree)
                equationString += " + " + to_string(cofficient[i]) + "*x^" + to_string(i);
            else if (cofficient[i] < 0 && i != max_degree)
                equationString += " - " + to_string(-1 * cofficient[i]) + "*x^" + to_string(i);
        }
        else if (i == 0)
        {
            if (cofficient[i] > 0)
                equationString += " + " + to_string(cofficient[i]) + " = 0";
            else if (cofficient[i] < 0)
                equationString += " - " + to_string(-1 * cofficient[i]) + " = 0";
        }

        // if (i == 5)
        // {
        //     if (cofficient[i] > 0)
        //         equationString += to_string(cofficient[i]) + "*x^5 ";
        //     else if (cofficient[i] < 0)
        //         equationString += "- " + to_string(-1 * cofficient[i]) + "*x^5 ";
        // }
        // else if (i == 4)
        // {
        //     if (cofficient[i] > 0)
        //         equationString += "+ " + to_string(cofficient[i]) + "*x^4 ";
        //     else if (cofficient[i] < 0)
        //         equationString += "- " + to_string(-1 * cofficient[i]) + "*x^4 ";
        // }
        // else if (i == 3)
        // {
        //     if (cofficient[i] > 0)
        //         equationString += "+ " + to_string(cofficient[i]) + "*x^3 ";
        //     else if (cofficient[i] < 0)
        //         equationString += "- " + to_string(-1 * cofficient[i]) + "*x^3 ";
        // }
        // else if (i == 2)
        // {
        //     if (cofficient[i] > 0)
        //         equationString += "+ " + to_string(cofficient[i]) + "*x^2 ";
        //     else if (cofficient[i] < 0)
        //         equationString += "- " + to_string(-1 * cofficient[i]) + "*x^2 ";
        // }
        // else if (i == 1)
        // {
        //     if (cofficient[i] > 0)
        //         equationString += "+ " + to_string(cofficient[i]) + "*x ";
        //     else if (cofficient[i] < 0)
        //         equationString += "- " + to_string(-1 * cofficient[i]) + "*x ";
        // }
        // if (i == 0)
        // {
        //     if (cofficient[i] > 0)
        //         equationString += " + " + to_string(cofficient[i]) + " = 0";
        //     else if (cofficient[i] < 0)
        //         equationString += " - " + to_string(-1 * cofficient[i]) + " = 0";
        // }
    }
    cout << "Given Equation: " << equationString << endl;

    cout << "\n1. Bisection Method\n2. False Position Method\n3. Newton Raphson Method\n4. Secant Method" << endl;
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