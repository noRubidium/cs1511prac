#!/usr/bin/env python
import random
start_num = int(raw_input())
num_test = int(raw_input())

#!/usr/bin/env python
NORTH, S, W, E = (0, -1), (0, 1), (-1, 0), (1, 0) # directions
turn_right = {NORTH: E, E: S, S: W, W: NORTH} # old -> new direction

def spiral(width, height):
    if width < 1 or height < 1:
        raise ValueError
    x, y = width // 2, height // 2 # start near the center
    dx, dy = NORTH # initial direction
    matrix = [[None] * width for _ in range(height)]
    count = 0
    while True:
        count += 1
        matrix[y][x] = count # visit
        # try to turn right
        new_dx, new_dy = turn_right[dx,dy]
        new_x, new_y = x + new_dx, y + new_dy
        if (0 <= new_x < width and 0 <= new_y < height and
            matrix[new_y][new_x] is None): # can turn right
            x, y = new_x, new_y
            dx, dy = new_dx, new_dy
        else: # try to move straight
            x, y = x + dx, y + dy
            if not (0 <= x < width and 0 <= y < height):
                return matrix # nowhere to go

def print_matrix(matrix):
    s = ""
    width = len(str(max(el for row in matrix for el in row if el is not None)))
    fmt = "{:%d}" % width
    for row in matrix:
        s += (" ".join("_"*width if el is None else fmt.format(el) for el in row))
        s += '\n'
    return s

for i in xrange(num_test):
    n = i + 5
    f = open('{}.in'.format(i+start_num), 'w')
    f.write('{}\n'.format(n))
    f.close()

    f = open('{}.out'.format(i+start_num), 'w')
    f.write(str(print_matrix(spiral(n, n)))+"\n")
    f.close()
