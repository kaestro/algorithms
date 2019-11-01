class MyCircularQueue:

    def __init__(self, k: int):
        self.cq = [None] * k
        self.qsize = k
        self.head = -1
        self.tail = -1


    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        if self.isEmpty():
            self.head = 0
        self.tail = (self.tail + 1) % self.qsize
        self.cq[self.tail] = value
        return True


    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        if self.head == self.tail:
            self.head, self.tail = -1, -1
            return True
        
        self.head = (self.head + 1) % self.qsize
        return True


    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.cq[self.head]
        

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.cq[self.tail]
        

    def isEmpty(self) -> bool:
        return self.head == -1


    def isFull(self) -> bool:
        return (self.tail + 1) % self.qsize == self.head


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()