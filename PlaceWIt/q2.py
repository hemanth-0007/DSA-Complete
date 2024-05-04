
def countLargestSet(words):
    n = len(words)
    # i want a set
    set1 = set()
    for i in range(n):
        for j in range(n):
            if i != j:
                if words[i] not in words[j] and words[j] not in words[i]:
                    set1.add(words[i])
                    set1.add(words[j])
    pass

if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())
    print(countLargestSet(words))