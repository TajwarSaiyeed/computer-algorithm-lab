# Experiment No : 06

# Experiment Name : Radix Sort Algorithm

# Setup :

- VsCode Editor, Python 3.x installed system
- Create a new Python file named `radix_sort.py`
- Open the file in VsCode Editor

# Procedure :

    1. Define `counting_sort(arr, exp)` function to sort by specific digit position
    2. Define `radix_sort(arr)` function using radix sort algorithm
    3. Find maximum element to determine number of digits
    4. Loop through each digit position (LSD to MSD) using counting sort
    5. Get user input array and call radix_sort function
    6. Print the sorted array

# Discussion

    - Radix Sort is a non-comparative sorting algorithm with O(d × (n + k)) time complexity where d is number of digits, n is number of elements, and k is the range (0-9 for decimal). It's stable because counting sort preserves relative order of equal elements. The algorithm processes digits from least significant to most significant, using counting sort as a subroutine. Requires O(n + k) extra space for counting and output arrays.

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
    arr = list(map(int, input("Input : ").split()))
    radix_sort(arr)
    print(f"Sorted array: {arr}")

if __name__ == "__main__":
    main()

# Output:
Input : [170, 45, 75, 90, 802, 24, 2, 66]
Sorted array: [2, 24, 45, 66, 75, 90, 170, 802]
```

# Complexity Analysis:

| Case         | Time Complexity | Space Complexity |
| ------------ | --------------- | ---------------- |
| Best Case    | O(d × (n + k))  | O(n + k)         |
| Average Case | O(d × (n + k))  | O(n + k)         |
| Worst Case   | O(d × (n + k))  | O(n + k)         |

# Stability: **STABLE**
