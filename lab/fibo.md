# Experiment No : 01

# Experiment Name : Fibonacci Series

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `fibonacci.py`
- Open the file in VsCode Editor

# Procedure :

    1. Define `fibonacci(n)` function with iterative approach
    2. Handle base cases: return 0 if n ≤ 0, return 1 if n = 1
    3. Initialize `prev = 0, curr = 1` for the first two Fibonacci numbers
    4. Loop from 2 to n, updating: `prev, curr = curr, prev + curr`
    5. Return `curr` as the nth Fibonacci number
    6. Get user input for n and display the result

# Discussion

    - The iterative approach is the most efficient solution with O(n) time complexity and O(1) space complexity. It avoids the overhead of recursive function calls and memory cost of storing intermediate results. The algorithm uses only two variables to track previous values, making it memory-efficient and suitable for calculating large Fibonacci numbers without risk of stack overflow.

# Code :

```python
def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1

    prev, curr = 0, 1
    for _ in range(2, n + 1):
        prev, curr = curr, prev + curr
    return curr

n = int(input("Enter a positive integer: "))
result = fibonacci(n)
print(f"The {n}th Fibonacci number is: {result}")

# Output Example:
Enter a positive integer: 7
The 7th Fibonacci number is: 13
```

# Complexity Analysis:

| Approach             | Time Complexity | Space Complexity | Notes                                  |
| -------------------- | --------------- | ---------------- | -------------------------------------- |
| Iterative (For Loop) | O(n)            | O(1)             | Most efficient, no stack overflow risk |
| Recursion Without DP | O(2^n)          | O(n)             | Very slow, exponential time            |
| Recursion With DP    | O(n)            | O(n)             | Fast but uses extra memory             |
