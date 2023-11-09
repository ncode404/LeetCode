class Solution:
    def countHomogenous(self, s: str) -> int:
        c, res = 1, 0
        for i in range(1, len(s)):
            if(s[i]!=s[i-1]): 
                res += (c*(c+1)//2)
                c = 1
            else: c += 1
            res %= (10**9+7)

        return (res + (c*(c+1)//2))%(10**9+7)