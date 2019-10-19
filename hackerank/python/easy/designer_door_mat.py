if __name__ == "__main__":
    height, width = int(input())
    width = height * 3
    increment_bar = -3
    no_bar = int(width / 2) - 1

    for row in range(height):
        if no_bar != 0:
            no_mark = int((width - 2 * no_bar) / 3)
            bar = '-' * no_bar
            mark = '.|.' * no_mark

        else:
            increment_bar *= -1
            bar_length = (int)((width - len("WELCOME")) / 2)
            bar = '-' * bar_length
            mark = 'WELCOME'

        no_bar += increment_bar
        print(bar + mark + bar)
