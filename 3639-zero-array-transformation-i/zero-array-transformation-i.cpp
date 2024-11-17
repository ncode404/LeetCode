class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> pre(nums.size(),0);
        for(auto i:queries) {
            pre[i[0]]++; 
            if(i[1]+1<nums.size()) pre[i[1]+1]--;
        }
        for(int i=1;i<nums.size();i++) {
            pre[i]+=pre[i-1];
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i]-pre[i]>0)  return 0;
        }
        return 1;
    }
};