# Experiment No : 02

# Experiment Name : Factorial Calculation

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `factorial.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `factorial(n)` that returns the factorial of n using recursion.
    2. Inside the function, check if `n` is less than or equal to 1. If so, return 1 (base case).
    3. For all other values of `n`, return `n * factorial(n-1)`.
    4. Outside the function, prompt the user to enter a positive integer `n`.
    5. Call the `factorial(n)` function and print the result.
    6. Use memoization to optimize the recursive calls for larger values of `n`.

# Discussion and Application
    - The factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n. Mathematical definition: n! = n × (n-1) × (n-2) × ... × 2 × 1, where 0! = 1.
    - This recursive approach is simple and elegant but can be inefficient for large `n` due to repeated calculations. Memoization helps optimize performance by caching previously computed results. The factorial function grows very rapidly (5! = 120, 10! = 3,628,800), making it important to understand computational limits.
    - Applications include combinatorics (permutations and combinations nCr = n!/(r!×(n-r)!)), probability theory (binomial distributions), cryptography (key generation), algorithm complexity analysis, game theory (calculating possible game states), biology (genetic combinations), and machine learning (feature selection).
    - Learning outcomes: Master basic recursion with clear base and recursive cases, understand how to implement memoization for optimization, analyze factorial's rapid growth rate, and apply factorial in solving combinatorial problems.

# DP Table Example:
For n = 5:
```
n    | 0 | 1 | 2 | 3 | 4  | 5  |
-----|---|---|---|---|----|----|
f(n) | 1 | 1 | 2 | 6 | 24 | 120|
```

# Code :
```python
def factorial(n, memo={}):
    if n in memo:
        return memo[n]
    
    if n <= 1:
        return 1
    
    memo[n] = n * factorial(n-1, memo)
    return memo[n]

n = int(input("Enter a positive integer: "))
result = factorial(n)
print(f"The factorial of {n} is: {result}")
```

# Output Example:
```
Enter a positive integer: 5
The factorial of 5 is: 120
```
