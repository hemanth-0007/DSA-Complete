# Finding the peek element

def get_peek_element(A, N):
    for i in range(N-1):
        if A[i] > A[i+1]:
            return i
    return N-1

def get_peek_index_bin(A, N):
    low, high = 0 , N-1
    while low < high:
        mid = (low + high)//2
        print(low , mid , high)
        if A[mid] < A[mid + 1]:
            low = mid + 1
        else:
            high = mid
    return low


# N = int(input())
# A = list(map(int, input().split()))


A = [4,5 , 3,2, 7, 6 ]
N = len(A)
print(A)
# print(get_peek_element(A, N))
# O(N)
print(get_peek_index_bin(A, N))
# O(logN)