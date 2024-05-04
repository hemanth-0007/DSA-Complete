
def peekElements(A, N):
    flag = 0
    for i in range(1, N-1):
        if A[i-1] < A[i] and A[i] > A[i+1]:
            flag = 1
            print(i, end=" ")
    if flag == 0:
        print(-1, end=" ")




if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split(" ")))
    peekElements(A, N)