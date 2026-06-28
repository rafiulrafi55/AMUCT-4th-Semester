# Truncation error using Taylor series
import math
x = 1
true_value = math.exp(x)

print("\nTRUNCATION ERROR (Taylor Series of e^x)")
print("-" * 50)
print("True Value of e^1 =", true_value)

approximation = 0

for n in range(1, 6):
    approximation += x**(n-1) / math.factorial(n-1)
    truncation_error = abs(true_value - approximation)

    print("Terms used:", n)
    print("Approximation:", approximation)
    print("Truncation Error:", truncation_error)
    print("-" * 50)