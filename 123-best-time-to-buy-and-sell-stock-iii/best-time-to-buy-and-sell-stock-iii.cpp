class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we can use prefix profits, suffix profits
        int t=INT_MIN, res=0, n=prices.size(), x=INT_MIN;
        vector<int> sp(n);
        for(int i=n-1;i>=0;i--) {
            t=max(t,prices[i]);
            sp[i]=max(x,t-prices[i]);
            x=max(x,sp[i]);
        }
        t=INT_MAX;
        for(int i=0;i<n-1;i++) {
            t=min(t,prices[i]);
            res=max(res,(prices[i]-t)+sp[i+1]);
        }
        res=max(res,prices[n-1]-prices[0]); // no split
        return res;
    }
};