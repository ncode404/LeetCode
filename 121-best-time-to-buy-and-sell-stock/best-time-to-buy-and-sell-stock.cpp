class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> suf(prices.size());
        int t=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--) {
            t=max(t,prices[i]);
            suf[i]=t;
        }
        int res=INT_MIN;
        for(int i=0;i<prices.size();i++) {
            res=max(res,suf[i]-prices[i]);
        }
        return res;
    }
};