class Solution {
    int f(vector<int> &a,int i,int k,bool buy, vector<vector<vector<int>>> &dp) {
        if(i==a.size()) return 0;
        if(k==0) return 0;
        if(dp[i][k][buy]!=-1) return dp[i][k][buy];
        int res=INT_MIN;
        if(!buy) {
            res=max({res, -a[i]+f(a,i+1,k,1,dp), f(a,i+1,k,0,dp)});
        }
        else {
            res=max({res, a[i]+f(a,i+1,k-1,0,dp), f(a,i+1,k,1,dp)});
        }
        return dp[i][k][buy] = res;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (k+1, vector<int> (2,-1)));
        return f(prices,0,k,0,dp);
    }
};