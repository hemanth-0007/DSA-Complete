# return subarray whose sum is K
# assumming all the positive numbers
def subarray_sum(nums, K):
    N = len(nums)
    left, right = 0,0
    sum = nums[0]
    while left < N and right < N:
        if sum == K:
            return nums[left:right+1]
            # return right - left + 1
        elif sum < K:
            right += 1
            sum += nums[right]
        elif sum > K:
            sum -= nums[left]
            left += 1
    return -1
        



nums = [10,44,20,2,10,5]
K = 32

print(subarray_sum(nums, K))