# Experiment No : 04

# Experiment Name : Merge Sort Algorithm

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `merge_sort.py`
- Open the file in VsCode Editor

# Procedure :

    1. Define `merge(left, right)` function to merge two sorted arrays
    2. Define `merge_sort(arr)` function using divide-and-conquer approach
    3. Divide array into two halves recursively until single elements
    4. Merge sorted subarrays back together in sorted order
    5. Get user input array and call merge_sort function
    6. Print the sorted array

# Discussion

    - Merge Sort is a stable divide-and-conquer sorting algorithm with consistent O(n log n) time complexity in all cases. It divides the array recursively until single elements, then merges sorted subarrays. Requires O(n) extra space for temporary arrays during merging. Stability is preserved by placing left array elements before right array elements when equal.

# Code :

```python
def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]
    left = merge_sort(left)
    right = merge_sort(right)
    return merge(left, right)

def main():
    arr = list(map(int, input("Input : ").split()))
    sorted_arr = merge_sort(arr)
    print(f"Sorted array: {sorted_arr}")

if __name__ == "__main__":
    main()
# Output :
Input : [38, 27, 43, 3, 9, 82, 10]
Sorted array: [3, 9, 10, 27, 38, 43, 82]
```

# Complexity Analysis:

| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Best Case    | O(n log n)      | O(n)             |
| Average Case | O(n log n)      | O(n)             |
| Worst Case   | O(n log n)      | O(n)             |

# Stability: **STABLE**
