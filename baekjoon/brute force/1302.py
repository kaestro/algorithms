from collections import defaultdict

def best_seller(num_sold):
    book_count = defaultdict(int)
    for _ in range(num_sold):
        book_count[input()] += 1
    
    # return max(book_count, key=lambda k: book_count[k])
    # max_key, max_val = max(book_count.items())
    # max_key, max_val = max(book_count, key=lambda k: book_count[k])
    max_val = max(book_count.values())
    book_names = []
    for key, value in book_count.items():
        if value == max_val:
            book_names.append(key)
    
    return min(book_names)


if __name__ == "__main__":
    print(best_seller(int(input())))


# originally I tried
# max_key, max_val = max(book_count.items())
# for key, value in book_count.items():
# if value == max_val and key < max_key
#   max_key = key
# what was wrong with this?