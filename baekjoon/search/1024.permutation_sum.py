if __name__ == "__main__":
    goal, min_length = map(int, input().split())
    first_element = -1
    min_permutation_length = 0

    for permutation_length in range(min_length, 101):
        # pl * (pl - 1) / 2 for the minimum possible value is 0(unsinged int)
        min_permutation_sum = permutation_length * (permutation_length - 1) / 2

        if min_permutation_sum > goal:
            break

        if (goal - min_permutation_sum) % permutation_length == 0:
            # sum = sum + permutation length when first_element = first_element + 1
            first_element = int((goal - min_permutation_sum) / permutation_length)
            min_permutation_length = permutation_length
            break
    
    if first_element == -1:
        print(-1)
    else:
        print(' '.join(str(first_element + i) for i in range(0, min_permutation_length)))