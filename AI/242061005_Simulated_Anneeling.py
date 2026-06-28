from __future__ import annotations

import math
from dataclasses import dataclass
from typing import Sequence, Tuple


@dataclass(frozen=True)
class State:
	index: int
	value: int


def acceptance_probability(current_value: int, candidate_value: int, temperature: float) -> float:

	if candidate_value <= current_value:
		return 1.0
	if temperature <= 0:
		return 0.0
	return math.exp((current_value - candidate_value) / temperature)


def simulated_annealing(
	values: Sequence[int],
	initial_temperature: float = 50.0,
	alpha: float = 0.8,
	random_value: float = 0.6,
) -> Tuple[State, State]:

	if not values:
		raise ValueError("values must not be empty")

	current = State(0, values[0])
	best = current
	temperature = float(initial_temperature)

	for index in range(1, len(values)):
		candidate = State(index, values[index])
		probability = acceptance_probability(current.value, candidate.value, temperature)

		if candidate.value <= current.value or random_value < probability:
			current = candidate

		if current.value < best.value:
			best = current

		temperature *= alpha

	return current, best


def main() -> None:
	values = [10, 8, 6, 13, 21]
	current, best = simulated_annealing(values, initial_temperature=50, alpha=0.8, random_value=0.6)

	print(f"Final current state: index={current.index}, value={current.value}")
	print(f"Best minimized state: index={best.index}, value={best.value}")


if __name__ == "__main__":
	main()
