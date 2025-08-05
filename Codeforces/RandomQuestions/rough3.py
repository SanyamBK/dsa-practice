def closestSquaredDistance(x, y):
    points = sorted(zip(x, y))
    memo = {}

    def squared_dist(p1, p2):
        return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

    def closest_pair(points):
        if len(points) <= 3:
            return min((squared_dist(points[i], points[j])
                        for i in range(len(points)) for j in range(i + 1, len(points))), default=float('inf'))

        mid = len(points) // 2
        left_points = points[:mid]
        right_points = points[mid:]

        min_dist_left = closest_pair(left_points)
        min_dist_right = closest_pair(right_points)
        min_dist = min(min_dist_left, min_dist_right)

        mid_x = points[mid][0]
        in_strip = [p for p in points if abs(p[0] - mid_x) < min_dist**0.5]
        in_strip.sort(key=lambda p: p[1]) 

        for i in range(len(in_strip)):
            for j in range(i + 1, len(in_strip)):
                if (in_strip[j][1] - in_strip[i][1])**2 >= min_dist:
                    break
                min_dist = min(min_dist, squared_dist(in_strip[i], in_strip[j]))

        return min_dist

    return closest_pair(points)

x = [0, 1, 2]
y = [0, 1, 4]
print(closestSquaredDistance(x, y)) 