
def max_score(s):
    zeros, ones = 0, 0
    N = len(s)
    for i in range(N):
        if s[i] == "0":
            zeros += 1
        else:
            ones += 1
    cur_ones = 1 if s[0] == "1" else 0
    cur_zeros = 1 if s[0] == "0" else 0
    max_score = (1 + ones) if s[0] == "0" else (ones - 1)
    for i in range(1,N-1):
        if s[i] == "0":
            cur_zeros += 1
        else:
            cur_ones += 1
        max_score = max(max_score,cur_zeros + (ones - cur_ones))
    return max_score
            

    # get max score








# s = "011101"
s = "00"
print(max_score(s))