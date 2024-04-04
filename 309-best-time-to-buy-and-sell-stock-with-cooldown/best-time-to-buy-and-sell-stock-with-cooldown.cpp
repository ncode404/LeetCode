class Solution {
    vector<vector<int>> dp;
    int f(vector<int> &a,int i,int buy) {
        if(i>=a.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int res=INT_MIN;
        if(!buy) {
            res=max({res,-a[i]+f(a,i+1,1), f(a,i+1,0)});
        }   
        else {
            res=max({res,a[i]+f(a,i+2,0), f(a,i+1,1)});
        }
        return dp[i][buy] = res;
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1, vector<int> (2,-1));
        return f(prices,0,0);
    }
};