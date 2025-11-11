# Experiment No : 05

# Experiment Name : Quick Sort Algorithm

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `quick_sort.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `quick_sort(arr, low, high)` that sorts an array using the quick sort algorithm.
    2. Choose a pivot element (usually the last element in the partition).
    3. Partition the array around the pivot: elements smaller than pivot go to the left, larger go to the right.
    4. Define a `partition(arr, low, high)` function that places the pivot in its correct position.
    5. Recursively apply quick sort to the left partition (elements before pivot).
    6. Recursively apply quick sort to the right partition (elements after pivot).
    7. The base case is when `low >= high` (single element or empty array).
    8. Read input array from user and call quick_sort function.
    9. Print the sorted array.

# Discussion and Application
    - Quick Sort is a highly efficient, divide-and-conquer sorting algorithm that works by partitioning arrays around a pivot element. **Stability: UNSTABLE** - Does not preserve the relative order of equal elements due to swapping operations during partitioning.
    - Average time complexity is O(n log n), but worst case is O(n²) when the array is already sorted or reverse sorted. Uses in-place sorting with O(log n) extra space for recursion stack in average case. Named by Tony Hoare in 1959, it's one of the most widely used sorting algorithms.
    - Quick sort is often faster in practice than other O(n log n) algorithms due to good cache locality and low constant factors. The choice of pivot significantly affects performance; common strategies include: last element, first element, median-of-three, or random element.
    - Applications include operating systems (file system sorting, process scheduling), database management (query optimization, index creation), search engines (ranking results), e-commerce (product sorting by price/rating), scientific computing (data analysis), graphics processing (Z-buffer sorting), compiler design (symbol tables), and programming libraries (C++ std::sort uses Introsort which starts with Quick Sort).
    - Learning outcomes: Understand divide-and-conquer paradigm, master partitioning technique, learn in-place sorting strategies, analyze best/average/worst-case complexities, understand pivot selection impact, recognize trade-offs between stability and efficiency, and compare Quick Sort with other O(n log n) algorithms.

# Partitioning Example:
For array [10, 7, 8, 9, 1, 5] with pivot = 5:
```
Initial:  [10, 7, 8, 9, 1, 5]
Pivot: 5
After partition: [1, 5, 8, 9, 7, 10]
                    ^
                  pivot at correct position
Left partition: [1]
Right partition: [8, 9, 7, 10]
```

# Recursion Tree:
```
                [10, 7, 8, 9, 1, 5]
                /                  \
            [1]                [8, 9, 7, 10]
                              /            \
                        [7, 8, 9]          [10]
                        /      \
                    [7, 8]     [9]
                    /    \
                  [7]    [8]
```

# Step-by-Step Execution Table:
```
Step | Array                    | Pivot | Action
-----|--------------------------|-------|------------------
1    | [10, 7, 8, 9, 1, 5]     | 5     | Partition
2    | [1, 5, 8, 9, 7, 10]     | -     | Pivot placed
3    | [1] | [8, 9, 7, 10]     | 10    | Sort subarrays
4    | [1] | [7, 8, 9, 10]     | 9     | Continue sorting
5    | [1, 5, 7, 8, 9, 10]     | -     | Final sorted
```

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
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best Case     | O(n log n)      | O(log n)         |
| Average Case  | O(n log n)      | O(log n)         |
| Worst Case    | O(n²)           | O(n)             |

# Stability: **UNSTABLE**
# In-Place: **YES**
