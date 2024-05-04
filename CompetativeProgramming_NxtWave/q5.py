import numpy as np

def shift_array_right(arr, k):
    n = len(arr)
    k = k % n
    # reverse only upto n - k -1 elements
    arr[:n-k] = arr[:n-k][::-1]
    arr[n-k:] = arr[n-k:][::-1]
    arr.reverse()
    print(arr)    

if __name__ == "__main__":
    # n = int(input())
    # arr = list(map(int, input().split()))
    arr = [1, 2, 3, 4, 5, 6, 7]
    # k = int(input())
    k = 3
    shift_array_right(arr, k)