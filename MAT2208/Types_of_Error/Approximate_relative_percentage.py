import math

# True value and approximate values
true_value = math.sqrt(2)
approx_values = [1.41, 1.414, 1.4142]

print("TRUE VALUE =", true_value)
print("-" * 50)

for approx in approx_values:
    absolute_error = abs(true_value - approx)
    relative_error = absolute_error / abs(true_value)
    percentage_error = relative_error * 100

    print("Approximate Value:", approx)
    print("Absolute Error   :", absolute_error)
    print("Relative Error   :", relative_error)
    print("Percentage Error :", percentage_error, "%")
    print("-" * 50)
