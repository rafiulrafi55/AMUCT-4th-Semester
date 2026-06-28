#include <iostream>
#include <cmath>
using namespace std;

// Original function
double f(double x)
{
    return x*x*x - x*x + 2;
}

// Derivative for Newton-Raphson
double df(double x)
{
    return 3*x*x - 2*x;
}

/* ================= FIXED POINT METHOD ================= */
// g(x) chosen from: x^3 - x^2 + 2 = 0
// Rearranged as: x = cbrt(x^2 - 2)

double g(double x)
{
    return cbrt(x*x - 2);
}

void fixedPoint(double x0, double tol, int maxIter)
{
    cout << "\n--- Fixed Point Iteration ---\n";

    double x1;
    int iter = 0;

    while (iter < maxIter)
    {
        x1 = g(x0);

        cout << "Iter " << iter + 1 << " : " << x1 << endl;

        if (fabs(x1 - x0) < tol)
        {
            cout << "Root (Fixed Point) = " << x1 << "\n";
            cout << "Iterations = " << iter + 1 << "\n";
            return;
        }

        x0 = x1;
        iter++;
    }

    cout << "Did not converge.\n";
}

/* ================= NEWTON RAPHSON METHOD ================= */

void newtonRaphson(double x0, double tol, int maxIter)
{
    cout << "\n--- Newton Raphson Method ---\n";

    double x1;
    int iter = 0;

    while (iter < maxIter)
    {
        if (df(x0) == 0)
        {
            cout << "Derivative zero, stop\n";
            return;
        }

        x1 = x0 - f(x0) / df(x0);

        cout << "Iter " << iter + 1 << " : " << x1 << endl;

        if (fabs(x1 - x0) < tol)
        {
            cout << "Root (Newton) = " << x1 << "\n";
            cout << "Iterations = " << iter + 1 << "\n";
            return;
        }

        x0 = x1;
        iter++;
    }

    cout << "Did not converge\n";
}

/* ================= MAIN ================= */

int main()
{
    double x0, tol;
    int maxIter;

    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    fixedPoint(x0, tol, maxIter);
    newtonRaphson(x0, tol, maxIter);

    return 0;
}