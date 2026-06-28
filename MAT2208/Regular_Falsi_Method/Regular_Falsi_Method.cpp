// C++ program for implementation of Regular Falsi Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000


// An example function whose solution is determined using
// Regular Falsi Method. The function is x^3 - x^2  + 2
double func(double x)
{
    return x*x*x - x*x + 2;
}

// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b, int maxIter)
{
    if (a > b)
        swap(a, b);

    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;  // Initialize result
    int iterations = (maxIter > 0) ? maxIter : MAX_ITER;

    for (int i=0; i < iterations; i++)
    {
        // Find the point that touches x axis
        c = (a*func(b) - b*func(a))/ (func(b) - func(a));

        // Check if the above found point is root
        if (func(c)==0)
            break;

        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}

// Driver program to test above function
int main()
{
    // Initial values assumed
    double a, b;
    int maxIter;

    cout << "Enter a: ";
    if (!(cin >> a))
    {
        cout << "Invalid input.\n";
        return 1;
    }

    cout << "Enter b: ";
    if (!(cin >> b))
    {
        cout << "Invalid input.\n";
        return 1;
    }

    cout << "Enter max iterations: ";
    if (!(cin >> maxIter))
    {
        cout << "Invalid input.\n";
        return 1;
    }

    regulaFalsi(a, b, maxIter);
    return 0;
}