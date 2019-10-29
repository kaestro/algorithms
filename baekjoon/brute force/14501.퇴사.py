if __name__ == "__main__":
    appointments = []
    for _ in range(int(input())):
        # can be replaced with line = map(int, input().split(' '))
        line = [int(x) for x in input().split(' ')]
        appointments.append({'duration':line[0], 'price':line[1]})

    max_profit = [0]
    for i in range(len(appointments) + 1):
        for j in range(0, i):
            if (j + appointments[j]['duration'] == i):
                max_profit[i] = max(max_profit[i], max_profit[j] + appointments[j]['price'])
        max_profit.append(max(max_profit))
    
    print(max(max_profit))

def another():
    input_size = int(input())
    max_profit_at = [0] * 30
    last_max_profit = max_profit_at[0]
    for start_date in range(0, input_size):
        duration, price = map(int, input().split())
        finish_date = start_date + duration
        max_profit_at[finish_date] = max(max_profit_at[finish_date], last_max_profit + price)
        last_max_profit = max(last_max_profit, max_profit_at[start_date])
    print(last_max_profit)
