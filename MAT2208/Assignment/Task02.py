import math


def f(x):
	return math.exp(-x) - x


def df(x):
	return -math.exp(-x) - 1


def get_float(prompt):
	while True:
		value = input(prompt).strip()
		if value.lower() == "stop":
			print("Program stopped")
			raise SystemExit
		try:
			return float(value)
		except ValueError:
			print("Invalid input. Please enter a numeric value")


def regula_falsi(a, b, tol=1e-6, max_iter=1000):
	fa = f(a)
	fb = f(b)

	if fa * fb >= 0:
		return None, 0, None

	c_prev = None
	c = None
	fc = None

	for i in range(1, max_iter + 1):
		c = (a * fb - b * fa) / (fb - fa)
		fc = f(c)

		if c_prev is not None and abs(c - c_prev) < tol:
			return c, i, fc

		if fa * fc < 0:
			b = c
			fb = fc
		elif fb * fc < 0:
			a = c
			fa = fc
		else:
			return c, i, fc

		c_prev = c

	return c, max_iter, fc


def newton_raphson(x0, tol=1e-6, max_iter=1000):
	x_prev = x0

	for i in range(1, max_iter + 1):
		dfx = df(x_prev)
		if dfx == 0:
			return None, i - 1, None

		x_new = x_prev - f(x_prev) / dfx

		if abs(x_new - x_prev) < tol:
			return x_new, i, f(x_new)

		x_prev = x_new

	return x_prev, max_iter, f(x_prev)


def print_method_result(name, root, iterations, f_root):
	print(f"\n{name}:")
	if root is None:
		print("Method failed to produce a root")
		return
	print(f"Root approximation: {root:.12f}")
	print(f"Iterations: {iterations}")
	print(f"f(root): {f_root:.12e}")
	print(f"Accuracy |f(root)|: {abs(f_root):.12e}")


def print_conclusion(rf_root, rf_it, rf_fx, nr_root, nr_it, nr_fx):
	print("\nConclusion:")

	if rf_root is None and nr_root is None:
		print("Neither method produced a valid root with the provided inputs")
		return

	if rf_root is None:
		print("Newton-Raphson converged faster because Regula Falsi did not converge from the given bracket")
	elif nr_root is None:
		print("Regula Falsi converged faster because Newton-Raphson did not converge from the given initial guess")
	else:
		if nr_it < rf_it:
			print("Newton-Raphson converges faster (fewer iterations)")
		elif rf_it < nr_it:
			print("Regula Falsi converges faster (fewer iterations)")
		else:
			print("Both methods required the same number of iterations")

		if abs(nr_fx) < abs(rf_fx):
			print("Newton-Raphson gave a slightly more accurate root in this run")
		elif abs(rf_fx) < abs(nr_fx):
			print("Regula Falsi gave a slightly more accurate root in this run")
		else:
			print("Both methods achieved similar root accuracy in this run")

	print("Newton performs poorly when the initial guess is far from the root, near a point where f'(x) is very small, or when the function behavior causes divergence/oscillation. Regula Falsi is more robust in these cases but can be slower to converge, especially if the root is near one of the endpoints of the initial bracket")


def main():
	tol = 1e-6

	print("Method Comparison for f(x) = e^(-x) - x")
	print("Type STOP at any prompt to exit the program")

	while True:
		a = get_float("Enter Regula Falsi lower bound a: ")
		b = get_float("Enter Regula Falsi upper bound b: ")
		if f(a) * f(b) < 0:
			break
		print("Invalid bracket: f(a) * f(b) must be < 0. Please try again\n")

	x0 = get_float("Enter Newton-Raphson initial guess x0: ")

	rf_root, rf_it, rf_fx = regula_falsi(a, b, tol=tol)
	nr_root, nr_it, nr_fx = newton_raphson(x0, tol=tol)

	print_method_result("Regula Falsi", rf_root, rf_it, rf_fx)
	print_method_result("Newton-Raphson", nr_root, nr_it, nr_fx)
	print_conclusion(rf_root, rf_it, rf_fx, nr_root, nr_it, nr_fx)


if __name__ == "__main__":
	main()
