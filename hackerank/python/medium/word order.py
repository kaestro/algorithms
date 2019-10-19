if __name__ == "__main__":
    word_occurence = {}
    for _ in range(int(input())):
        word = input()
        if word in word_occurence:
            word_occurence[word] += 1 
        else:
            word_occurence[word] = 1
    
    print(len(word_occurence))
    print(" ".join(str(x) for x in word_occurence.values()))