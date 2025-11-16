# Experiment No : 06

# Experiment Name : Merge Sort Algorithm

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `merge_sort.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `merge_sort(arr)` that sorts an array using the merge sort algorithm.
    2. Divide the array into two halves recursively until each subarray has only one element.
    3. Define a `merge(left, right)` function that merges two sorted arrays into one sorted array.
    4. In the merge function, compare elements from both arrays and place them in sorted order.
    5. If one array is exhausted, append the remaining elements from the other array.
    6. Recursively merge the sorted subarrays back together.
    7. The base case is when the array has one or zero elements (already sorted).
    8. Read input array from user and call merge_sort function.
    9. Print the sorted array.

# Discussion and Application
    - Merge Sort is a stable, divide-and-conquer sorting algorithm that guarantees O(n log n) performance in all cases. **Stability: STABLE** - Preserves the relative order of equal elements because during merging, elements from the left array are always placed before elements from the right array when they are equal.
    - Consistent O(n log n) time complexity in all cases (best, average, worst), making it highly predictable. Requires O(n) extra space for temporary arrays during merging, which is the main drawback. The algorithm can be parallelized effectively for multi-core processors. Invented by John von Neumann in 1945.
    - Applications include external sorting (sorting large files that don't fit in memory), linked list sorting (efficient due to sequential access), database systems (sorting query results, merge joins in SQL), version control (Git uses merge sort for combining branches), e-commerce (stable sorting of products by multiple criteria like price then rating), operating systems (task scheduling), scientific computing (large dataset analysis, genomic data), parallel processing (multi-threaded sorting in big data), and distributed systems (MapReduce operations).
    - Learning outcomes: Master divide-and-conquer paradigm, understand efficient merging of sorted arrays, learn guaranteed O(n log n) performance regardless of input, understand stable sorting importance, analyze space-time trade-offs, learn external sorting for large datasets, understand parallel algorithm design, and recognize when stability matters in real applications.

# Division Example:
For array [38, 27, 43, 3, 9, 82, 10]:
```
Level 0:        [38, 27, 43, 3, 9, 82, 10]
                /                        \
Level 1:   [38, 27, 43, 3]            [9, 82, 10]
           /            \              /         \
Level 2: [38, 27]    [43, 3]        [9, 82]    [10]
         /    \      /    \         /    \
Level 3: [38] [27]  [43] [3]      [9]  [82]   [10]
```

# Merging Example:
```
Merge: [27, 38] and [3, 43]
Compare: 27 vs 3  → [3]
Compare: 27 vs 43 → [3, 27]
Compare: 38 vs 43 → [3, 27, 38]
Remaining: 43     → [3, 27, 38, 43]
```

# Step-by-Step Execution Table:
```
Step | Action                          | Result
-----|--------------------------------|------------------------
1    | Divide [38,27,43,3,9,82,10]   | [38,27,43,3] [9,82,10]
2    | Divide left                    | [38,27] [43,3]
3    | Divide right                   | [9,82] [10]
4    | Merge [38] [27]                | [27,38]
5    | Merge [43] [3]                 | [3,43]
6    | Merge [27,38] [3,43]           | [3,27,38,43]
7    | Merge [9] [82]                 | [9,82]
8    | Merge [9,82] [10]              | [9,10,82]
9    | Merge [3,27,38,43] [9,10,82]   | [3,9,10,27,38,43,82]
```

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
    arr = list(map(int, input("Enter array elements separated by space: ").split()))
    
    print(f"Original array: {arr}")
    sorted_arr = merge_sort(arr)
    print(f"Sorted array: {sorted_arr}")

if __name__ == "__main__":
    main()
```

# Input Example:
```
Enter array elements separated by space: 38 27 43 3 9 82 10
```

# Output Example:
```
Original array: [38, 27, 43, 3, 9, 82, 10]
Sorted array: [3, 9, 10, 27, 38, 43, 82]
```

# Complexity Analysis:
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best Case     | O(n log n)      | O(n)             |
| Average Case  | O(n log n)      | O(n)             |
| Worst Case    | O(n log n)      | O(n)             |

# Stability: **STABLE**
# In-Place: **NO** (requires extra space)
