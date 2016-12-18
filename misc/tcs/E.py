import sys
import math
import string
def getboard(fen):
    board = [['-' for i in range(8)] for j in range(8)]
    for rank, state in enumerate(fen):
        cur_col = 0
        for ch in state:
            if ch in string.digits:
                cur_col += int(ch)
            else:
                board[rank][cur_col] = ch
                cur_col += 1
    return board

def debug(board):
    print('\n'.join([''.join(b) for b in board]))

d_move = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
def get_coding(rank, col):
    return chr(ord('a')+col)+str(8-rank)

d_moves = {
    'P': [(1, 1), (1, -1)],
    'P': [(-1, 1), (-1, -1)],
    'k': [(2, 1), (1, 2), (-1, 2), (2, -1), (-1, -2), (-2, -1), (1, -2), (-2, 1)]
}
king_pos = {}
def valid(rank, col):
    return 0 <= rank < 8 and 0 <= col < 8

def get_team(piece):
    return 'w' if piece in string.ascii_uppercase else 'b'

def movable(rank1, col1, rank2, col2, board):
    piece = board[rank1][col1]
    if piece == '-':
        return False
    team = get_team(piece)
    team2 = get_team(board[rank2][col2])
    if team == team2: return False

    cur_rank, cur_col = rank1, col1
    if piece.lower() == 'b' or piece.lower() == 'q':
        if abs(rank1-rank2) != abs(col1-col2):
            return False
        incr_rank = 1 if rank1 < rank2 else -1
        incr_col = 1 if col1 < col2 else -1
        while valid(cur_rank, cur_col):
            if cur_rank == rank2 and cur_col == col2:
                return True
            if (cur_rank != rank1 or cur_col != col1):
                piece2 = board[cur_rank][cur_col]
                if piece2 != '-':
                    return False
            cur_rank += incr_rank
            cur_col += incr_col
    if piece.lower() == 'p':
        for _d in d_moves[piece]:
            if rank1 + _d[0] == rank2 and col1 + _d[1] == col2:
                return True
    if piece.lower() == 'k':
        for _d in d_moves['k']:
            if rank1 + _d[0] == rank2 and col1 + _d[1] == col2:
                return True
    if piece.lower() == 'r' or piece.lower() == 'q':
        if rank1 != rank2 and col1 != col2:
            return False
        incr_col, incr_rank = 0, 0
        if rank1 != rank2:
            incr_rank = -1 if rank2 < rank1 else 1
        if col1 != col2:
            incr_col = -1 if col2 < col1 else 1
        while valid(cur_rank, cur_col):
            if cur_rank == rank2 and cur_col == col2:
                return True
            if (cur_rank != rank1 or cur_col != col1):
                piece2 = board[cur_rank][cur_col]
                if piece2 != '-':
                    return False
            cur_rank += incr_rank
            cur_col += incr_col

    return False


def check(board, team):
    king_rank, king_col = king_pos[team]
    for rank in range(len(board)):
        for col in range(8):
            if movable(rank, col, king_rank, king_col, board):
                return True

    return False

def move(board, rank, col):
    res = []
    team = 'w' if board[rank][col] in string.ascii_uppercase else 'b'
    if board[rank][col].lower() == 'b':
        for d_ in d_move:
            cur_rank = rank
            cur_col = col
            while 0 <= cur_rank < 8 and 0 <= cur_col < 8:
                if (cur_rank != rank or cur_col != col):
                    cur_team = 'w' if board[cur_rank][cur_col] in string.ascii_uppercase else 'b'
                    if(board[cur_rank][cur_col] != '-'):
                        tmp = board[cur_rank][cur_col]
                        board[cur_rank][cur_col] = board[rank][col]
                        board[rank][col] = '-'
                        if team != cur_team and not check(board, team):
                            res.append((rank, col, cur_rank, cur_col))
                        board[rank][col] = board[cur_rank][cur_col]
                        board[cur_rank][cur_col] = tmp
                        break
                    tmp = board[cur_rank][cur_col]
                    board[cur_rank][cur_col] = board[rank][col]
                    board[rank][col] = '-'
                    if not check(board, team):
                        res.append((rank, col, cur_rank, cur_col))
                    board[rank][col] = board[cur_rank][cur_col]
                    board[cur_rank][cur_col] = tmp
                cur_rank += d_[0]
                cur_col += d_[1]
    return res

def comparator(x):
    rank, col, tar_rank, tar_col = x
    return rank, col, tar_rank, tar_col

def main():
    fen = sys.stdin.read().strip().split()[:2]
    turn = fen[1]
    fen = fen[0].split('/')
    board = getboard(fen)
    piece = 'b' if fen[1] == 'b' else 'B'
    res = []
    for rank in range(len(board)):
        for col in range(8):
            if board[rank][col] == 'k':
                king_pos['b'] = (rank, col)
            elif board[rank][col] == 'K':
                king_pos['w'] = (rank, col)
    for rank in range(len(board)):
        for col in range(8):
            if board[rank][col] == piece:
                res += move(board, rank, col)
    res.sort(key=comparator)
    res = [get_coding(rank, col) + get_coding(cur_rank, cur_col) for rank, col, cur_rank, cur_col in res]
    print('[%s]' % ', '.join(res))
    # debug(board)
if __name__ == '__main__':
    main()
