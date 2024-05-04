#prefix sum
# maintaining profix sum in place
A = [1,2,3,4]
Q = { 0:2, 2:3}
print(A)
N = len(A)
for i in range(1,N):
    A[i] += A[i-1]
print(A)

print(Q.get(0))

for left, right in Q.items():
    print(left, " ", right)
    if left == 0:
        print(A[right])
    else:
        print(A[right] - A[left-1])