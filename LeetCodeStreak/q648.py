# import the List module
from typing import List

def replaceWords(dictionary: List[str], sentence: str) -> str:
    list_deri = sentence.split(' ')
#   declare a set s
    s = set(dictionary)
    ans = []
    for word in list_deri:
        prefix = ''
        for i in range(len(word)+1):
            prefix = word[:i]
            if prefix in s:
                break
        ans.append(prefix)
    return ' '.join(ans)

dictionary = ["cat","bat","rat"]
sentence = "the cattle was rattled by the battery"
print(replaceWords(dictionary, sentence))