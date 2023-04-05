#include <iostream>

using namespace std;

int main()
{
    float x[20], y[20][20];
    int i, j, n;

    /* Input Section */
    cout << "Enter number of data? " << endl;
    cin >> n;

    cout << "Enter data: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }

    /* Generating Forward Difference Table */
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    /* Displaying Forward Difference Table */
    cout << endl
         << "FORWARD DIFFERENCE TABLE" << endl;
    for (i = 0; i < n; i++)
    {
        cout << x[i];
        for (j = 0; j < n - i; j++)
        {
            cout << "\t" << y[i][j];
        }
        cout << endl;
    }

    return 0;
}
/*
Enter number of data?
5
Enter data:
x[0] = 40
y[0] = 31
x[1] = 50
y[1] = 73
x[2] = 60
y[2] = 124
x[3] = 70
y[3] = 159
x[4] = 80
y[4] = 190

FORWARD DIFFERENCE TABLE
40      31      42      9       -25     37
50      73      51      -16     12
60      124     35      -4
70      159     31
80      190
*/