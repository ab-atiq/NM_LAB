#include <iostream>
/* cmath header file is included for pow & fabs functions */
#include <cmath>
using namespace std;

double func(double);
double first_derivative(double);
void newtonRaphsonMethod(double, double);

int main()
{
    double x2, e;

    cout << "Enter the initial guess: ";
    cin >> x2;

    cout << "Enter desired accuracy: ";
    cin >> e;

    newtonRaphsonMethod(x2, e);

    return 0;
}

double func(double x)
{
    /* write the equation whose root you want to find. Here, we are using equation x^3 + x - 1 */
    double res = pow(x, 3) + x - 1;
    return res;
}

double first_derivative(double x)
{
    /* In this function, we have to return the first derivative of our equation which will be 3*x^2 + 1 */
    return (3 * pow(x, 2) + 1);
}

void newtonRaphsonMethod(double x2, double e)
{
    double x1;

    do
    {
        x1 = x2;

        /* Xi+1 = Xi - f(x) / f'(x) */
        x2 = x1 - func(x1) / first_derivative(x1);

    } while (fabs(x2 - x1) >= e);
    /* Stop the loop when |Xi+1 - Xi| becomes less than the desired accuracy(e) */

    cout << "\nThe root of an equation is " << x2;
}