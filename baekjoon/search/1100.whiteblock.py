def create_CB():
    cb = []
    for _ in range(8):
        cb.append(input())
    return cb


def countWhiteBock(chessBoard):
    count = 0
    for row in range(len(chessBoard)):
        for col in range(len(chessBoard[row])):
            if (row + col) % 2 == 0 and chessBoard[row][col] == 'F':
                count += 1
    return count


if __name__ == "__main__":
    chessBoard = create_CB()
    print(countWhiteBock(chessBoard))