from typing import List

class MyQueue:

    def __init__(self):
        self.inStack = []
        self.outStack = []
        

    def push(self, x: int) -> None:
        self.move()
        self.inStack.append(x)
        self.move_back()


    def pop(self) -> int:
        return self.inStack.pop()


    def peek(self) -> int:
        return self.inStack[-1]


    def empty(self) -> bool:
        return len(self.inStack) == 0
    

    def move(self) -> None:
        for _ in range(len(self.inStack)):
            self.outStack.append(self.inStack.pop())
    
    def move_back(self) -> None:
        for _ in range(len(self.outStack)):
            self.inStack.append(self.outStack.pop())


if __name__ == "__main__":
    queue = MyQueue()

    queue.push(1)
    print(queue.inStack)
    queue.push(2)
    print(queue.inStack)
    print(queue.peek())
    print(queue.inStack)
    print(queue.pop())
    print(queue.inStack)
    print(queue.empty())
    print(queue.inStack)