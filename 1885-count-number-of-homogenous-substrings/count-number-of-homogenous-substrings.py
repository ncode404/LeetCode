class Solution:
    def countHomogenous(self, s: str) -> int:
        c, res, mod = 1, 0, 1000000007
        for i in range(1, len(s)):
            if(s[i]!=s[i-1]): 
                res += (c*(c+1)//2)
                res %= mod; c = 1
            else: c += 1
        return (res + (c*(c+1)//2))%mod