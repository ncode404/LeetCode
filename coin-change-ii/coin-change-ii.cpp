class Solution {
public:
    int f(vector<int> &coins,int t,int i,vector<vector<int>> &dp) {
        if(i==coins.size()) {
            if(t==0) return 1;
            return 0;
        }
        if(dp[t][i]!=-1) return dp[t][i];
        int nt,take=0;
        nt = f(coins,t,i+1,dp);
        if(coins[i]<=t)
        take = f(coins,t-coins[i],i,dp);

        return dp[t][i] = take+nt;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int> (coins.size()+1,-1));
        return f(coins,amount,0,dp);
    }
};