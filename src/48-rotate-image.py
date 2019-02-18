# 48. Rotate Image

from math import floor

class Solution:
    def rotate(self, matrix: 'List[List[int]]') -> 'None':
        """
        Do not return anything, modify matrix in-place instead.
        """
        size = len(matrix)

        for i in range(0, floor(size / 2)):
            for j in range(0, size):
                matrix[i][j] ^= matrix[size - 1 - i][j]
                matrix[size - 1 - i][j] ^= matrix[i][j]
                matrix[i][j] ^= matrix[size - 1 - i][j]
        for i in range(0, size):
            for j in range(i + 1, size):
                matrix[i][j] ^= matrix[j][i]
                matrix[j][i] ^= matrix[i][j]
                matrix[i][j] ^= matrix[j][i]

    # [
    #   [ 5, 1, 9,11],    [15,14,12,16],
    #   [ 2, 4, 8,10],    [13, 3, 6, 7],
    #   [13, 3, 6, 7],    [ 2, 4, 8,10],
    #   [15,14,12,16]     [ 5, 1, 9,11],
    # ],
    # [
    #   [15,13, 2, 5],   0,0->0,n-1 0,1->1,n-1 0,2->2,n-1
    #   [14, 3, 4, 1],   1,0->0,n-2 1,1->1,n-2 1,2->2,n-2
    #   [12, 6, 8, 9],
    #   [16, 7,10,11]
    # ]


if __name__ == "__main__":
    import time
    start = time.clock()

    matrix1 = [
      [1,2,3,10,55],
      [4,5,6,11,66],
      [7,8,9,12,77],
      [12,42,53,90,88],
      [91,13,76,65,35]
    ]
    matrix2 = [
      [ 5, 1, 9,11],
      [ 2, 4, 8,10],
      [13, 3, 6, 7],
      [15,14,12,16]
    ]

    s = Solution()
    ans = s.rotate(matrix2)
    print(matrix2)

    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))

