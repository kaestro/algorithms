from collections import deque

class MovingAverage:

    def __init__(self, size: int):
        self.dq = dequeue(maxlen=size)
        

    def next(self, val: int) -> float:
        self.dq.append(val)
        return sum(dq)/len(dq)