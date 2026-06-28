def build_forward_difference_table(y_values):
	n = len(y_values)
	table = [list(y_values)]
	for order in range(1, n):
		prev = table[order - 1]
		curr = [prev[i + 1] - prev[i] for i in range(n - order)]
		table.append(curr)
	return table


def factorial(n):
	result = 1
	for i in range(2, n + 1):
		result *= i
	return result


def newton_forward_interpolation(x_values, diff_table, x_target):
	h = x_values[1] - x_values[0]
	p = (x_target - x_values[0]) / h
	result = diff_table[0][0]
	p_term = 1.0

	for order in range(1, len(x_values)):
		p_term *= (p - (order - 1))
		result += (p_term * diff_table[order][0]) / factorial(order)

	return result


def newton_backward_interpolation(x_values, diff_table, x_target):
	n = len(x_values)
	h = x_values[1] - x_values[0]
	p = (x_target - x_values[-1]) / h
	result = diff_table[0][-1]
	p_term = 1.0

	for order in range(1, n):
		p_term *= (p + (order - 1))
		backward_diff = diff_table[order][n - order - 1]
		result += (p_term * backward_diff) / factorial(order)

	return result


def print_difference_table(x_values, diff_table):
	n = len(x_values)
	headers = ["x", "y", "Delta y", "Delta^2 y", "Delta^3 y", "Delta^4 y"]
	print("Forward Difference Table:")
	print(" | ".join(f"{h:>10}" for h in headers[: n + 1]))
	print("-" * (13 * (n + 1)))

	for i in range(n):
		row = [f"{x_values[i]:>10.4f}", f"{diff_table[0][i]:>10.4f}"]
		for order in range(1, n):
			if i < len(diff_table[order]):
				row.append(f"{diff_table[order][i]:>10.4f}")
			else:
				row.append(f"{'':>10}")
		print(" | ".join(row))


def main():
	x_values = [0, 1, 2, 3, 4]
	y_values = [1, 3, 7, 13, 21]

	diff_table = build_forward_difference_table(y_values)

	x_forward = 1.5
	x_backward = 3.5

	y_forward = newton_forward_interpolation(x_values, diff_table, x_forward)
	y_backward = newton_backward_interpolation(x_values, diff_table, x_backward)

	print_difference_table(x_values, diff_table)

	print("\nInterpolated Values:")
	print(f"Using Newton Forward at x = {x_forward}: y = {y_forward:.6f}")
	print(f"Using Newton Backward at x = {x_backward}: y = {y_backward:.6f}")

	print("\nComparison:")
	print(f"Forward result at x = {x_forward}: {y_forward:.6f}")
	print(f"Backward result at x = {x_backward}: {y_backward:.6f}")
	print("Forward interpolation is used for x = 1.5 because it is closer to the beginning of the table (x0 = 0)")
	print("Backward interpolation is used for x = 3.5 because it is closer to the end of the table (xn = 4)")


if __name__ == "__main__":
	main()
