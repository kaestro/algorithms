class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        cur, cnt, n, seen = [(0, 0, 0)], 0, len(grid),set([0, 0, 0])
        while cur and (n - 1, n - 2, 0) not in cur:
            cnt, tmp = cnt + 1, []
            for x, y, dx in cur:
                if dx == 0:
                    if y + 2 < n and grid[x][y + 2] == 0:
                        tmp += [(x, y + 1, 0)]
                    if x < n - 1 and (grid[x + 1][y] + grid[x + 1][y + 1]) == 0:
                        tmp += [(x, y, 1), (x + 1, y, 0)]
                else:
                    if x + 2 < n and grid[x + 2][y] == 0:
                        tmp += [(x + 1, y, 1)]
                    if y < n - 1 and (grid[x][y + 1] + grid[x + 1][y + 1] == 0):
                        tmp += [(x, y, 0), (x, y + 1, 1)]
            cur = set(tmp) - seen
            seen |= cur
        return cnt if cur else -1