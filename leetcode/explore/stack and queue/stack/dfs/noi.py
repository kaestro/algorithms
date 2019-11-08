from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        height = len(grid)
        if height == 0: return 0
        width = len(grid[0])
        if width == 0: return 0

        def sink(row, col):
            if grid[row][col] == "1":
                grid[row][col] = "0"
                for nr, nc in [(row-1,col), (row,col+1), (row+1,col), (row,col-1)]:
                    if 0 <= nr < height and 0 <= nc < width:
                        sink(nr,nc)
                return 1
            return 0
        
        noi = 0
        for row in range(height):
            for col in range(width):
                noi += sink(row, col)
        return noi

if __name__ == "__main__":
    input = [
        ["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"]
    ]

    print(Solution().numIslands(input))

    input2 = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"]
    ]

    print(Solution().numIslands(input2))