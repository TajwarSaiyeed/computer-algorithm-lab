# Experiment No : 05

# Experiment Name : Quick Sort Algorithm

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `quick_sort.py`
- Open the file in VsCode Editor

# Procedure :

    1. Define `partition(arr, low, high)` function to place pivot at correct position
    2. Define `quick_sort(arr, low, high)` using divide-and-conquer approach
    3. Choose pivot element (last element) and partition array
    4. Recursively sort left partition (elements before pivot)
    5. Recursively sort right partition (elements after pivot)
    6. Get user input array, call quick_sort, and print result

# Discussion

    - Quick Sort is an efficient divide-and-conquer sorting algorithm with O(n log n) average time complexity but O(n²) worst case. It partitions arrays around a pivot element with in-place sorting using O(log n) space for recursion stack. Unstable because swapping operations don't preserve relative order of equal elements.

# Code :

```python
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def main():
    arr = list(map(int, input("Enter array elements separated by space: ").split()))
    n = len(arr)
    print(f"Original array: {arr}")
    quick_sort(arr, 0, n - 1)
    print(f"Sorted array: {arr}")

if __name__ == "__main__":
    main()
```

# Input Example:

```
Enter array elements separated by space: 10 7 8 9 1 5
```

# Output Example:

```
Original array: [10, 7, 8, 9, 1, 5]
Sorted array: [1, 5, 7, 8, 9, 10]
```

# Complexity Analysis:

| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Best Case    | O(n log n)      | O(log n)         |
| Average Case | O(n log n)      | O(log n)         |
| Worst Case   | O(n²)           | O(n)             |

# Stability: **UNSTABLE**
