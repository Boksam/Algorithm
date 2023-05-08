
basic = [[1, 1], [1, 0]]

def matrix_mul(mat1, mat2):
    result = [[0 for _ in range(2)] for _ in range(2)]
    result[0][0] = (mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0]) % 1000000007
    result[0][1] = (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]) % 1000000007
    result[1][0] = (mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0]) % 1000000007
    result[1][1] = (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1]) % 1000000007
    return result

def fibonachi(n):
    if n == 1:
        return basic
    
    if n % 2 == 0:
        tmp = fibonachi(n // 2)
        return matrix_mul(tmp, tmp)
    else:
        tmp = fibonachi(n // 2)
        return matrix_mul(matrix_mul(tmp, tmp), basic)
    
n = int(input())
result = fibonachi(n)
print(result[0][1])