from tkinter import *
import random
import sys
import time


class Square:
    colors = {'l': 'orange', 'r': 'red', 'u': 'white', 'd': 'yellow', 'f': 'green', 'b': 'blue'}
    face_coords = {'l': (0, 150), 'f': (300, 150), 'u': (450, 0), 'd': (300, 450), 'r': (600, 150), 'b': (750, 0)}
    face_axis = {'l': ((0, 100), (100, 0)), 'f': ((0, 100), (100, 0)), 'd': ((0, 100), (100, 0)), 'b': ((0, 100), (100, 0)), 
                 'u': ((-50, 50), (100, 0)), 'r': ((0, 100), (50, -50))}

    def __init__(self, id, i, j):
        self.color = Square.colors[id]
        self.id = id
        self.i = i
        self.j = j
        self.rec = None

    def draw(self):
        x, y = Square.face_coords[self.id]
        (ix, iy), (jx, jy) = Square.face_axis[self.id]

        y += iy * self.i + jy * self.j
        x += ix * self.i + jx * self.j
        x1, y1 = x + ix, y + iy
        x2, y2 = x1 + jx, y1 + jy
        x3, y3 = x + jx, y + jy
        if canvas:
            self.rec = canvas.create_polygon(x, y, x1, y1, x2, y2, x3, y3, fill=self.color, outline='black')
        # self.rec = canvas.create_rectangle(x, y, x+100, y+100, fill=color)
    
    def update(self, color):
        self.color = color
        if canvas:
            canvas.itemconfig(self.rec, fill=color)


class Face:
    neighbors = {'l': ['u', 'f', 'd', 'b'], 'r': ['u', 'b', 'd', 'f'],
                    'u': ['b', 'r', 'f', 'l'], 'd': ['f', 'r', 'b', 'l'],
                    'f': ['u', 'r', 'd', 'l'], 'b': ['u', 'l', 'd', 'r']}

    def __init__(self, id, cube):
        self.id = id
        self.squares = [[Square(id, i, j) for j in range(3)] for i in range(3)]
        self.cube = cube
        self.crown = None
    
    def __getitem__(self, ij):
        i, j = ij
        return self.squares[i][j]

    def get_column(self, column):
        return [self.squares[i][column] for i in range(3)]
    
    def get_row(self, row):
        return self.squares[row][:]

    def draw(self):
        for i in range(3):
            for j in range(3):
                self[i, j].draw()

    def get_crown(self):
        if self.crown:
            return self.crown
        res = []
        if self.id == 'l':
            res += self.cube['u'].get_column(0)
            res += self.cube['f'].get_column(0)
            res += self.cube['d'].get_column(0)
            res += self.cube['b'].get_column(2)[::-1]
        elif self.id == 'r':
            res += self.cube['u'].get_column(2)[::-1]
            res += self.cube['b'].get_column(0)
            res += self.cube['d'].get_column(2)[::-1]
            res += self.cube['f'].get_column(2)[::-1]
        elif self.id == 'u':
            res += self.cube['b'].get_row(0)[::-1]
            res += self.cube['r'].get_row(0)[::-1]
            res += self.cube['f'].get_row(0)[::-1]
            res += self.cube['l'].get_row(0)[::-1]
        elif self.id == 'd':
            res += self.cube['f'].get_row(2)
            res += self.cube['r'].get_row(2)
            res += self.cube['b'].get_row(2)
            res += self.cube['l'].get_row(2)
        elif self.id == 'f':
            res += self.cube['u'].get_row(2)
            res += self.cube['r'].get_column(0)
            res += self.cube['d'].get_row(0)[::-1]
            res += self.cube['l'].get_column(2)[::-1]
        elif self.id == 'b':
            res += self.cube['u'].get_row(0)[::-1]
            res += self.cube['l'].get_column(0)
            res += self.cube['d'].get_row(2)
            res += self.cube['r'].get_column(2)[::-1]
        self.crown = res
        return self.crown

    def rotate(self, direction):
        for d in range(direction):
            # Rotate the face
            for i in range(2):
                tmp = self.squares[0][i].color
                self.squares[0][i].update(self.squares[2-i][0].color)
                self.squares[2-i][0].update(self.squares[2][2-i].color)
                self.squares[2][2-i].update(self.squares[i][2].color)
                self.squares[i][2].update(tmp)
            # Rotate the crown
            crown = self.get_crown()
            tmp = [s.color for s in crown[9:]]
            for i in range(12 - 1, 3 -1, -1):
                crown[i].update(crown[i-3].color)
            for i in range(3):
                crown[i].update(tmp[i])
        root.update()

