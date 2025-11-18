# Experiment No : 08

# Experiment Name : Fractional Knapsack Problem

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `fractional_knapsack.py`
- Open the file in VsCode Editor

# Procedure :

    1. Calculate value-to-weight ratio for each item
    2. Sort items in descending order by value/weight ratio
    3. Initialize `total_value = 0` and `remaining_capacity = W`
    4. Iterate through sorted items, take full item if possible
    5. If item doesn't fit completely, take fractional part
    6. Return total_value as maximum achievable value

# Discussion

    - Fractional Knapsack is an optimization problem where items can be divided, allowing partial selection to maximize total value. The greedy approach is optimal with O(n log n) time complexity due to sorting. Unlike 0/1 Knapsack, we can take fractions of items, making greedy strategy work. Sort by value/weight ratio and greedily pick items with highest ratio first until capacity is full.

# Code :

```python
def main():
    n = int(input())
    weights = list(map(int, input().split()))
    values = list(map(int, input().split()))
    W = int(input())
    items = []
    for i in range(n):
        ratio = values[i] / weights[i]
        items.append((ratio, weights[i], values[i]))

    items.sort(reverse=True, key=lambda x: x[0])
    total_value = 0.0
    remaining_capacity = W

    for ratio, weight, value in items:
        if remaining_capacity >= weight:
            total_value += value
            remaining_capacity -= weight
        else:
            total_value += ratio * remaining_capacity
            break
    print(f"{total_value:.2f}")

if __name__ == "__main__":
    main()

# Output :
3
10 20 30
60 100 120
50
240.00
```

# Greedy Selection Example:

For items: weights=[10, 20, 30], values=[60, 100, 120], capacity=50

```
Item | Weight | Value | Ratio (v/w)
-----|--------|-------|------------
  1  |   10   |  60   |   6.0
  2  |   20   |  100  |   5.0
  3  |   30   |  120  |   4.0
```

After sorting by ratio (descending):

```
Step 1: Take item 1 (w=10, v=60) - Remaining capacity: 40
Step 2: Take item 2 (w=20, v=100) - Remaining capacity: 20
Step 3: Take 20/30 of item 3 (w=20, v=80) - Remaining capacity: 0

Total value = 60 + 100 + 80 = 240
```

# Complexity Analysis:

| Approach         | Time Complexity | Space Complexity | Notes                           |
| ---------------- | --------------- | ---------------- | ------------------------------- |
| Greedy (sorting) | O(n log n)      | O(n)             | Optimal for fractional knapsack |
| Without sorting  | O(n²)           | O(1)             | Finding max ratio each time     |
