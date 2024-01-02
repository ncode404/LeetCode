class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        d = {}
        mx = -1
        for i in nums:
            if i in d: d[i] += 1
            else: d[i] = 1
            mx = max(mx, d[i])

        res = [[] for i in range(mx)]
        for i in d:
            for j in range(d[i]):
                res[j].append(i)

        return res