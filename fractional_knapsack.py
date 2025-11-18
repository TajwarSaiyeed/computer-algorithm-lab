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