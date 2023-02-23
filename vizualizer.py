colors = {'l': 'orange', 'r': 'red', 'u': 'white', 'd': 'yellow', 'f': 'green', 'b': 'blue'}

class Square:
    face_coords = {'l': (0, 300), 'f': (300, 300), 'u': (300, 0), 'd': (300, 600), 'r': (600, 300), 'b': (900, 300)}
    color_coords = {}
    for c in face_coords:
        color_coords[colors[c]] = face_coords[c]

    def __init__(self, color, i, j):
        self.color = color
        x, y = Square.color_coords[self.color]
        y += i * 100
        x += j * 100
        self.rec = canvas.create_rectangle(x, y, x+100, y+100, fill=color)
    
    def update(self, color):
        self.color = color
        canvas.itemconfig(self.rec, fill=color)


class Face:
    # neighbors = {'l': ['u', 'f', 'd', 'b'], 'r': ['u', 'b', 'd', 'f'],
    #                 'u': ['l', 'f', 'r', 'b'], 'd': ['l', 'b', 'r', 'f'],
    #                 'f': ['l', 'u', 'r', 'd'], 'b': ['l', 'd', 'r', 'u']}

    def __init__(self, id, cube):
        color = colors[id]
        self.id = id
        self.squares = [[Square(color, i, j) for j in range(3)] for i in range(3)]
        self.cube = cube
    
    def __getitem__(self, ij):
        i, j = ij
        return self.squares[i][j]

    def get_column(self, column):
        return [self.squares[i][column] for i in range(3)]
    
    def get_row(self, row):
        return self.squares[row][:]

    def get_crown(self):
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
            res += self.cube['l'].get_row(0)[::-1]
            res += self.cube['b'].get_row(0)[::-1]
            res += self.cube['r'].get_row(0)[::-1]
            res += self.cube['f'].get_row(0)[::-1]
        elif self.id == 'd':
            res += self.cube['l'].get_row(2)
            res += self.cube['f'].get_row(2)
            res += self.cube['r'].get_row(2)
            res += self.cube['b'].get_row(2)
        elif self.id == 'f':
            res += self.cube['l'].get_column(2)[::-1]
            res += self.cube['u'].get_row(2)
            res += self.cube['r'].get_column(0)
            res += self.cube['d'].get_row(0)[::-1]
        elif self.id == 'b':
            res += self.cube['l'].get_column(0)
            res += self.cube['d'].get_row(2)
            res += self.cube['r'].get_column(2)[::-1]
            res += self.cube['u'].get_row(0)[::-1]
        return res

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
        
class Cube:
    def __init__(self):
        self.faces = {id: Face(id, self) for id in ['l', 'r', 'u', 'd', 'f', 'b']}

    def rotate(self, face, direction):
        direction = (direction + 4) % 4
        self.faces[face].rotate(direction)
    
    def __getitem__(self, face):
        return self.faces[face]

from tkinter import *
root = Tk()
root.title('Rubik\'s Cube')
# root.geometry("500x900")
canvas = Canvas(root, width=1200, height=900)
canvas.pack()

cube = Cube()

def key_press(event):
    code = event.keycode
    global i0, j0
    if event.char == 'q':
        root.destroy()
        exit()
    # elif event.char == 'p':
    #     launch()
    #     return
    if event.char.lower() in ['l', 'r', 'u', 'd', 'f', 'b']:
        dir = -1 if event.char.isupper() else 1
        cube.rotate(event.char.lower(), dir)  

root.bind('<KeyPress>', key_press)
root.mainloop()


