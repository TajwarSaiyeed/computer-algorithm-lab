# Experiment No : 07

# Experiment Name : 0-1 Knapsack Problem (Recursive Solution)

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `0_1_knapsack.py`
- Open the file in VsCode Editor

# Procedure :

    1. Create DP table `dp[n+1][W+1]` initialized with 0
    2. Iterate through items (i from 1 to n) and weights (w from 1 to W)
    3. If current item weight ≤ w: `dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w])`
    4. Otherwise: `dp[i][w] = dp[i-1][w]`
    5. Get user input: n, weights, values, capacity
    6. Return `dp[n][W]` as maximum value

# Discussion

    - The 0/1 Knapsack problem is a classic optimization problem where each item can be included or excluded to maximize total value without exceeding weight capacity. The iterative DP approach is the most efficient solution with O(n×W) time complexity and O(n×W) space complexity. It builds a table bottom-up, avoiding recursion overhead and stack overflow risk. Each cell dp[i][w] represents the maximum value achievable with first i items and capacity w.

# Code :

```python
def knapsack(n, weights, values, W):
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if weights[i-1] <= w:
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w])
            else:
                dp[i][w] = dp[i-1][w]

    return dp[n][W]

def main():
    n = int(input())
    weights = list(map(int, input().split()))
    values = list(map(int, input().split()))
    W = int(input())
    print(knapsack(n, weights, values, W))

if __name__ == "__main__":
    main()
# Output :
3
10 20 30
60 100 120
50
220
```

# DP Table Example:

For items: weights=[10, 20, 30], values=[60, 100, 120], capacity=50

```
     w=0  10   20   30   40   50
i=0   0    0    0    0    0    0
i=1   0   60   60   60   60   60
i=2   0   60  100  160  160  160
i=3   0   60  100  160  180  220
```

Final answer: `dp[3][50] = 220`

# Complexity Analysis:

| Approach             | Time Complexity | Space Complexity | Notes                                  |
| -------------------- | --------------- | ---------------- | -------------------------------------- |
| Iterative with DP    | O(n×W)          | O(n×W)           | Most efficient, no stack overflow risk |
| Recursion with DP    | O(n×W)          | O(n×W) + O(n)    | Extra O(n) for recursion stack         |
| Recursion without DP | O(2^n)          | O(n)             | Very slow, exponential time            |
