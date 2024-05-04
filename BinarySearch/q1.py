def binary_search(A, X):
    N = len(A)
    left, right = 0 , N-1
    while left <= right:
        mid = (left + right)//2
        if A[mid] > X:
            right = mid - 1
        elif A[mid] < X:
            left = mid + 1
        else:
            return mid
    return -1



A = [1,2, 3,4, 5,6,7]
print(binary_search(A,10))