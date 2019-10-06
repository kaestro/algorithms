from typing import List
import math

class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        rowMax = len(grid)
        colMax = len(grid[0])
        def dfs(row: int, col: int, visited):
            if not (0 <= row < rowMax and 0 <= col < colMax and grid[row][col] != 0 and (row, col) not in visited):
                return -math.inf
            visited.add((row, col))
            res = grid[row][col] + max(0, max(dfs(row + dr, col + dc, visited) for dr, dc in [[-1, 0], [1, 0], [0, -1], [0, 1]]))
            visited.remove(row, col)
            return res
        return max(dfs(i,j, set()) for i in range(rowMax) for j in range(colMax))