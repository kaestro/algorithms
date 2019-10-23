from typing import List

class Solution:


    def init(self):
        jumpBoard = List[int]()

    def oddEvenJumps(self, A: List[int]) -> int:
        count = 0
        jumpBoard = A
        for index in range(len(A)):
            if reachedEnd(index): count += 1
        
        return count
    

    def reachedEnd(self, index: int) -> bool:
        
