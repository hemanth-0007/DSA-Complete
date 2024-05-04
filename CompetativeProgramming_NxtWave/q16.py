# Rain water trap problem

def trap(height):
    N = len(height)
    left, right = 0 , N-1
    ans = 0
    left_max, right_max = 0,0
    while left < right:
        if height[left] <= height[right]:
            if height[left] > left_max:
                left_max = height[left]
            ans += (left_max - height[left])
            left += 1
        elif height[left] > height[right]:
            if height[right] > right_max:
                right_max = height[right]
            ans += (right_max - height[right])
            right -= 1
    return ans



# N = int(input())
# height = list(map(int , input().split()))
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(trap(height))