#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
        return -1; // infinite solutions
    }
    if (a == 0 && b == 0) {
        return 0; // no solution
    }
    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0) return 0;

    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);

    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

void runTest(double a, double b, double c, vector<double> expected) {
    double x[4];
    int n = solveQuartic(a, b, c, x);
    cout << "Test input: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Output (" << n << ") solutions: ";
    for (int i = 0; i < n; i++) cout << x[i] << " ";
    cout << endl;

    cout << "Expected: ";
    for (double v : expected) cout << v << " ";
    cout << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    // Test cases
    runTest(0, 0, 0, {}); // infinite solutions
    runTest(0, 0, 5, {}); // no solution
    runTest(0, 2, -8, {2, -2});
    runTest(1, 0, 1, {});
    runTest(1, -5, 4, {2, -2, 1, -1});
    return 0;
}
