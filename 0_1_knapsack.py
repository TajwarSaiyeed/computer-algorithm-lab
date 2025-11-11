def knapsack(n, weights, values, total_W):
    if n < 0 or total_W == 0:
        return 0


    if weights[n] <= total_W:
        selected = knapsack(n-1,weights, values, total_W - weights[n]) + values[n]
        
        not_selected = knapsack(n-1, weights, values, total_W)
        return max(selected, not_selected)
    else :
        return knapsack(n-1, weights, values, total_W)


def main():
    n = int(input())
    weights = list(map(int, input().split()))
    values = list(map(int, input().split()))

    total_W = int(input())
    print(knapsack(n-1, weights, values, total_W))


if __name__ == "__main__":
    main()