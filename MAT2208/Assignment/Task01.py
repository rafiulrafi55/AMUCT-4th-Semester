def f(x):
	return x**3 - 4*x - 9


def get_float(prompt):
	while True:
		value = input(prompt).strip()
		if value.lower() == "stop":
			print("Program stopped by user ")
			raise SystemExit
		try:
			return float(value)
		except ValueError:
			print("Invalid input. Please enter a numeric value")


def regula_falsi(a, b, tol=1e-5, max_iter=100):
	fa = f(a)
	fb = f(b)

	if fa * fb >= 0:
		return None, None, None, []

	rows = []
	c_prev = None
	a_updates = 0
	b_updates = 0

	for i in range(1, max_iter + 1):
		c = (a * fb - b * fa) / (fb - fa)
		fc = f(c)

		if c_prev is None:
			err = None
		else:
			err = abs(c - c_prev)

		rows.append((i, a, b, c, fa, fb, fc, err))

		if err is not None and err < tol:
			return c, i, fc, rows, a_updates, b_updates

		if fa * fc < 0:
			b = c
			fb = fc
			b_updates += 1
		elif fb * fc < 0:
			a = c
			fa = fc
			a_updates += 1
		else:
			return c, i, fc, rows, a_updates, b_updates

		c_prev = c

	return c, max_iter, fc, rows, a_updates, b_updates


def print_table(rows):
	header = (
		f"{'Iter':>4} {'a':>14} {'b':>14} {'c':>14} "
		f"{'f(a)':>14} {'f(b)':>14} {'f(c)':>14} {'|error|':>14}"
	)
	print("\nIntermediate Values:")
	print(header)
	print("-" * len(header))
	for i, a, b, c, fa, fb, fc, err in rows:
		err_text = "-" if err is None else f"{err:.8e}"
		print(
			f"{i:>4} {a:>14.8f} {b:>14.8f} {c:>14.8f} "
			f"{fa:>14.8f} {fb:>14.8f} {fc:>14.8f} {err_text:>14}"
		)


def print_bias_comment(a_updates, b_updates):
	print("\nBias Analysis:")
	if a_updates == b_updates:
		print("Endpoint updates are balanced; no strong one-sided bias is observed")
	elif a_updates > b_updates:
		print(
			"The method updates a more often while b remains fixed more frequently, "
			"indicating one-sided convergence bias toward the right endpoint"
		)
	else:
		print(
			"The method updates b more often while a remains fixed more frequently, "
			"indicating one-sided convergence bias toward the left endpoint"
		)


def main():
	print("Regula Falsi Method for f(x) = x^3 - 4x - 9")

	while True:
		a = get_float("Enter initial guess a: ")
		b = get_float("Enter initial guess b: ")
		if f(a) * f(b) < 0:
			break
		print("Invalid interval: f(a) * f(b) must be < 0. Please try again\n")

	result = regula_falsi(a, b, tol=1e-5, max_iter=100)

	if result[0] is None:
		print("Failed to start Regula Falsi: valid bracketing interval not provided")
		return

	root, iterations, f_root, rows, a_updates, b_updates = result

	print_table(rows)

	print("\nResults:")
	print(f"Root approximation: {root:.10f}")
	print(f"Number of iterations: {iterations}")
	print(f"f(x) at root: {f_root:.10e}")

	print_bias_comment(a_updates, b_updates)


if __name__ == "__main__":
	main()
