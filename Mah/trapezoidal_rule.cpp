#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 1.0 / (1 + x * x);
}

int main() {
    double lower, upper, answer, stepSize, k;
    int i, n;

    cout << "Enter lower & upper limit and number of intervals(even): ";
    cin >> lower >> upper >> n;

    stepSize = (upper - lower) / n;
    answer = f(lower) + f(upper);

    k = lower;
    for (i = 1; i <= n - 1; i++) {
        k = k + stepSize;
        answer = answer + 2 * (f(k));
    }

    answer = answer * (stepSize / 2);
    cout << "\nAnswer is: " << answer << endl;

    return 0;
}
