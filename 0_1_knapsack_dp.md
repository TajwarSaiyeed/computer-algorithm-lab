# Experiment No : 04

# Experiment Name : 0-1 Knapsack Problem with Dynamic Programming (Memoization)

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `0_1_knapsack_dp.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `knapsack_dp(n, weights, values, total_W, dp)` that uses memoization.
    2. Create a DP table initialized with -1 to indicate uncomputed states.
    3. Inside the function, check base cases: if `n < 0` or `total_W == 0`, return 0.
    4. Check if the subproblem is already solved: if `dp[n][total_W] != -1`, return cached value.
    5. If the weight of current item is less than or equal to capacity:
       - Calculate selected case: `knapsack_dp(n-1, weights, values, total_W - weights[n], dp) + values[n]`
       - Calculate not selected case: `knapsack_dp(n-1, weights, values, total_W, dp)`
       - Store and return the maximum in `dp[n][total_W]`
    6. If weight exceeds capacity, store and return `knapsack_dp(n-1, weights, values, total_W, dp)`
    7. Read input and initialize DP table with -1
    8. Call the function and print the result

# Discussion and Application
    - This approach combines recursion with dynamic programming using memoization (top-down approach). Each subproblem is solved only once and cached in the DP table, eliminating redundant calculations and improving time complexity from O(2^n) to O(n × W) where W is the knapsack capacity.
    - The DP table stores solutions to subproblems: dp[i][w] = maximum value using first i items with capacity w. This technique demonstrates the power of trading space for time in algorithm optimization while maintaining the intuitive recursive structure.
    - Applications include e-commerce (recommendation systems with budget constraints, warehouse optimization), network design (bandwidth allocation), financial planning (asset allocation, portfolio optimization), manufacturing (production planning, cutting stock), healthcare (resource allocation in hospitals), logistics (container loading, delivery route planning), cloud computing (VM placement, cost optimization), and machine learning (feature selection with computational constraints).
    - Learning outcomes: Master top-down DP (memoization), understand how to convert recursive solutions to DP, learn to design 2D DP tables, analyze space-time trade-offs, recognize when memoization improves performance, understand state representation in DP, and apply DP to real-world optimization problems.

# DP Table Structure:
```
dp[i][w] = maximum value obtainable using first i items with capacity w

For items with weights [10, 20, 30], values [60, 100, 120], capacity 50:

     W:  0   10   20   30   40   50
Item 0: [0,  60,  60,  60,  60,  60]
Item 1: [0,  60, 100, 160, 160, 160]
Item 2: [0,  60, 100, 160, 180, 220]
                                 ^^^
                            Maximum value
```

# DP Table Explanation:
- **dp[0][10]** = 60 (take item 0 with weight 10, value 60)
- **dp[1][20]** = 100 (take item 1 with weight 20, value 100)
- **dp[1][30]** = 160 (take both item 0 and item 1, values 60+100)
- **dp[2][50]** = 220 (take item 1 and item 2, values 100+120)

# State Transition:
```
dp[i][w] = max(
    dp[i-1][w],                           // Don't take item i
    dp[i-1][w - weights[i]] + values[i]   // Take item i
)
```

# Code :
```python
def knapsack_dp(n, weights, values, total_W, dp):
    if n < 0 or total_W == 0:
        return 0
    
    if dp[n][total_W] != -1:
        return dp[n][total_W]
    
    if weights[n] <= total_W:
        selected = knapsack_dp(n-1, weights, values, total_W - weights[n], dp) + values[n]
        not_selected = knapsack_dp(n-1, weights, values, total_W, dp)
        dp[n][total_W] = max(selected, not_selected)
    else:
        dp[n][total_W] = knapsack_dp(n-1, weights, values, total_W, dp)
    
    return dp[n][total_W]

def main():
    n = int(input())
    weights = list(map(int, input().split()))
    values = list(map(int, input().split()))
    total_W = int(input())
    
    dp = [[-1 for _ in range(total_W + 1)] for _ in range(n)]
    
    result = knapsack_dp(n-1, weights, values, total_W, dp)
    print(result)

if __name__ == "__main__":
    main()
```

# Input Example:
```
3
10 20 30
60 100 120
50
```

# Output Example:
```
220
```

# Comparison with Recursive Approach:
| Aspect              | Recursive      | DP (Memoization) |
|---------------------|----------------|------------------|
| Time Complexity     | O(2^n)         | O(n × W)         |
| Space Complexity    | O(n)           | O(n × W)         |
| Recomputation       | Yes            | No               |
| Suitable for        | Small inputs   | Large inputs     |

# Time Complexity: O(n × W)
# Space Complexity: O(n × W) for DP table + O(n) for recursion stack
