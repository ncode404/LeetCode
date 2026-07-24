class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int> m,res;
        for(int i=0;i<nums.size();i++) {
            for(int j=i;j<nums.size();j++) m[nums[i]^nums[j]];
        }
        for(int i=0;i<nums.size();i++) {
            for(auto j:m) res[j.first^nums[i]]++;
        }
        return res.size();
    }
};