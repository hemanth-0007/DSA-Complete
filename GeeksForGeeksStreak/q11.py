
def min_spinklers(gallery):
    N = len(gallery)
    coverage  = [-1 for _ in range(N)]
    for ind, num in enumerate(gallery):
        if num != -1:
            left = max(0, ind - gallery[ind])
            right = min(N,ind + gallery[ind])
            for j in range(left, right):
                coverage[j] = max(coverage[j], right-1)
    return coverage





gallery = [-1, 2, 2, -1, 0, 0]
print(min_spinklers(gallery))
# for ind, num in enumerate(gallery):
#     print(ind, num)