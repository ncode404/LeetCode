class Solution {
    int tot=0;
    bool f(int i,vector<int> &nums,int x,vector<vector<int>> &dp) {
        if(i>=nums.size() || x>tot/2) return 0;
        if(x==tot/2) return 1;
        if(dp[i][x]!=-1) return dp[i][x];
        return dp[i][x] = f(i+1,nums,x+nums[i],dp) || f(i+1,nums,x,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        tot = accumulate(nums.begin(),nums.end(),0);
        if(tot&1) return 0;
        vector<vector<int>> dp(nums.size()+1,vector<int> (tot/2+1, -1));
        return f(0,nums,0,dp);
    }
};