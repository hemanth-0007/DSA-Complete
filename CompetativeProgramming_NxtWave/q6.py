
def kClosestElements(A, N , K , X):
    # code here
    left = 0
    right = N-1
    while left < right:
        # print("left : ",left,"right : ", right)
        if right - left + 1 == K:
            break
        elif right - left + 1 > K:
            if abs(A[left] - X) > abs(A[right] - X):
                left += 1
            else:
                right -= 1
    return A[left:right+1]


# sliding window approach
def kClosestElements_mod(A, N , K , X):
    total_dis =0
    min_total_dis = 0
    for i in range(K):
        total_dis += abs(A[i] - X)
    min_total_dis = total_dis
    for i in range(K, N):
        total_dis += abs(A[i] - X) - abs(A[i-K] - X)
        if total_dis <= min_total_dis:
            min_total_dis = total_dis
            continue
        else:
            print(A[i-K:i])
            break
    return
    

# N,K,X = map(int,input().split(" "))
# A = list(map(int,input().split(" ")))
N,K,X = 5, 2, 8
A = [1,3, 6, 7, 10]
print(A)
print(kClosestElements(A, N, K, X))
kClosestElements_mod(A, N, K, X)