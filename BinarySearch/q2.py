# finding the lower bound of a  element  X in the array A

def lower_bound(A, X):
    N = len(A)
    left , right = 0 , N-1
    while left <= right:
        mid = (left + right)//2
        if A[mid] >= X:
            right = mid - 1
        else:
            left = mid + 1
    return left if not N == left else -1



def upper_bound(A, X):
    N = len(A)
    left , right = 0 , N-1
    ans = N
    while left <= right:
        mid = (left + right)//2
        if A[mid] > X:
            right = mid - 1
            ans = mid
        else:
            left = mid + 1
    return ans


def search_insert_position(A, X):
    N = len(A)
    left , right = 0 , N-1
    ans = N
    while left <= right:
        mid = (left + right)//2
        if A[mid] > X:
            right = mid - 1
            ans = mid
        elif A[mid] < X:
            left = mid + 1
        else:
            return mid
    return ans


# A = [3,5,8,15,19,19,19,19]
A = [1,3,4,5,7,8,10]
print(upper_bound(A,0))