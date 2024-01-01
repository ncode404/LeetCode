class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        res,j = 0,0
        for i in range(len(g)):
            if j==len(s): break
            while j<len(s) and s[j]<g[i]: j+=1
            if j>=len(s): break
            res += 1; j+=1

        return res