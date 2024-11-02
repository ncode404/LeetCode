class Solution:
    def isCircularSentence(self, s: str) -> bool:
        t = s.split()
        prev = ""
        if s[0]!=s[-1]: return False
        for i in t:
            if prev and i[0]!=prev[-1]:
                return False
            prev = i
        return True