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

    /* Generating Backward Difference Table */
    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j > i - 1; j--)
        {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    /* Displaying Backward Difference Table */
    cout << endl
         << "BACKWARD DIFFERENCE TABLE" << endl;

    for (i = 0; i < n; i++)
    {
        cout << x[i];
        for (j = 0; j <= i; j++)
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
x[0] = 20
y[0] = 33
x[1] = 30
y[1] = 71
x[2] = 40
y[2] = 118
x[3] = 50
y[3] = 163
x[4] = 60
y[4] = 188

BACKWARD DIFFERENCE TABLE
20      33
30      71      38
40      118     47      9
50      163     45      -2      -11
60      188     25      -20     -18     -7
*/
