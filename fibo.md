# Experiment No : 01

# Experiment Name : Fibonacci Series

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `fibonacci.py`
- Open the file in VsCode Editor

# Procedure :

    1. Define a function `fibonacci(n)` that returns the nth Fibonacci number using an iterative approach.
    2. Inside the function, check if `n` is less than or equal to 0. If so, return 0.
    3. If `n` is equal to 1, return 1.
    4. Initialize two variables `prev` and `curr` to store the previous two Fibonacci numbers (0 and 1).
    5. Use a for loop to iterate from 2 to n, calculating each Fibonacci number by summing the previous two.
    6. In each iteration, update `prev` and `curr` to move forward in the sequence.
    7. Outside the function, prompt the user to enter a positive integer `n`.
    8. Call the `fibonacci(n)` function and print the result.

# Discussion and Application

    - The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1 (0, 1, 1, 2, 3, 5, 8, 13, 21...). It has applications in computer science, mathematics, nature (plant growth patterns, sunflower spirals), financial markets (technical analysis, Fibonacci retracement), and art & architecture (golden ratio).
    - This iterative approach is the most efficient solution with O(n) time complexity and O(1) space complexity. It avoids the overhead of recursive function calls and the memory cost of storing intermediate results. The algorithm uses only two variables to track the previous values, making it memory-efficient and suitable for calculating large Fibonacci numbers without risk of stack overflow.

# Algorithm Flow:

For n = 10, the iterative calculation:

```
Iteration | prev | curr | Result
----------|------|------|--------
  Start   |  0   |  1   |   -
    1     |  1   |  1   |   1
    2     |  1   |  2   |   2
    3     |  2   |  3   |   3
    4     |  3   |  5   |   5
    5     |  5   |  8   |   8
    6     |  8   |  13  |  13
    7     |  13  |  21  |  21
    8     |  21  |  34  |  34
    9     |  34  |  55  |  55
```

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
```

# Output Example:

```
Enter a positive integer: 10
The 10th Fibonacci number is: 55
```

# Complexity Analysis:

| Approach             | Time Complexity | Space Complexity | Notes                                  |
| -------------------- | --------------- | ---------------- | -------------------------------------- |
| Iterative (For Loop) | O(n)            | O(1)             | Most efficient, no stack overflow risk |
| Recursion Without DP | O(2^n)          | O(n)             | Very slow, exponential time            |
| Recursion With DP    | O(n)            | O(n)             | Fast but uses extra memory             |
