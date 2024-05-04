def find_pivot_index(arr, low, high):
    mid = int((low + high)/2)
    print(low, " ", mid, " ",high)
    if high < low:
        return -1
    if high == low:
        return low
    # definitely low < high
    if mid < high and arr[mid] > arr[mid+1]:
        return mid
    if mid > low and arr[mid - 1] > arr[mid]:
        return mid-1
    if arr[low] >= arr[mid]:
        return find_pivot_index(arr, low, mid-1)
    return find_pivot_index(arr, mid+1, high)

def find_pivot_index_itr(arr, low, high):
    while low < high:
        mid = int((low + high)/2)
        print(low, " ", mid, " ", high)
        if low < mid and arr[mid-1] > arr[mid]:
            return mid - 1
        if mid < high and arr[mid] > arr[mid+1]:
            return mid
        if arr[low] >= arr[mid]:
            high = mid-1
        else:
            low = mid+1
    if low == high:
        return low
    if low > high:
        return -1

if __name__ == '__main__':
    # n = int(input())
    # arr = list(map(int, input().split()))
    # arr = [3,4,5,6,7,1,2]
    # arr = [1,2 ,3 ,4, 5, 6]
    arr = [6, 5,4, 3, 2, 1]
    print(arr)
    pivot = find_pivot_index(arr, 0 , len(arr)-1)
    print(pivot)
    pivot = find_pivot_index_itr(arr, 0 , len(arr)-1)
    print(pivot)