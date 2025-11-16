# Experiment No : 03

# Experiment Name : 0-1 Knapsack Problem (Recursive Solution)

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `0_1_knapsack.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `knapsack(n, weights, values, total_W)` that returns the maximum value that can be obtained.
    2. Inside the function, check if `n < 0` or `total_W == 0`. If so, return 0 (base case).
    3. If the weight of the current item is less than or equal to the remaining capacity:
       - Calculate the value if item is selected: `knapsack(n-1, weights, values, total_W - weights[n]) + values[n]`
       - Calculate the value if item is not selected: `knapsack(n-1, weights, values, total_W)`
       - Return the maximum of these two values
    4. If the weight exceeds capacity, skip the item and return `knapsack(n-1, weights, values, total_W)`
    5. Read input: number of items, weights array, values array, and knapsack capacity
    6. Call the function with `n-1` (0-indexed) and print the result

# Discussion and Application
    - The 0-1 Knapsack problem is a classic optimization problem where each item can either be included (1) or excluded (0) from the knapsack. Goal: Maximize the total value of items without exceeding weight capacity.
    - The recursive approach explores all possible combinations but has exponential time complexity O(2^n), making it inefficient for larger inputs due to overlapping subproblems being recalculated multiple times. The problem exhibits both optimal substructure and overlapping subproblems, making it suitable for dynamic programming optimization.
    - Applications include resource allocation (distributing limited CPU, memory, bandwidth), budget management (selecting projects within budget to maximize ROI), cargo loading (optimizing shipment weight and value), investment portfolio selection, manufacturing (cutting stock problem), cloud computing (VM allocation, task scheduling), cryptography (subset sum problems), and data compression.
    - Learning outcomes: Understand optimization problems with constraints, learn to formulate problems recursively with multiple choices, analyze exponential time complexity, recognize overlapping subproblems, understand trade-offs between including/excluding items, and identify when dynamic programming is needed.

# Recursion Tree Example:
For items with weights [10, 20, 30], values [60, 100, 120], capacity 50:
```
                    K(2, 50)
                   /         \
              K(1, 20)      K(1, 50)
              /     \       /      \
         K(0,10) K(0,20) K(0,30) K(0,50)
```

# Code :
```python
def knapsack(n, weights, values, total_W):
    if n < 0 or total_W == 0:
        return 0

    if weights[n] <= total_W:
        selected = knapsack(n-1, weights, values, total_W - weights[n]) + values[n]
        not_selected = knapsack(n-1, weights, values, total_W)
        return max(selected, not_selected)
    else:
        return knapsack(n-1, weights, values, total_W)

def main():
    n = int(input())
    weights = list(map(int, input().split()))
    values = list(map(int, input().split()))
    total_W = int(input())
    print(knapsack(n-1, weights, values, total_W))

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

# Time Complexity: O(2^n)
# Space Complexity: O(n) - recursion stack
