class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        d = Counter(nums)
        dupli,miss = -1,-1
        for i in range(1,len(nums)+1):
            if d[i]==2: dupli = i
            if d[i]==0: miss = i
            if dupli!=-1 and miss!=-1: 
                return [dupli, miss]