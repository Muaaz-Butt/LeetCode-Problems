class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        new_points = points.sort(key=lambda x: x[1])
        arrows = 1
        shot = points[0][1]
        for point in points:
            if not (shot >= point[0] and shot <= point[1]):
                arrows += 1
                shot = point[1]
        return arrows