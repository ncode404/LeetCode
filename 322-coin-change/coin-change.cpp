class Solution {
    vector<vector<int>> dp;
    int f(vector<int> &coins,int a,int i) {
        if(i==coins.size()) {
            if(!a) return 0;
            return INT_MAX-1;
        }
        if(dp[i][a]!=-1) return dp[i][a];

        int res=INT_MAX;
        if(a>=coins[i]) res=min(res,1+f(coins,a-coins[i],i));
        res=min(res,f(coins,a,i+1));

        return dp[i][a]=res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+1,vector<int> (amount+1,-1));
        int res=f(coins,amount,0);
        if(res==INT_MAX-1) return -1;
        return res;
    }
};