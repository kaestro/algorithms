def max_profit(end_date):
    max_profits = [0] * 20
    cur_max = 0
    for i in range(end_date):
        date, profit = map(int, input().split(' '))
        max_val = max(max_profits[i], cur_max)
        cur_max, max_profits[i] = max_val, max_val
        max_profits[i + date] = max(max_profits[i + date], cur_max + profit)
    return max(cur_max, max_profits[end_date])

if __name__ == "__main__":
    print(max_profit(int(input())))