def lol_func(i, j):
    if j == 1:
        return i
    if i == 1:
        return 3 - j

class Cube:
    def __init__(self):
        self.faces = {id: Face(id, self) for id in ['l', 'r', 'u', 'd', 'f', 'b']}
        Cube.iscross = self.hashable()
        print(Cube.iscross)

    def rotate(self, face, direction):
        direction = (direction + 4) % 4
        self.faces[face].rotate(direction)

    def hashable(self):
        res = []
        for face in self.faces.values():
            crown = face.get_crown()
            for i in range(3):
                for j in range(3):
                    if (i != 1 and j != 1):
                        res.append('*')
                    elif (face[i, j].color != 'white' and crown[1 + 3 * lol_func(i, j)].color != 'white'):
                        res.append('*')
                    else:
                        res.append(face[i, j].color)
        return tuple(res)
    
    def __getitem__(self, face):
        return self.faces[face]
    
    def draw(self):
        for face in self.faces.values():
            face.draw()
    
    def shuffle(self):
        for i in range(10000):
            face = random.choice(['l', 'r', 'u', 'd', 'f', 'b'])
            direction = random.choice([-1, 1, 2])
            self.rotate(face, direction)
    
    def is_cross(self):
        return self.hashable() == self.iscross

    # def search_for_cross(self):
    #     breadth = [self]
    #     visited = set()
    #     while True:
    #         new = []
    #         for cube in breadth:
    #             for face in ['l', 'r', 'u', 'd', 'f', 'b']:
    #                 for direction in range(1, 4):
    #                     self.rotate(face, 1)
    #                     if self.hashable not in visited:
    #                         new.append(Cube(self))
    #                 self.rotate(face, 1)


    def backtrack_for_cross(self):
        res = []
        moves = []
        visited = {}

        def backtrack(depth):
            ret = False
            if self.is_cross():
                print(moves)
                return True
            hashed = self.hashable()
            if depth == 0 or (hashed in visited and len(moves) >= visited[hashed]):
                return False
            visited[hashed] = len(moves)
            for face in ['l', 'r', 'u', 'd', 'f', 'b']:
                for direction in range(1, 4):
                    self.rotate(face, 1)
                    moves.append(face.upper()+str(direction))
                    if backtrack(depth - 1):
                        ret = True
                    moves.pop()
                self.rotate(face, 1)
            return ret

        nb = 5
        while not backtrack(nb):
            print(nb , "done", "visited", len(visited))
            visited = {}
            nb += 1
        print(nb , "done", "visited", len(visited))
        return res

def read_moves():
    res = []
    for line in sys.stdin:
        res.extend(line.split())
    return res

def launch():
    for move in moves:
        print(move)
        face = move[0].lower()
        direction = 1
        if len(move) >= 2:
            if move[1] == '2':
                direction = 2
            elif move[1] == '\'':
                direction = 3
        cube.rotate(face, direction)
        # root.update()
        time.sleep(0.2)

def key_press(event):
    # code = event.keycode
    if event.char == 'q':
        root.destroy()
        exit()
    elif event.char == 'p':
        launch()
    elif event.char.lower() in ['l', 'r', 'u', 'd', 'f', 'b']:
        dir = -1 if event.char.isupper() else 1
        cube.rotate(event.char.lower(), dir)

canvas = None
cube = Cube()


# cube.shuffle()
# cube.backtrack_for_cross()
# exit()
root = Tk()
root.title('Rubik\'s Cube')
# root.geometry("500x900")
canvas = Canvas(root, width=1050, height=750)
canvas.pack()
cube.draw()

moves = read_moves()

if len(sys.argv) >= 2:
    mmmmmhhhhh = sys.argv[1].split()
    for move in mmmmmhhhhh:
        face = move[0].lower()
        direction = 1
        if len(move) >= 2:
            if move[1] == '2':
                direction = 2
            elif move[1] == '\'':
                direction = 3
        cube.rotate(face, direction)
        

root.bind('<KeyPress>', key_press)
root.mainloop()


