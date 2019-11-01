class Solution:

    def __init__(self):
        self.row_size = 0
        self.col_size = 0


    def numIslands(self, grid: List[List[str]]) -> int:
        num_islands = 0
        self.row_size = len(grid)
        if self.row_size == 0:
            return 0
        self.col_size = len(grid[0])
        if self.col_size == 0:
            return 0
        
        for row in range(self.row_size):
            for col in range(self.col_size):
                if grid[row][col] == "1":
                    self.bfs(row, col, grid)
                    num_islands += 1
        return num_islands


    def bfs(self, row, col, grid) -> None:
        grid[row][col] = "0"
        for nr, nc in (row-1, col), (row, col+1), (row+1, col), (row, col-1):
            if 0 <= nr < self.row_size and 0 <= nc < self.col_size:
                if grid[nr][nc] == "1":
                    self.bfs(nr, nc, grid)