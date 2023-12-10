class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res=0, j=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
            while(m[nums[i]]>k) {
                m[nums[j]]--; j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};