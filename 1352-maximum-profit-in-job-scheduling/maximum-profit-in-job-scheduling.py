class Solution:
    def jobScheduling(self, s: List[int], e: List[int], cost: List[int]) -> int:
        t = []
        for i in range(len(s)):
            t.append([e[i], s[i], cost[i]])
        t.sort()
        y = [i[0] for i in t]
        dp = [0 for i in range(len(s))]
        # print(t)
        p = -1
        for i in range(len(s)):
            x = bisect_right(y, t[i][1])
            # print(x, end=' ')
            if x==0: 
                if t[x][0]>t[i][1]:
                    dp[i] = max(p, t[i][2])
                elif t[x][0] == t[i][1]:
                    dp[i] = max(p,t[i][2]+dp[x])

            else:
                if t[x][0]>t[i][1]:
                    dp[i] = max(t[i][2]+dp[x-1],p)
                elif t[x][0] == t[i][1]:
                    dp[i] = max(p,t[i][2]+dp[x])

            p=max(p,dp[i])
        # print()
        # print(dp)
        return p