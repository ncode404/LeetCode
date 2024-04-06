class Solution {
    vector<vector<int>> dp;
    int f(vector<int> &nums,int t,int i) {
        if(i==nums.size()) return t==0;
        if(dp[i][t+5000]!=-1) return dp[i][t+5000];
        int res=0;
        res += f(nums,t-nums[i],i+1);
        res += f(nums,t+nums[i],i+1);
        return dp[i][t+5000] = res;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size()+1,vector<int> (20000,-1));
        return f(nums,target,0);
    }
};