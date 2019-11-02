def solution(clothes):
    answer = 1
    result = {}
    for value, key in clothes:
        result[key] = result[key] + 1 if key in result else 1
    for key, value in result.items():
        answer *= (value + 1)
    return answer - 1

if __name__ == "__main__":
    clothes = [["yellow_hat", "headgear"]]
    solution(clothes)