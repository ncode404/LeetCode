class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        res = []
        cnt = 0
        for i in nums:
            if i<pivot: res.append(i)
            if i==pivot: cnt+=1

        while cnt:
            res.append(pivot)
            cnt-=1

        for i in nums:
            if i>pivot: res.append(i)

        return res