class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        x = sentence.split(' ')
        d = {}
        for i in dictionary:
            if i not in d: d[i]=1

        res = ''
        for i in range(len(x)):
            t,b = '',0
            for l in x[i]:
                t += l
                if t in d: 
                    x[i]=t; b=1; break
            
            res+=x[i]; res+=' '
        return res.strip()