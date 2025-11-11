def quick_sort(arr, l, r):
    if l < r:
        x = part(arr, l, r)
        quick_sort(arr, l, x - 1)
        quick_sort(arr, x + 1, r)

def part(arr, l, r):
    pivot = arr[l]
    l_p = l + 1
    r_p = r

    while (l_p <= r_p):
        while l_p <= r and arr[l_p] <= pivot:
            l_p += 1

        while r_p >= l and arr[r_p] > pivot:
            r_p -= 1

        if l_p < r_p:
            arr[l_p], arr[r_p] = arr[r_p], arr[l_p]
        elif l_p >= r_p:
            arr[l], arr[r_p] = arr[r_p], arr[l]
    
    return r_p


def main():
    arr = [3, 6, 8, 10, 1, 2, 1]
    quick_sort(arr, 0, len(arr) - 1)
    print("Sorted array:", arr)


if __name__ == "__main__":
    main()