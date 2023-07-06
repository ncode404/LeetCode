class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,i,j=0,ans=INT_MAX;
        for(i=0;i<nums.size();i++) {
            sum+=nums[i];
            while(sum>=target) {
                ans=min(ans,i-j+1);
                sum-=nums[j++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};