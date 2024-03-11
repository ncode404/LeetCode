class Solution:
    def customSortString(self, order: str, s: str) -> str:
        d = Counter(s)
        res = ''
        for i in order:
            if i in d: 
                for j in range(d[i]):
                    res += i
                del d[i]
                
        for i in range(26):
            if chr(i+ord('a')) in d:
                for j in range(d[chr(i+ord('a'))]):
                    res += chr(i+ord('a'))

        return res