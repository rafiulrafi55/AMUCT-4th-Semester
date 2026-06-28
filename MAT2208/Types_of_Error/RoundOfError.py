# Round-off error example
x = 1 / 3

rounded_2 = round(x, 2)
rounded_4 = round(x, 4)

error_2 = abs(x - rounded_2)
error_4 = abs(x - rounded_4)

print("\nROUND-OFF ERROR")
print("-" * 50)
print("Original Value           :", x)
print("Rounded to 2 decimals    :", rounded_2)
print("Round-off Error (2 dec)  :", error_2)
print("Rounded to 4 decimals    :", rounded_4)
print("Round-off Error (4 dec)  :", error_4)