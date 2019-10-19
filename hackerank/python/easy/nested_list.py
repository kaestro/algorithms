from collections import OrderedDict

if __name__ == '__main__':
    students = {}
    scores = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students[name] = score
        scores.append(score)
    
    scores = set(scores)
    scores = list(scores)
    scores = sorted(scores)
    orderedStudents = OrderedDict(sorted(students.items()))

    # print(key for key, val in students if val == scores[1])
    for key, val in orderedStudents.items():
        if val == scores[1]:
            print(key)
