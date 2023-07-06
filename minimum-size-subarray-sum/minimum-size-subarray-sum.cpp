class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,ans=INT_MAX,l=0,r=0;
        while(r<nums.size()) {
            sum+=nums[r++];
            while(sum>=target) {
                ans=min(ans,r-l);
                sum-=nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};