# finding the start index and end index of a particular target element

def find_the_range(A, K):
    N = len(A)
    left , right = 0 , N-1
    ind = -1
    while left < right:
        mid = (left + right)//2
        if A[mid] == K:
            ind = mid
            break
        elif A[mid] < K:
            left = mid+1
        else:
            right = mid
    startInd, endInd = -1,-1 
    if ind != -1:
        while ind > 0 and A[ind] == A[ind -1]:
            ind -= 1
        startInd = ind
        while ind < N-1 and A[ind] == A[ind + 1]:
            ind += 1
        endInd = ind
    else:
        return -1
    return startInd, endInd


def get_the_range_mod(A, K):
    N = len(A)
    left ,right = 0 , N-1
    ind = -1
    while left < right:
        mid = (left + right)//2
        if  A[mid] == K:
            ind = mid
            break
        elif A[mid] < K:
            left = mid + 1
        else:
            right = mid
    start_ind, end_ind = -1 , -1
    if ind != -1:
        while ind > 0 and A[ind] == A[ind-1]:
            ind -= 1
        start_ind = ind
        while ind < N-1 and A[ind] == A[ind+1]:
            ind += 1
        end_ind = ind
        return start_ind, end_ind
        # print(end_ind)
    else:
        return -1



A = [1,2,3, 3, 3]
print(A)
K = 3
print(get_the_range_mod(A, K))



