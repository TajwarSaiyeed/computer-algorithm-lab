# Experiment No : 07

# Experiment Name : Insertion Sort Algorithm

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `insertion_sort.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `insertion_sort(arr)` that sorts an array using the insertion sort algorithm.
    2. Start with the second element (index 1) as the first element is considered sorted.
    3. Store the current element in a variable (key).
    4. Compare the key with elements in the sorted portion (elements before it).
    5. Shift all elements greater than the key one position to the right.
    6. Insert the key at its correct position in the sorted portion.
    7. Repeat steps 3-6 for all elements in the array.
    8. Read input array from user and call insertion_sort function.
    9. Print the sorted array.

# Discussion and Application
    - Insertion Sort is a simple, stable sorting algorithm that builds the final sorted array one item at a time, similar to sorting playing cards. **Stability: STABLE** - Preserves the relative order of equal elements because we only shift elements when they are strictly greater than the key, not when equal.
    - Efficient for small datasets and nearly sorted arrays (best case O(n) when already sorted, worst case O(n²)). Works well for online sorting (sorting data as it arrives in real-time). In-place sorting with O(1) extra space. Simple implementation makes it easy to understand and debug. Despite O(n²) worst-case complexity, it can outperform complex algorithms on small or nearly sorted datasets due to low overhead. Adaptive algorithm: performance improves when input is partially sorted.
    - Applications include small dataset sorting (when n < 50), hybrid sorting algorithms (used as final step in Timsort for Python and Introsort for C++), online algorithms (sorting data streams), playing cards (natural human sorting method), database indexing (maintaining small sorted index pages), real-time systems (low overhead for embedded systems), spreadsheet software (sorting small ranges), file systems (sorting directory entries), and network packet processing.
    - Learning outcomes: Understand incremental algorithm design, learn maintaining sorted and unsorted portions, master in-place array manipulation, understand adaptive algorithm behavior, learn when simple algorithms outperform complex ones, analyze best/average/worst-case scenarios, understand algorithm constants in practice, learn loop invariants for correctness, and understand stability in sorting.

# Sorting Process Visualization:
For array [5, 2, 4, 6, 1, 3]:
```
Initial:    [5, 2, 4, 6, 1, 3]
            
Pass 1:     [2, 5, 4, 6, 1, 3]  (Insert 2 before 5)
Pass 2:     [2, 4, 5, 6, 1, 3]  (Insert 4 between 2 and 5)
Pass 3:     [2, 4, 5, 6, 1, 3]  (6 already in place)
Pass 4:     [1, 2, 4, 5, 6, 3]  (Insert 1 at beginning)
Pass 5:     [1, 2, 3, 4, 5, 6]  (Insert 3 between 2 and 4)
```

# Step-by-Step Execution Table:
```
Pass | Key | Sorted Portion  | Action               | Result
-----|-----|-----------------|----------------------|------------------
0    | -   | [5]             | Initial              | [5, 2, 4, 6, 1, 3]
1    | 2   | [5]             | Insert 2 before 5    | [2, 5, 4, 6, 1, 3]
2    | 4   | [2, 5]          | Insert 4 at index 1  | [2, 4, 5, 6, 1, 3]
3    | 6   | [2, 4, 5]       | No shift needed      | [2, 4, 5, 6, 1, 3]
4    | 1   | [2, 4, 5, 6]    | Insert 1 at index 0  | [1, 2, 4, 5, 6, 3]
5    | 3   | [1, 2, 4, 5, 6] | Insert 3 at index 2  | [1, 2, 3, 4, 5, 6]
```

# Detailed Example (Pass 2):
```
Array: [2, 5, 4, 6, 1, 3]
Key = 4, i = 2

Compare 4 with 5: 4 < 5
  Shift 5 to right: [2, _, 5, 6, 1, 3]
  
Compare 4 with 2: 4 > 2
  Stop shifting
  
Insert 4 at position 1: [2, 4, 5, 6, 1, 3]
```

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
    arr = list(map(int, input("Enter array elements separated by space: ").split()))
    
    print(f"Original array: {arr}")
    insertion_sort(arr)
    print(f"Sorted array: {arr}")

if __name__ == "__main__":
    main()
```

# Input Example:
```
Enter array elements separated by space: 5 2 4 6 1 3
```

# Output Example:
```
Original array: [5, 2, 4, 6, 1, 3]
Sorted array: [1, 2, 3, 4, 5, 6]
```

# Complexity Analysis:
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best Case     | O(n)            | O(1)             |
| Average Case  | O(n²)           | O(1)             |
| Worst Case    | O(n²)           | O(1)             |

# When to Use:
- Small datasets (n < 50)
- Nearly sorted data
- Online sorting (data arrives in real-time)
- When stability is required
- When simplicity and low space overhead are priorities

# Stability: **STABLE**
# In-Place: **YES**
