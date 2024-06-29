class Solution:
    def __init__(self):
        self.d = {}
        t = 0
        while t*t<=(2**31-1):
            self.d[t*t]=1; t+=1

    def judgeSquareSum(self, c: int) -> bool:
        t = 0
        while t*t<=(2**31-1):
            if c-(t*t) in self.d:
                return 1
            t+=1
        return 0