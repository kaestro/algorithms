def solution(priorities, location):
    answer = 0
    sortedPriorities = sorted(priorities, reverse = True)
    printed = False
    while not printed:
        for i, priority in enumerate(priorities):
            if priority == sortedPriorities[0]:
                sortedPriorities.pop(0)
                answer += 1
                if i == location:
                    printed = True
                    break
            else:
                continue
    return answer