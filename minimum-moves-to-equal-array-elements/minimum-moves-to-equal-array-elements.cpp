class Solution {
public:
    int minMoves(vector<int>& nums) {
        int s=0,m=INT_MAX;
        for(auto i:nums) {
            s+=i; m=min(m,i);
        }
        return s-m*nums.size();
    }
};