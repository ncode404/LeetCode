class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        res = []
        temp = 0
        for i in word:
            temp = temp*10+int(i)
            if(temp%m): res.append(0)
            else: res.append(1)
            temp%=m

        return res