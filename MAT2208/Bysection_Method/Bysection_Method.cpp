// C++ program for implementation of Bisection Method for
// solving equations
#include <cmath>
#include <iostream>
using namespace std;

// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    return x*x*x - x*x + 2;
}

// Prints root of func(x) with error of tol or after max_iter iterations
void bisection(double a, double b, double tol, int max_iter)
{
    if (a > b)
        swap(a, b);
    else if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;
    int iter = 0;
    while ((b - a) >= tol && iter < max_iter)
    {
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (func(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;

        iter++;
    }
    cout << "The value of root is : " << c << "\n";
    cout << "Iterations: " << iter << "\n";
}

// Driver program to test above function
int main()
{
    // User inputs for interval, tolerance, and iterations
    double a = 0.0, b = 0.0;
    int exp = 0;
    int max_iter = 0;

    cout << "Enter a (left endpoint): ";
    cin >> a;
    cout << "Enter b (right endpoint): ";
    cin >> b;
    cout << "Enter tolerance exponent (e.g., 6 for 1e-6): ";
    cin >> exp;
    cout << "Enter max iterations: ";
    cin >> max_iter;

    double tol = pow(10.0, -exp);

    bisection(a, b, tol, max_iter);
    return 0;
}