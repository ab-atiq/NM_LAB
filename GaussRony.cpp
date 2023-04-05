#include <bits/stdc++.h>
using namespace std;

double matrix[10][10];
double solution[10];

void gaussElimination(int size)
{
    for (int i = 0; i < size; i++)
    {
        // Reduce each row below pivot
        for (int j = i + 1; j < size; j++)
        {
            for (int k = i + 1; k < size + 1; k++)
            {
                matrix[j][k] -= (matrix[j][i] / matrix[i][i]) * matrix[i][k];
            }
            matrix[j][i] = 0;
        }
    }
}

void backSubstitution(int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < size; j++)
        {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (matrix[i][size] - sum) / matrix[i][i];
    }
}

int main()
{
    int size;
    cout << "Enter size of matrix: ";
    cin >> size;

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            cin >> matrix[i][j];
        }
    }

    gaussElimination(size);
    backSubstitution(size);

    cout << "Solution:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "x[" << i << "] = " << solution[i] << endl;
    }

    return 0;
}