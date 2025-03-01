class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]==nums[i]) nums[i-1]*=2, nums[i]=0;
        }
        vector<int> a,b, res;
        for(auto i:nums) if(i) a.push_back(i); else b.push_back(i);
        for(auto i:a)res.push_back(i);
        for(auto i:b) res.push_back(0);
        return res;
    }
};