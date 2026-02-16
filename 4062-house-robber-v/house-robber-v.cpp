class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size());
        dp[0]=nums[0];
        if(nums.size()>=2) {
            if(colors[1]==colors[0]) dp[1]=max((long long)nums[1], dp[0]);
            else dp[1]=dp[0]+nums[1];
        }
        for(int i=2;i<colors.size();i++) {
            if(colors[i]!=colors[i-1]) dp[i]=dp[i-1]+nums[i];
            else dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[colors.size()-1];
    }
};