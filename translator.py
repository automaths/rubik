yscope = { 'L': 'F', 'F': 'R', 'R': 'B', 'B': 'L', 'U': 'U', 'D': 'D' } # [U]
yscope = "LFRB"
zscope = { 'L': 'D', 'D': 'R', 'R': 'U', 'U': 'L', 'F': 'F', 'B': 'B' } # [F]
zscope = "LDRU"
xscope = { 'L': 'L', 'R': 'R', 'F': 'D', 'D': 'B', 'B': 'U', 'U': 'F' } # [R]
xscope = "FDBU"
opposites = { 'L': 'R', 'R': 'L', 'F': 'B', 'B': 'F', 'U': 'D', 'D': 'U' }
axis = { 'L': 'x\'', 'R': 'x', 'F': 'z', 'B': 'z\'', 'U': 'y', 'D': 'y\'' }


def clean_w(moves):
    res = []
    for move in moves:
        if len(move) > 1 and move[1] == 'w':
            prime = move[2] if len(move) > 2 else ''
            res.append(opposites[move[0]] + prime)
            res.append(axis[move[0]] + prime)
            while res[-1][-2:] == '\'\'':
                res[-1] = res[-1][:-2]
        else:
            res.append(move)
    return res

def translate(moves):
    moves = moves.split()
    moves = clean_w(moves)
    scopes = []
    res = []
    for move in moves:
        if move[0] in 'xyz':
            scopes.append(move[0])
        else:
            for scope in scopes[::-1]:
                dir = 1 if len(scope) == 1 else 3
                if scope == 'x' and move[0] in xscope:
                    move = xscope[(xscope.index(move[0]) + dir) % 4] + move[1:]
                elif scope == 'y' and move[0] in yscope:
                    move = yscope[(yscope.index(move[0]) + dir) % 4] + move[1:]
                elif scope == 'z' and move[0] in zscope:
                    move = zscope[(zscope.index(move[0]) + dir) % 4] + move[1:]
            res.append(move)
    return " ".join(res)


print(translate("Rw U R' U' Rw' F R F'"))

