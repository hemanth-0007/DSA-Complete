def zeros_matrix_optimal(matrix):
    col = 1
    N = len(matrix)
    M = len(matrix[0])
    # first you iterate for the 0 th row and 0 th column and 
    # mark the matrix[0][0] and col variables
    for i in range(0, N):
        if matrix[i][0] == 0:
            col = 0
            break
    for j in range(1, M):
        if matrix[0][j] == 0:
            matrix[0][0] = 0
            break
    # now you iterate from the 1 to N and 1 to M for matrix
    for i in range(1, N):
        for j in range(1, M):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    # based on the 0 th row and 0th col we update the (N-1)x(M-1) matrix
    for i in range(1, N):
        for j in range(1, M):
            if matrix[0][j] == 0 or matrix[i][0] == 0:
                matrix[i][j] = 0
    # ** very very imp first you solve for 0 th row and then 0 th column
    if matrix[0][0] == 0:
        for j in range(1, M):
            matrix[0][j] = 0
    if col == 0:
        for i in range(0,N):
            matrix[i][0] = 0
    
    return matrix

# two array method
def zeros_matrix(matrix):
    N = len(matrix)
    M = len(matrix[0])
    zero_row = [1]*M
    zero_col = [1]*N
    for i in range(N):
        for j in range(M):
            if matrix[i][j] == 0:
                zero_row[j] = 0
                zero_col[i] = 0
    for i in range(N):
        for j in range(M):
            if zero_col[i] == 0 or zero_row[j] == 0:
                matrix[i][j] = 0
    return matrix



def print_matrix(matrix):
    for row in matrix:
        print(row)
    return



# M , N = map(int , input().split(" "))
matrix = [[0,1,1,1], [1,1,1,1], [1,1,0,1],[1,1,1,1]]
# for i in range(M):
#     matrix.append(list(map(int , input().split(" "))))
print_matrix(matrix)
print(" ")
print_matrix(zeros_matrix(matrix))