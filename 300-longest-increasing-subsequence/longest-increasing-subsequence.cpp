class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0]=1;
        for(int i=1;i<nums.size();i++) {
            int t=0;
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i])
                t=max(t,dp[j]);
            }
            dp[i]=t+1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};