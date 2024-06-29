class Solution:
    def __init__(self):
        self.__class__.d = {}
        t = 0
        while t*t<=(2**31-1):
            self.__class__.d[t*t]=1; t+=1

    def judgeSquareSum(self, c: int) -> bool:
        # print(self.__class__.d)
        t = 0
        while t*t<=(2**31-1):
            if c-(t*t) in self.__class__.d:
                return 1
            t+=1
        return 0