def calc_diff(Px, Py, Mx, My):
    diff_x = Px - Mx
    diff_y = Py - My
    if diff_x < 0:
        diff_x *= -1
    if diff_y < 0:
        diff_y *= -1
    return diff_x + diff_y

def findfocus(PlayerList, pos, lenPList):
    index_focus = 0
    i = 0
    while i < lenPList:
        tmp_diff = calc_diff(PlayerList[i]['x'], PlayerList[i]['z'], pos['x'], pos['z'])
        if i == 0:
            mindiff = tmp_diff
        if mindiff >= tmp_diff:
            mindiff = tmp_diff
            index_focus = i
        i = i + 1
    return (PlayerList[index_focus], index_focus)

# def goto(posPlayer, pos):
#     diff = calc_diff(posPlayer['x'], posPlayer['y'], pos['x'], pos['y'])
#     new_pos = {'x': 0, 'y': 0}
#     if calc_diff(posPlayer['x'], posPlayer['y'], pos['x'], pos['y'] - 1) < diff:
#         new_pos['x'] = pos['x']
#         new_pos['y'] = pos['y'] - 1
#     if calc_diff(posPlayer['x'], posPlayer['y'], pos['x'] + 1, pos['y']) < diff:
#         new_pos['x'] = pos['x'] + 1
#         new_pos['y'] = pos['y']
#     if calc_diff(posPlayer['x'], posPlayer['y'], pos['x'], pos['y'] + 1) < diff:
#         new_pos['x'] = pos['x']
#         new_pos['y'] = pos['y'] + 1
#     if calc_diff(posPlayer['x'], posPlayer['y'], pos['x'] - 1, pos['y']) < diff:
#         new_pos['x'] = pos['x'] - 1
#         new_pos['y'] = pos['y']
#     return new_pos

def IA_Astar(PlayerList, pos):
    lenPList = len(PlayerList)
    Focus = findfocus(PlayerList, pos, lenPList)

    return Focus
