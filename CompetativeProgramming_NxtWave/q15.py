# return the no of submatrices whose sum is K
# return the larget or smallest area of the submatrix whose sum is k
# return the left right top down indexes of the largest area submatrix with the given sum K

def count_subarray_sum(rowsCol, K):
    N = len(rowsCol)
    print("rows Col",rowsCol)
    count = 0
    for i in range(N):
        cur_sum = 0
        for j in range(i, N):
            cur_sum += rowsCol[j]
            if cur_sum == K:
                count += 1
    return count



def count_sub_matrix(matrix,K):
    M = len(matrix)
    N = len(matrix[0])
    # print(M , N)
    # preffix sum matrix
    for i in range(M):
        for j in range(1,N):
            matrix[i][j] += matrix[i][j-1]
    ans = 0
    # print(matrix)
    for col1 in range(N):
        for col2 in range(col1,N):
            rowsCol = [0 for _ in range(M)]
            # print(rowsCol)
            for k in range(M):
                if col1 == 0:
                    rowsCol[k] = matrix[k][col2]
                else:
                    rowsCol[k] = matrix[k][col2] - matrix[k][col1-1]
            # print(rowsCol)
            ans += count_subarray_sum(rowsCol, K)
    return ans
                    
    
def largest_submatrix(rowsCol , K, col1, col2):
    N = len(rowsCol)
    max_area = 0
    for i in range(N):
        cur_sum = 0
        for j in range(i, N):
            cur_sum += rowsCol[j]
            if cur_sum == K:
                max_area = max(max_area, (col2 - col1 + 1)*(j - i + 1))
    return max_area




def largest_area_sub_matrix(matrix,K):
    M = len(matrix)
    N = len(matrix[0])
    # preffix sum matrix
    for i in range(M):
        for j in range(1,N):
            matrix[i][j] += matrix[i][j-1]
    ans = 0
    # print(matrix)
    for col1 in range(N):
        for col2 in range(col1,N):
            rowsCol = [0 for _ in range(M)]
            # print(rowsCol)
            for k in range(M):
                if col1 == 0:
                    rowsCol[k] = matrix[k][col2]
                else:
                    rowsCol[k] = matrix[k][col2] - matrix[k][col1-1]
            ans = max(ans, largest_submatrix(rowsCol,K, col1, col2))
            # print(rowsCol)
            
    return ans


# M, N, K = map(int , input().split())
# matrix = []
# for i in range(M):
#     matrix.append(list(map(int , input().split())))
# print(count_sub_matrix(matrix, K))
M , N , K = 3,3,2
matrix = [[1,0,1],[3,-1, -2],[2, 5, 6]]
# print(matrix)
# print(count_subarray_sum([1,2,3], 3))
# print(count_sub_matrix(matrix, K))
print(largest_area_sub_matrix(matrix,K))