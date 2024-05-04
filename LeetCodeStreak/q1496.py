visited = set()
def is_path_crossing(path):
    x_ind, y_ind = 0 , 0
    visited.add("0,0")
    for ch in path:
        if ch == "N":
            y_ind += 1
        elif ch == "S":
            y_ind -= 1
        elif ch == "E":
            x_ind += 1
        elif ch == "W":
            x_ind -= 1
        # print(ch , x_ind, y_ind)
        point_str = str(x_ind) + "," + str(y_ind)
        if point_str in visited:
            return True
        visited.add(point_str)
    return False


# path = "NNSWWEWSSESSWENNW"
# path = "NES"
path = "NESWW"

print(is_path_crossing(path))
print(visited)
