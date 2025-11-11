# Experiment No : 08

# Experiment Name : Radix Sort Algorithm

# Setup :
  - VsCode Editor, Python 3.x installed system
  - Create a new Python file named `radix_sort.py`
  - Open the file in VsCode Editor
  
# Procedure :
    1. Define a function `radix_sort(arr)` that sorts an array using the radix sort algorithm.
    2. Find the maximum element in the array to determine the number of digits.
    3. Define a `counting_sort(arr, exp)` function that sorts based on a specific digit position.
    4. Start from the least significant digit (LSD) and move to the most significant digit (MSD).
    5. For each digit position, use counting sort as a subroutine to sort elements.
    6. Count the occurrences of each digit (0-9) at the current position.
    7. Build the output array by placing elements in sorted order based on current digit.
    8. Copy the output array back to the original array.
    9. Repeat for all digit positions until the most significant digit is processed.
    10. Read input array from user and call radix_sort function.
    11. Print the sorted array.

# Discussion and Application
    - Radix Sort is a non-comparative sorting algorithm that sorts integers by processing individual digits from least significant to most significant. **Stability: STABLE** - Radix sort is stable because the underlying counting sort is stable. When two numbers have the same digit at the current position, their relative order is preserved.
    - Time complexity is O(d × (n + k)) where d is number of digits, n is number of elements, and k is the range of input (0-9 for decimal). Works efficiently for integers and strings with fixed-length keys, achieving linear time when d is constant. Not suitable for floating-point numbers or when the range of digits is very large relative to n. Requires extra space for counting and output arrays. Can be implemented with LSD (Least Significant Digit) or MSD (Most Significant Digit) approach. One of the few sorting algorithms that can beat the O(n log n) comparison-based sorting lower bound.
    - Applications include parallel computing (sorting large integer datasets on GPUs), string sorting (fixed-length strings like phone numbers, zip codes, IDs), database systems (sorting integer keys, creating indexes), network routing (IP address sorting and routing tables), suffix array construction (text processing and pattern matching), computer graphics (Z-buffer sorting for 3D rendering), big data (Hadoop and Spark use radix sort for shuffle operations), cryptography (sorting hash values, key management), telecommunications (sorting call records, billing systems), and scientific computing (sorting measurement data with fixed precision).
    - Learning outcomes: Understand non-comparative sorting algorithms, learn digit-by-digit processing techniques, master the relationship between radix and counting sort, understand when to use radix sort vs comparison-based sorts, analyze time complexity with multiple parameters (n, d, k), learn stable sorting implementation, understand time-space trade-offs, and learn how to beat the O(n log n) comparison-based sorting lower bound.

# Sorting Process Visualization:
For array [170, 45, 75, 90, 802, 24, 2, 66]:
```
Original:           [170, 45, 75, 90, 802, 24, 2, 66]

Pass 1 (Ones):      [170, 90, 802, 2, 24, 45, 75, 66]
  Sorting by digit at position 1 (1's place)
  Buckets:
    0: [170, 90]
    2: [802, 2]
    4: [24]
    5: [45, 75]
    6: [66]

Pass 2 (Tens):      [802, 2, 24, 45, 66, 170, 75, 90]
  Sorting by digit at position 10 (10's place)
  Buckets:
    0: [802, 2]
    2: [24]
    4: [45]
    6: [66]
    7: [170, 75]
    9: [90]

Pass 3 (Hundreds):  [2, 24, 45, 66, 75, 90, 170, 802]
  Sorting by digit at position 100 (100's place)
  Buckets:
    0: [2, 24, 45, 66, 75, 90]
    1: [170]
    8: [802]
```

# Step-by-Step Execution Table:
```
Pass | Digit Position | Array State                    | Explanation
-----|----------------|--------------------------------|------------------
0    | -              | [170,45,75,90,802,24,2,66]    | Original
1    | 1 (ones)       | [170,90,802,2,24,45,75,66]    | Sort by ones digit
2    | 10 (tens)      | [802,2,24,45,66,170,75,90]    | Sort by tens digit
3    | 100 (hundreds) | [2,24,45,66,75,90,170,802]    | Sort by hundreds
```

# Counting Sort Subroutine Example:
For sorting by ones digit [170, 45, 75, 90]:
```
Step 1 - Extract digits:  [0, 5, 5, 0]
Step 2 - Count array:     count[0]=2, count[5]=2
Step 3 - Cumulative:      count[0]=2, count[5]=4
Step 4 - Build output:    [170, 90, 45, 75]
```

# Code :
```python
def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n  
    count = [0] * 10  
    
    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1
    
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1
    
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    max_element = max(arr)
    
    exp = 1
    while max_element // exp > 0:
        counting_sort(arr, exp)
        exp *= 10
    
    return arr

def main():
    arr = list(map(int, input("Enter array elements separated by space: ").split()))
    
    print(f"Original array: {arr}")
    radix_sort(arr)
    print(f"Sorted array: {arr}")

if __name__ == "__main__":
    main()
```

# Input Example:
```
Enter array elements separated by space: 170 45 75 90 802 24 2 66
```

# Output Example:
```
Original array: [170, 45, 75, 90, 802, 24, 2, 66]
Sorted array: [2, 24, 45, 66, 75, 90, 170, 802]
```

# Complexity Analysis:
| Case          | Time Complexity | Space Complexity |
|---------------|-----------------|------------------|
| Best Case     | O(d × (n + k))  | O(n + k)         |
| Average Case  | O(d × (n + k))  | O(n + k)         |
| Worst Case    | O(d × (n + k))  | O(n + k)         |

Where:
- d = number of digits in the maximum number
- n = number of elements
- k = range of digits (10 for decimal system)

# Advantages:
- Linear time complexity when d is constant
- Stable sorting algorithm
- No comparisons needed
- Efficient for large datasets with small digit ranges

# Disadvantages:
- Requires extra space
- Only works with integers or fixed-length strings
- Not suitable when d (number of digits) is very large
- Performance depends on the number of digits

# Stability: **STABLE**
# In-Place: **NO** (requires extra space)
