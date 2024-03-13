class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        res=[]
        for i in range(len(arr)):
            def get(s):
                pr=[]
                for i in range(len(s)):
                    temp=""
                    for j in range(i,len(s)):
                        temp+=s[j]
                        pr.append([len(temp),temp])

                pr.sort()
                return pr
            pr = get(arr[i])
            for p in pr:
                x = 0
                for j in range(len(arr)):
                    if i!=j:
                        if p[1] in arr[j]:
                            x=1
                            break

                if x==0: 
                    res.append(p[1])
                    break
            else: res.append("")
        return res