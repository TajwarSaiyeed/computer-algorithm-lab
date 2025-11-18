# Experiment No : 05

# Experiment Name : Insertion Sort Algorithm

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `insertion_sort.py`
- Open the file in VsCode Editor

# Procedure :

    1. Define `insertion_sort(arr)` function using insertion sort algorithm
    2. Start from second element, store it as key
    3. Compare key with sorted portion elements
    4. Shift elements greater than key one position right
    5. Insert key at correct position in sorted portion
    6. Get user input array, call insertion_sort, and print result

# Discussion

    - Insertion Sort is a simple stable sorting algorithm that builds the sorted array one element at a time. It's efficient for small datasets with O(n) best case (already sorted) and O(n²) worst case. Uses O(1) space with in-place sorting. Stability is preserved by shifting only when elements are strictly greater than the key, not when equal.

# Code :

```python
def insertion_sort(arr):
    n = len(arr)

    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def main():
    arr = list(map(int, input("Input : ").split()))
    insertion_sort(arr)
    print(f"Sorted array: {arr}")

if __name__ == "__main__":
    main()
Input : [5, 2, 4, 6, 1, 3]
Sorted array: [1, 2, 3, 4, 5, 6]
```

# Input Example:

```
Enter array elements separated by space: 5 2 4 6 1 3
```

# Output Example:

```

```

# Complexity Analysis:

| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Best Case    | O(n)            | O(1)             |
| Average Case | O(n²)           | O(1)             |
| Worst Case   | O(n²)           | O(1)             |

# Stability: **STABLE**
