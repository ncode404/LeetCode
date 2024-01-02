class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        l = []
        for i in range(len(nums)):
            ok = 0
            for j in range(len(l)):
                if l[j][-1] != nums[i]:
                    l[j].append(nums[i])
                    ok = 1; break
            if not ok:
                l.append([nums[i]])

        return l
            