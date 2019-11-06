from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row_size = len(grid)
        if row_size == 0:
            return 0
        col_size = len(grid[0])
        if col_size == 0:
            return 0
        def sink(row, col):
            if 0 <= row < row_size and 0 <= col < col_size and grid[row][col] == "1":
                grid[row][col] = "0"
                for nr, nc in [(row-1,col), (row,col+1), (row+1,col), (row,col-1)]:
                    sink(nr, nc)
                return 1
            else:
                return 0
        
        ans = 0
        for row in range(row_size):
            for col in range(col_size):
                ans += sink(row,col)
        return ans


if __name__ == "__main__":
    grid = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
    print(Solution().numIslands(grid))