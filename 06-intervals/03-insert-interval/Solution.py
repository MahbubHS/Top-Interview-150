class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        res = []
        i, n = 0, len(intervals)

        # 1. all intervals ending before newInterval starts
        while i < n and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1

        # 2. merge all intervals overlapping newInterval
        start, end = newInterval
        while i < n and intervals[i][0] <= end:
            start = min(start, intervals[i][0])
            end = max(end, intervals[i][1])
            i += 1
        res.append([start, end])

        # 3. remaining intervals start after newInterval ends
        while i < n:
            res.append(intervals[i])
            i += 1

        return res
