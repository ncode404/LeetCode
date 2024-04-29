class Solution:
    def minimumAddedInteger(self, x: List[int], y: List[int]) -> int:
        d = Counter(x)
        for k in range(-1000,1000):
            t = {}
            for i in y:
                if i-k in t: t[i-k]+=1 
                else: t[i-k]=1

            for i in t:
                if i not in d: break
                elif d[i]<t[i]: break
            else: return k