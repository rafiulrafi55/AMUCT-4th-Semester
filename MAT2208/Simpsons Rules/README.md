# Weddle's Rule (Composite) - Example

This directory contains a small C++ example implementing the composite Weddle's rule for numerical integration.

Files:
- `Weddles_rule.cpp`: implementation and example `main()`.

Notes:
- Weddle's rule requires the number of subintervals `n` to be a positive multiple of 6.

Compile (using `g++`):

```powershell
g++ -std=c++17 "Weddles_rule.cpp" -O2 -o Weddles_rule.exe
./Weddles_rule.exe
```

Example: integrates `sin(x)` on [0, pi]; expected result is 2.0.
