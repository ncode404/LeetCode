class Solution {
    vector<vector<int>> dp;
    int f(int i,vector<int> &nums,int t) {
        if(i==nums.size()) return t==0;
        if(dp[i][t]!=-1) return dp[i][t];
        int res=0;
        if(t>=nums[i]) res += f(0,nums,t-nums[i]);
        res += f(i+1,nums,t);
        return dp[i][t]=res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(nums.size()+1,vector<int> (target+1,-1));
        return f(0,nums,target);
    }
};