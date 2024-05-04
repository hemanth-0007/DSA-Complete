# kadanes algo 

def max_subarray_sum_mod(A):
    cur_sum,max_sum = 0, float("-inf")
    max_num = float("-inf")
    for num in A:
        cur_sum += num
        max_num = max(max_num, num)
        # you wont carry the subarray sum that doesnot add up to our subarray that is if it is negative 
        if cur_sum < 0:
            cur_sum = 0
        max_sum = max(max_sum, cur_sum)
    return max_num if max_sum == 0 else max_sum


def max_subarray_sum(A):
    # max_sum should be inital element
    max_sum, cur_max = A[0],0
    for num in A:
        # this current max only carries max
        cur_max = max(cur_max + num, num)
        max_sum = max(cur_max, max_sum)
    return max_sum

def min_subarray_sum(A):
    cur_min, min_sum = 0 , A[0]
    for num in A:
        cur_min = min(cur_min + num , num)
        min_sum = min(cur_min, min_sum)
    return min_sum


def max_circular_subarray_sum(A):
    cur_min, cur_max, total_sum = 0,0,0
    max_sum , min_sum = A[0], A[0]
    for num in A:
        cur_min = min(cur_min + num, num)
        min_sum = min(min_sum , cur_min)
        cur_max = max(cur_max + num, num)
        max_sum = max(cur_max, max_sum)
        total_sum += num
    if max_sum > 0:
        return max(max_sum , total_sum - min_sum)
    else:
        return max_sum

# N = int(input())

A = [1,2,2,4, -7 , -6, 10]
print(max_subarray_sum(A))
# print(max_subarray_sum_mod(A))
print(max_circular_subarray_sum(A))