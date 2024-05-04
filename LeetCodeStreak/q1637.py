
def widestVerticalArea(points):
    first_x = min(points[0][0], points[1][0])
    sec_x = max(points[0][0], points[1][0])
    max_width = abs(points[0][0] - points[1][0])
    N = len(points)
    for i in range(2, N):
        if points[i][0] < first_x:
            if abs(points[i][0] - first_x) > max_width:
                max_width = abs(points[i][0] - first_x)
                sec_x = first_x
                fisrt_x = points[i][0]
        elif points[i][0] > sec_x:
            if abs(points[i][0] - sec_x) > max_width:
                max_width = abs(points[i][0] - sec_x)
                first_x = sec_x
                sec_x = points[i][0]
        elif points[i][0] < sec_x and points[i][0] > first_x:
            max_width = max(abs(points[i][0] - sec_x),abs(points[i][0] - first_x))
            if abs(points[i][0] - sec_x) > abs(points[i][0] - first_x):
                first_x = points[i][0]
            else:
                sec_x = points[i][0]
    return max_width







points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
print(widestVerticalArea(points))