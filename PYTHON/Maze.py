def PATH(h, v, maze, path, width, height):
    path[h][v] = 1
    x = [h]
    y = [v]
    while True:
        currentX = x.pop(0)
        currentY = y.pop(0)
        if currentX+1 >= 0:
            if currentX+1 < height:
                if path[currentX+1][currentY] == -2:
                    path[currentX+1][currentY] = path[currentX][currentY]+1
                    if maze[currentX+1][currentY] == 0:
                        x.append(currentX+1)
                        y.append(currentY)

        if currentX-1 >= 0:
            if currentX-1 < height:
                if path[currentX-1][currentY] == -2:
                    path[currentX-1][currentY] = path[currentX][currentY]+1
                    if maze[currentX-1][currentY] == 0:
                        x.append(currentX-1)
                        y.append(currentY)

        if currentY+1 >= 0:
            if currentY+1 < width:
                if path[currentX][currentY+1] == -2:
                    path[currentX][currentY+1] = path[currentX][currentY]+1
                    if maze[currentX][currentY+1] == 0:
                        x.append(currentX)
                        y.append(currentY+1)

        if currentY-1 >= 0:
            if currentY-1 < width:
                if path[currentX][currentY-1] == -2:
                    path[currentX][currentY-1] = path[currentX][currentY]+1
                    if maze[currentX][currentY-1] == 0:
                        x.append(currentX)
                        y.append(currentY-1)

        if not x:
            break
    return path

def answer(maze):
    width = len(maze[0])
    height = len(maze)
    shortest = 10000
    path = [[-2 for i in range(width)] for j in range(height)]
    path2 = [[-2 for i in range(width)] for j in range(height)]
    PATH(0, 0, maze, path, width, height)
    PATH(height-1, width-1, maze, path2, width, height)
    for i in range(height):
        for j in range(width):
            if path[i][j] and path2[i][j]:
                if (path[i][j]+path2[i][j]) < shortest and (path[i][j] > 0 and path2[i][j] > 0):
                    shortest = path[i][j]+path2[i][j]
    return shortest-1

maze = [[0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
              [1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
              [1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
              [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
              [0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1],
              [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
print answer(maze)