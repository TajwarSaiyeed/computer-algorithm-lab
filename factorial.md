# Experiment No : 02

# Experiment Name : Factorial Calculation

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `factorial.py`
- Open the file in VsCode Editor

# Procedure :

    1. Define `factorial(n)` function with iterative approach
    2. Handle base case: return 1 if n ≤ 1
    3. Initialize `result = 1` to store the factorial value
    4. Loop from 2 to n, multiplying: `result *= i`
    5. Return `result` as the factorial of n
    6. Get user input for n and display the result

# Discussion

    - The iterative approach is the most efficient solution with O(n) time complexity and O(1) space complexity. It avoids the overhead of recursive function calls and memory cost of storing intermediate results. The algorithm uses a single variable to accumulate the factorial value, making it memory-efficient and suitable for calculating large factorials without risk of stack overflow.

# Code :

```python
def factorial(n):
    if n <= 1:
        return 1

    result = 1
    for i in range(2, n + 1):
        result *= i
    return result

n = int(input("Enter a positive integer: "))
result = factorial(n)
print(f"The factorial of {n} is: {result}")

# Output Example:
Enter a positive integer: 5
The factorial of 5 is: 120
```

# Complexity Analysis:

| Approach             | Time Complexity | Space Complexity | Notes                                  |
| -------------------- | --------------- | ---------------- | -------------------------------------- |
| Iterative (For Loop) | O(n)            | O(1)             | Most efficient, no stack overflow risk |
| Recursion Without DP | O(n)            | O(n)             | Stack overhead, risk of stack overflow |
| Recursion With DP    | O(n)            | O(n)             | Uses extra memory for memoization      |
