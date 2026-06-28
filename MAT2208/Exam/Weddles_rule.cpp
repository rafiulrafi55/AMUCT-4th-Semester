#include <iostream>
#include <cmath>
using namespace std;


double f(double x)
{
    return x * x + 1;  
}


double weddle(double a, double b, int n)
{
    if (n % 6 != 0)
        n += (6 - n % 6);

    double h = (b - a) / n;
    double integral = 0;

    for (int i = 0; i < n; i += 6)
    {
        double x0 = a + i * h;
        double x1 = x0 + h;
        double x2 = x0 + 2 * h;
        double x3 = x0 + 3 * h;
        double x4 = x0 + 4 * h;
        double x5 = x0 + 5 * h;
        double x6 = x0 + 6 * h;

        integral += (3 * h / 10) *
                    (f(x0) + 5 * f(x1) + f(x2) +
                     6 * f(x3) + f(x4) +
                     5 * f(x5) + f(x6));
    }

    return integral;
}

int main()
{
    double a, b;
    int n;

    cout << "Enter lower limit: ";
    cin >> a;

    cout << "Enter upper limit: ";
    cin >> b;

    cout << "Enter number of subintervals: ";
    cin >> n;

    cout << "Integral = " << weddle(a, b, n) << endl;

    return 0;
}