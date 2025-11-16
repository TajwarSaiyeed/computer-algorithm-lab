# Experiment No : 01

# Experiment Name : Fibonacci Series

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `fibonacci.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `fibonacci(n)` that returns the nth Fibonacci number using recursion.
    2. Inside the function, check if `n` is less than or equal to 0. If so, return 0.
    3. If `n` is equal to 1, return 1.
    4. For all other values of `n`, return the sum of the two preceding Fibonacci numbers by calling `fibonacci(n-1)` and `fibonacci(n-2)`.
    5. Outside the function, prompt the user to enter a positive integer `n`.
    6. Call the `fibonacci(n)` function and print the result.
    7. Use memoization to optimize the recursive calls for larger values of `n`.

# Discussion and Application
    - The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1 (0, 1, 1, 2, 3, 5, 8, 13, 21...). It has applications in computer science, mathematics, nature (plant growth patterns, sunflower spirals), financial markets (technical analysis, Fibonacci retracement), and art & architecture (golden ratio).
    - This recursive approach is straightforward but can be inefficient for large `n` due to repeated calculations. Memoization reduces time complexity from exponential O(2^n) to linear O(n) by storing previously computed results.
    - Understanding recursion is crucial for solving problems that can be broken down into smaller subproblems. This experiment helps students learn the concept of overlapping subproblems in dynamic programming, analyze time-space complexity trade-offs, and implement top-down DP (memoization) technique.
    - Real-world applications include algorithm analysis, network optimization, game development (procedural generation), and DNA sequence analysis.

# DP Table (Memoization):
For n = 10, the memo dictionary stores:
```
n    | 0 | 1 | 2 | 3 | 4 | 5 | 6  | 7  | 8  | 9  | 10 |
-----|---|---|---|---|---|---|----|----|----|----|----|
f(n) | 0 | 1 | 1 | 2 | 3 | 5 | 8  | 13 | 21 | 34 | 55 |
```

# Recursion Tree Without Memoization:
```
                    fib(5)
                   /      \
              fib(4)      fib(3)
              /   \       /    \
         fib(3) fib(2) fib(2) fib(1)
         /  \    /  \    /  \
    fib(2) fib(1) ...  ...  ...
    /  \
fib(1) fib(0)
```
Without memoization: Many redundant calculations (fib(3) calculated twice, fib(2) three times, etc.)

# With Memoization:
```
First call to fib(n):
- Calculate and store in memo
- Subsequent calls: Return from memo (O(1))

Example for fib(5):
memo = {0: 0, 1: 1, 2: 1, 3: 2, 4: 3, 5: 5}
Each value computed only once!
```

# State Transition:
```
f(n) = f(n-1) + f(n-2)

where:
- f(0) = 0 (base case)
- f(1) = 1 (base case)
```

# Code :
```python
def fibonacci(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo)
        return memo[n] 
         
n = int(input("Enter a positive integer: "))
result = fibonacci(n)
print(f"The {n}th Fibonacci number is: {result}")
```

# Output Example:
```
Enter a positive integer: 10
The 10th Fibonacci number is: 55
```

# Complexity Analysis:
| Approach           | Time Complexity | Space Complexity |
|--------------------|-----------------|------------------|
| Without Memoization| O(2^n)          | O(n)             |
| With Memoization   | O(n)            | O(n)             |