def knapsack_dp(n, weights, values, total_W, dp):
    if n < 0 or total_W == 0:
        return 0
    
    if dp[n][total_W] != -1:
        return dp[n][total_W]
    
    if weights[n] <= total_W:
        selected = knapsack_dp(n-1, weights, values, total_W - weights[n], dp) + values[n]
        not_selected = knapsack_dp(n-1, weights, values, total_W, dp)
        dp[n][total_W] = max(selected, not_selected)
    else:
        dp[n][total_W] = knapsack_dp(n-1, weights, values, total_W, dp)
    
    return dp[n][total_W]


def main():
    n = int(input())
    weights = list(map(int, input().split()))
    values = list(map(int, input().split()))
    total_W = int(input())
    
    dp = [[-1 for _ in range(total_W + 1)] for _ in range(n)]
    
    result = knapsack_dp(n-1, weights, values, total_W, dp)
    print(result)


if __name__ == "__main__":
    main()
