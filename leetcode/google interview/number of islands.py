from typing import List

class Solution:

    
    def __init__(self):
        self.map = List[List[str]]()

    def numIslands(self, grid: List[List[str]]) -> int:
        map = grid

    
    def moveToNextGrid(self, rowIdx, colIdx):