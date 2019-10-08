from typing import List

def solution(phone_book : List[str]):
    answer = True
    phone_book.sort()
    for i in range(len(phone_book) - 1):
        if phone_book[i] == phone_book[i + 1][0:len(phone_book[i])]:
            return False
    return answer