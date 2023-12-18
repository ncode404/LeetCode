l = []
for i in range(1,100000):
    s = str(i)
    l.append(int(s+s[::-1]))
    l.append(int(s+s[::-1][1:]))
l.sort()

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        nums.sort()
        x = nums[len(nums)//2]
        b = bisect_left(l,x)
        def f(a):
            # if a<0 or a>=len(l): return 10**18
            return sum(abs(i-l[a]) for i in nums)

        return min(f(b),f(b-1))