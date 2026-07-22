class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX, res=0;
        for(auto i:prices) {
            mini=min(mini,i);
            res=max(res,i-mini);
        }
        return res;
    }
};