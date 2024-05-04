# triplet sum = k print the triplets in the list

def triplets(array, K):
    N = len(array)
    req_triplets = []
    array.sort()  # Sort the array to simplify the search
    for i in range(N - 2):
        temp = array[i]
        left, right = i + 1, N - 1
        req_sum = K - temp
        while left < right:
            temp_sum = array[left] + array[right]
            if temp_sum > req_sum:
                right -= 1
            elif temp_sum < req_sum:
                left += 1
            else:
                req_triplets.append([temp, array[left], array[right]])
                left += 1
                right -= 1
    return req_triplets


K = 0
array = [-3, -2, -1, 0, 1, 2, 3]
my_triplets = triplets(array, K)
for triplet in my_triplets:
        print(triplet)


