#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float x0, y0, x1, y1, xp, yp;

    /* Inputs */
    cout << "Enter first point (x0,y0):" << endl;
    cin >> x0 >> y0;
    cout << "Enter second point (x1,y1):" << endl;
    cin >> x1 >> y1;
    cout << "Enter interpolation point: ";
    cin >> xp;

    /* Linear Interpolation */
    // Y = y1 + (x-x1)*(y2-y1)/(x2-x1)
    yp = y0 + ((y1 - y0) / (x1 - x0)) * (xp - x0);

    /* Displaying Output */
    cout << "Interpolated value at " << xp << " is " << yp;

    return 0;
}

/*

Enter first point (x0,y0): 35 5.6
Enter second point (x1,y1): 40 7.4
Enter interpolation point: 38
Interpolated value at 38 is 6.68

*/