class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN, c=0;
        for(auto i:nums) {
            c+=i;
            res=max(res,c);
            if(c<0) c=0;
        }
        return res;
    }
};